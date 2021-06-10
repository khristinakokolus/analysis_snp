import tarfile
import time
import requests


def read_data(archive_name: str) -> str:
    """
    Reads archive from I-TASSER and gets the needed model

    :param archive_name: name of the archive with the data from I_TASSER.
    :return: best predicted model from I_TASSER.
    """
    tar = tarfile.open(archive_name)
    tar.extractall("data/")
    tar.close()

    file_path = archive_name.split("tar")[0]
    model_file = file_path[:len(file_path) - 1] + "/" + "model1.pdb"
    file = open(model_file, "r")
    content = file.read()

    name = file_path.split("/")
    new_file = open(name[-1] + "_model.pdb", "w")
    new_file.write(content)
    new_file.close()
    return name[-1] + "_model.pdb"


def get_data(first_model: str, second_model: str) -> str:
    """
    Sends http request to the IPBA website and gets the information about the proteins models alignment.

    :param first_model: the name of the file with the first model to align.
    :param second_model: the name of the file with the second model to align.
    :return: text of the requested url with the alignment information.
    """
    # creating request to get the information about the alignment of the two protein models
    req = generate_request(first_model, second_model)
    req = req.prepare()
    s = requests.Session()
    resp = s.send(req)
    response_results = resp.text.split()
    result_url = response_results[response_results.index("results:") + 2]
    time.sleep(20)
    requested_data = requests.get(result_url)
    return requested_data.text


def generate_request(first_filename: str, second_filename: str) -> requests.Request:
    """
    Generates http request to the IPBA website.

    :param first_filename: the name of the first file to send to the website.
    :param second_filename: the name of the second file to send to the website.
    :return:
    """
    with open(first_filename, 'rb') as file1, open(second_filename, 'rb') as file2:
        boundary = "----WebKitFormBoundarytKR9cLsozlaHcPPb"
        content = f"""--{boundary}
Content-Disposition: form-data; name="pdbid1"

2AAK
--{boundary}
Content-Disposition: form-data; name="chainid1"

A
--{boundary}
Content-Disposition: form-data; name="file_pdb_1"; filename="{first_filename}"
Content-Type: application/x-aportisdoc

""".replace('\n', '\r\n') + file1.read().decode('utf-8') + f"""
--{boundary}
Content-Disposition: form-data; name="chainid1_2"


--{boundary}
Content-Disposition: form-data; name="pdbid2"

2VRR
--{boundary}
Content-Disposition: form-data; name="chainid2"

A
--{boundary}
Content-Disposition: form-data; name="file_pdb_2"; filename="{second_filename}"
Content-Type: application/x-aportisdoc

""".replace('\n', '\r\n') + file2.read().decode('utf-8') + f"""
--{boundary}
Content-Disposition: form-data; name="chainid2_2"


--{boundary}
Content-Disposition: form-data; name="ali"

global
--{boundary}--""".replace('\n', '\r\n')
        request = requests.Request('POST', 'https://www.dsimb.inserm.fr/dsimb_tools/ipba/cgi-bin/ipba.pl',
                                   {
                                       'Content-Type':
                                           'multipart/form-data; boundary=----WebKitFormBoundarytKR9cLsozlaHcPPb',
                                       'Content-length': f'{len(content)}'})

        request.data = content
        return request


def process_results(requested_data: str) -> tuple:
    # getting aligned models images urls
    data_for_images = requested_data.split("\"")
    images_urls = []
    for i in range(4):
        img_indx = data_for_images.index(">\n\t\t\t<img src=")
        images_urls.append(data_for_images[img_indx + 1])
        data_for_images.remove(data_for_images[img_indx])

    # extracting data for finding main alignment information
    updated_requested_data = requested_data.replace("<", ">")
    alignment_data = updated_requested_data.split(">")

    # getting rmsd score, alignment score, fraction aligned information
    normalized_score = alignment_data[alignment_data.index("Normalized score") + 4]
    rmsd_score = alignment_data[alignment_data.index("RMSD ") + 4]
    alignment_length = alignment_data[alignment_data.index("Alignment length") + 4]
    aligned_residues = alignment_data[alignment_data.index("Aligned residues") + 4]
    fraction_aligned = alignment_data[alignment_data.index("Fraction aligned") + 4]
    gdt_ts = alignment_data[alignment_data.index("GDT TS") + 4]

    protein_alignment_information = [normalized_score, rmsd_score, alignment_length,
                                     aligned_residues, fraction_aligned, gdt_ts]
    return protein_alignment_information, images_urls


def write_text_results(alignment_information) -> None:
    file_path = "results/alignment_information/alignment_results.txt"
    file = open(file_path, "a")
    alignment_terms = ["Normalized score", "RMSD\t\t\t", "Alignment length",
                       "Aligned residues", "Fraction aligned", "GDT TS\t\t\t"]
    terms_amount = len(alignment_terms)
    file.write("\t\t\tALIGNMENT INFORMATION\n")
    for i in range(terms_amount):
        file.write(alignment_terms[i] + "\t" + str(alignment_information[i]) + "\n")
    file.close()


def write_images_results(images_urls: list) -> None:
    file_path = "results/aligned_models/aligned_model1_model2"
    urls_amount = len(images_urls)
    for i in range(urls_amount):
        response = requests.get(images_urls[i])
        file = open(file_path + "_" + str(i) + ".png", "wb")
        file.write(response.content)
        file.close()

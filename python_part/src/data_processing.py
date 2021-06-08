import tarfile
import time
import requests


def read_data(archive_name):
    """
    Reads archive from I-TASSER and gets the needed model

    :param archive_name: name of the archive with the data from I_TASSER.
    :return: best predicted model from I_TASSER.
    """
    tar = tarfile.open("../data/" + archive_name, "r:bz2")
    file_folder = archive_name.split(".")[0]
    model_file = tar.extractfile(file_folder + "/model1.pdb")
    tar.close()
    return model_file


# def get_data(): #first_model, second_model):
#
#     files = {'file_pdb_1': open("model1.pdb", 'rb'), 'file_pdb_2': open("model2.pdb", 'rb')}
#     data = {"submit": "Align"}
#     r = requests.post("https://www.dsimb.inserm.fr/dsimb_tools/ipba",
#                       files=files, data=data, allow_redirects=True)
#
#     if r.history:
#         print("Request was redirected")
#         for resp in r.history:
#             print(resp.status_code, resp.url)
#         print("Final destination:")
#         print(r.status_code, r.url)
#     else:
#         print("Request was not redirected")

def get_data():
    req = generate_request('model1.pdb', 'model2.pdb')
    req = req.prepare()
    print(req.headers)
    s = requests.Session()
    resp = s.send(req)
    print(resp.status_code)
    print(resp)
    print(resp.text)
    # r1 = s.get("https://www.dsimb.inserm.fr/dsimb_tools/ipba")
    # files = {'file_pdb_1': open("model1.pdb", 'rb'), 'file_pdb_2': open("model2.pdb", 'rb')}
    # data = {"submit": "Align"} + files
    # r = s.post("https://www.dsimb.inserm.fr/dsimb_tools/ipba/cgi-bin/ipba.pl",
    #             data=files, allow_redirects=True)


# POST /dsimb_tools/ipba/cgi-bin/ipba.pl HTTP/1.1
# Host: www.dsimb.inserm.fr
# Content-Length: 595574
# User-Agent: python/1.1
# Content-Type: multipart/form-data; boundary=----WebKitFormBoundarytKR9cLsozlaHcPPb
# Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9
# Accept-Encoding: gzip, deflate
# Connection: close
#
# ------WebKitFormBoundarytKR9cLsozlaHcPPb
# Content-Disposition: form-data; name="pdbid1"
#
# 2AAK
# ------WebKitFormBoundarytKR9cLsozlaHcPPb
# Content-Disposition: form-data; name="chainid1"
#
# A
# ------WebKitFormBoundarytKR9cLsozlaHcPPb
# Content-Disposition: form-data; name="file_pdb_1"; filename="model1.pdb"
# Content-Type: application/x-aportisdoc


def generate_request(filename1: str, filename2: str) -> requests.Request:
    with open(filename1, 'rb') as file1, open(filename2, 'rb') as file2:
        boundary = "----WebKitFormBoundarytKR9cLsozlaHcPPb"
        content = f"""------WebKitFormBoundarytKR9cLsozlaHcPPb
Content-Disposition: form-data; name="pdbid1"

2AAK
------WebKitFormBoundarytKR9cLsozlaHcPPb
Content-Disposition: form-data; name="chainid1"

A
------WebKitFormBoundarytKR9cLsozlaHcPPb
Content-Disposition: form-data; name="file_pdb_1"; filename="{filename1}"
Content-Type: application/x-aportisdoc

""".replace('\n', '\r\n') + file1.read().decode('utf-8') + f"""
------WebKitFormBoundarytKR9cLsozlaHcPPb
Content-Disposition: form-data; name="chainid1_2"


------WebKitFormBoundarytKR9cLsozlaHcPPb
Content-Disposition: form-data; name="pdbid2"

2VRR
------WebKitFormBoundarytKR9cLsozlaHcPPb
Content-Disposition: form-data; name="chainid2"

A
------WebKitFormBoundarytKR9cLsozlaHcPPb
Content-Disposition: form-data; name="file_pdb_2"; filename="{filename2}"
Content-Type: application/x-aportisdoc

""".replace('\n', '\r\n') + file2.read().decode('utf-8') + f"""
------WebKitFormBoundarytKR9cLsozlaHcPPb
Content-Disposition: form-data; name="chainid2_2"


------WebKitFormBoundarytKR9cLsozlaHcPPb
Content-Disposition: form-data; name="ali"

global
------WebKitFormBoundarytKR9cLsozlaHcPPb--""".replace('\n', '\r\n')
        request = requests.Request('POST', 'https://www.dsimb.inserm.fr/dsimb_tools/ipba/cgi-bin/ipba.pl',
                                   {
                                    'Content-Type': 'multipart/form-data; boundary=----WebKitFormBoundarytKR9cLsozlaHcPPb',
                                    'Content-length': f'{len(content)}'})

        request.data = content
        return request

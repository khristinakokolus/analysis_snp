import tarfile
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


def get_data(first_model, second_model):
    files = {"file": open("model1.pdb")}
    gotten_information = requests.post("https://www.dsimb.inserm.fr/dsimb_tools/ipba/", files=files)
    print(gotten_information.text)


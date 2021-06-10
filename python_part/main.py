import sys
from src.data_processing import read_data, get_data, process_results,\
    write_text_results, write_images_results


def main(first_archive, second_archive):
    """
    Performs the main steps of the program.

    :return:
    """
    first_model = read_data(first_archive)
    second_model = read_data(second_archive)
    url_result = get_data(first_model, second_model)
    alignment_text_results, images_urls = process_results(url_result)
    write_text_results(alignment_text_results)
    write_images_results(images_urls)


if __name__ == '__main__':
    first_archive = "data/S611234_results.tar.bz2"
    second_archive = "data/S610689_results.tar.bz2"
    main(first_archive, second_archive)
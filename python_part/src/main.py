import sys
from src.data_processing import read_data, get_data, process_results,\
    write_text_results, write_images_results


def main():
    """
    Performs the main steps of the program.

    :return:
    """
    first_model = read_data("../data/S609367_results.tar.bz2")
    second_model = read_data("../data/S609367_results.tar.bz2")
    url_result = get_data(first_model, second_model)
    alignment_text_results, images_urls = process_results(url_result)
    write_text_results(alignment_text_results)
    write_images_results(images_urls)


if __name__ == '__main__':
    # first_archive = sys.argv[1]
    # second_archive = sys.argv[2]
    main()
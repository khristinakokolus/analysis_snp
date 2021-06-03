import sys
from src.data_processing import read_data, get_data


def main():
    first_archive = "S609367_results.tar.bz2"
    second_archive = "S611234_results.tar.bz2"

    first_model = read_data(first_archive)
    second_model = read_data(second_archive)

    get_data(first_model, second_model)


if __name__ == '__main__':
    # first_archive = sys.argv[1]
    # second_archive = sys.argv[2]
    main()
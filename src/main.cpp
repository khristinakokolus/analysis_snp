#include <iostream>
#include <vector>
#include "../inc/sequence_processing.h"
#include "../inc/energy.h"
#include "../inc/reading_conf.h"


// TODO: перевірити чи виконується на СOMT, якщо вийде
// тобто як приклад показати в презентації як працює програма

int main(int argc, char *argv[]) {
    const char *filename;

    if (argc == 2)
        filename = argv[1];
    if (argc > 2) {
        std::cerr << "Too many arguments. Usage: \n"
                     "<program>\n"
                     "or\n"
                     "<program> <config-filename>\n" << std::endl;
        return 1;
    } else {
        filename = "config.dat";
    }

    rna_configuration conf{};
    try {
        conf = rna_configuration::parse_config(filename);
    } catch (std::exception &ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 2;
    }

    // example of input data to check sequence processing functions
<<<<<<< Updated upstream
//    std::string rna_sequence = "gcagacggcgctgagcgcggcggcggcgggagcggcgtcgagtgtctccgtgcgcccgtctgtggccaagcagccagcagcctagcagccagtcagcttgccgccggcggccaagcagccaaccatgctcaacttcggtgcctctctccagcagactgcggaggaaagaatggaaatgatttctgaaaggccaaaagagagtatgtattcctggaacaaaactgcagagaaaagtgattttgaagctgtagaagcacttatgtcaatgagctgcagttggaagtctgattttaagaaatacgttgaaaacagacctgttacaccagtatctgatttgtcagaggaagagaatctgcttccgggaacacctgattttcatacaatcccagcattttgtttgactccaccttacagtccttctgactttgaaccctctcaagtgtcaaatctgatggcaccagcgccatctactgtacacttcaagtcactctcagatactgccaaacctcacattgccgcacctttcaaagaggaagaaaagagcccagtatctgcccccaaactccccaaagctcaggcaacaagtgtgattcgtcatacagctgatgcccagctatgtaaccaccagacctgcccaatgaaagcagccagcatcctcaactatcagaacaattcttttagaagaagaacccacctaaatgttgaggctgcaagaaagaacataccatgtgccgctgtgtcaccaaacagatccaaatgtgagagaaacacagtggcagatgttgatgagaaagcaagtgctgcactttatgacttttctgtgccttcctcagagacggtcatctgcaggtctcagccagcccctgtgtccccacaacagaagtcagtgttggtctctccacctgcagtatctgcagggggagtgccacctatgccggtcatctgccagatggttccccttcctgccaacaaccctgttgtgacaacagtcgttcccagcactcctcccagccagccaccagccgtttgcccccctgttgtgttcatgggcacacaagtccccaaaggcgctgtcatgtttgtggtaccccagcccgttgtgcagagttcaaagcctccggtggtgagcccgaatggcaccagactctctcccattgcccctgctcctgggttttccccttcagcagcaaaagtcactcctcagattgattcatcaaggataaggagtcacatctgtagccacccaggatgtggcaagacatactttaaaagttcccatctgaaggcccacacgaggacgcacacaggagaaaagcctttcagctgtagctggaaaggttgtgaaaggaggtttgcccgttctgatgaactgtccagacacaggcgaacccacacgggtgagaagaaatttgcgtgccccatgtgtgaccggcggttcatgaggagtgaccatttgaccaagcatgcccggcgccatctatcagccaagaagctaccaaactggcagatggaagtgagcaagctaaatgacattgctctacctccaacccctgctcccacacagtgacagaccggaaagtgaagagtcagaactaactttggtctcagcgggagccagtggtgatgtaaaaatgcttccactgcaagtctgtggccccacaacgtgggcttaaagcagaagccccacagcctggcacgaaggccccgcctgggttaggtgactaaaagggcttcggccacaggcaggtcacagaaaggcaggtttcatttcttatcacataagagagatgagaaagcttttattcctttgaatattttttgaaggtttcagatgaggtcaacacaggtagcacagattttgaatctgtgtgcatatttgttactttacttttgctgtttatacttgagaccaacttttcaatgtgattcttctaaagcactggtttcaagaatatggaggctggaaggaaataaacattacggtacagacatggagatgtaaaatgagtttgtattattacaaatattgtcatctttttctagagttatcttctttattattcctagtctttccagtcaacatcgtggatgtagtgattaaatatatctagaactatcatttttacactattgtgaatatttggaattgaacgactgtatattgctaagagggcccaaagaattggaatcctccttaatttaattgctttgaagcatagctacaatttgtttttgcatttttgttttgaaagtttaacaaatgactgtatctaggcatttcattatgctttgaactttagtttgcctgcagtttcttgtgtagatttgaaaattgtataccaatgtgttttctgtagactctaagatacactgcactttgtttagaaaaaaaactgaagatgaaatatatattgtaaagaagggatattaagaatcttagataacttcttgaaaaagatggcttatgtcatcagtaaagtacctttatgttatgaggatataatgtgtgctttattgaattagaaaattagtgaccattattcacaggtggacaaatgttgatgttgtcctgttaatttataggcgttttttggggatgtggaggtagttgggtagaaaaattattagaacattcacttttgttaacagtatttctcttttattctgttatatagtggatgatatacacagtggcaaaacaaaagtacattgcttaaaatatatagtgaaaaatgtcactatatcttcccatttaacattgtttttgtatattgggtgtagatttctgacatcaaaacttggacccttggaaaacaaaagttttaattaaaaaaaatccttgtgacttacaatttgcacaatatttcttttgttgtactttatatcttgtttacaataaagaattccctttggta";
//    int mutation_amount = 2;
//    std::vector<std::string>subsequences_to_change{"threonine", "threonine"};
//    std::vector<int> mutation_places{158, 203};
=======
    std::string rna_sequence = "gcagacggcgctgagcgcggcggcggcgggagcggcgtcgagtgtctccgtgcgcccgtctgtggccaagcagccagcagcctagcagccagtcagcttgccgccggcggccaagcagccaaccatgctcaacttcggtgcctctctccagcagactgcggaggaaagaatggaaatgatttctgaaaggccaaaagagagtatgtattcctggaacaaaactgcagagaaaagtgattttgaagctgtagaagcacttatgtcaatgagctgcagttggaagtctgattttaagaaatacgttgaaaacagacctgttacaccagtatctgatttgtcagaggaagagaatctgcttccgggaacacctgattttcatacaatcccagcattttgtttgactccaccttacagtccttctgactttgaaccctctcaagtgtcaaatctgatggcaccagcgccatctactgtacacttcaagtcactctcagatactgccaaacctcacattgccgcacctttcaaagaggaagaaaagagcccagtatctgcccccaaactccccaaagctcaggcaacaagtgtgattcgtcatacagctgatgcccagctatgtaaccaccagacctgcccaatgaaagcagccagcatcctcaactatcagaacaattcttttagaagaagaacccacctaaatgttgaggctgcaagaaagaacataccatgtgccgctgtgtcaccaaacagatccaaatgtgagagaaacacagtggcagatgttgatgagaaagcaagtgctgcactttatgacttttctgtgccttcctcagagacggtcatctgcaggtctcagccagcccctgtgtccccacaacagaagtcagtgttggtctctccacctgcagtatctgcagggggagtgccacctatgccggtcatctgccagatggttccccttcctgccaacaaccctgttgtgacaacagtcgttcccagcactcctcccagccagccaccagccgtttgcccccctgttgtgttcatgggcacacaagtccccaaaggcgctgtcatgtttgtggtaccccagcccgttgtgcagagttcaaagcctccggtggtgagcccgaatggcaccagactctctcccattgcccctgctcctgggttttccccttcagcagcaaaagtcactcctcagattgattcatcaaggataaggagtcacatctgtagccacccaggatgtggcaagacatactttaaaagttcccatctgaaggcccacacgaggacgcacacaggagaaaagcctttcagctgtagctggaaaggttgtgaaaggaggtttgcccgttctgatgaactgtccagacacaggcgaacccacacgggtgagaagaaatttgcgtgccccatgtgtgaccggcggttcatgaggagtgaccatttgaccaagcatgcccggcgccatctatcagccaagaagctaccaaactggcagatggaagtgagcaagctaaatgacattgctctacctccaacccctgctcccacacagtgacagaccggaaagtgaagagtcagaactaactttggtctcagcgggagccagtggtgatgtaaaaatgcttccactgcaagtctgtggccccacaacgtgggcttaaagcagaagccccacagcctggcacgaaggccccgcctgggttaggtgactaaaagggcttcggccacaggcaggtcacagaaaggcaggtttcatttcttatcacataagagagatgagaaagcttttattcctttgaatattttttgaaggtttcagatgaggtcaacacaggtagcacagattttgaatctgtgtgcatatttgttactttacttttgctgtttatacttgagaccaacttttcaatgtgattcttctaaagcactggtttcaagaatatggaggctggaaggaaataaacattacggtacagacatggagatgtaaaatgagtttgtattattacaaatattgtcatctttttctagagttatcttctttattattcctagtctttccagtcaacatcgtggatgtagtgattaaatatatctagaactatcatttttacactattgtgaatatttggaattgaacgactgtatattgctaagagggcccaaagaattggaatcctccttaatttaattgctttgaagcatagctacaatttgtttttgcatttttgttttgaaagtttaacaaatgactgtatctaggcatttcattatgctttgaactttagtttgcctgcagtttcttgtgtagatttgaaaattgtataccaatgtgttttctgtagactctaagatacactgcactttgtttagaaaaaaaactgaagatgaaatatatattgtaaagaagggatattaagaatcttagataacttcttgaaaaagatggcttatgtcatcagtaaagtacctttatgttatgaggatataatgtgtgctttattgaattagaaaattagtgaccattattcacaggtggacaaatgttgatgttgtcctgttaatttataggcgttttttggggatgtggaggtagttgggtagaaaaattattagaacattcacttttgttaacagtatttctcttttattctgttatatagtggatgatatacacagtggcaaaacaaaagtacattgcttaaaatatatagtgaaaaatgtcactatatcttcccatttaacattgtttttgtatattgggtgtagatttctgacatcaaaacttggacccttggaaaacaaaagttttaattaaaaaaaatccttgtgacttacaatttgcacaatatttcttttgttgtactttatatcttgtttacaataaagaattccctttggta";
    int mutation_amount = 1;
    std::vector<std::string>subsequences_to_change{"threonine"};
    std::vector<int> mutation_places{203};
>>>>>>> Stashed changes

    std::string rna_sequence = conf.rna_sequence_initial;
    std::string rna_sequence_to_mutate = conf.rna_sequence_to_mutate;
    int mutation_amount = conf.mutation_amount;
    std::vector<std::string> subsequences_to_change = conf.amino_acids;
    std::vector<int> mutation_places = conf.mutation_places;

    // apply sequence processing functions
    std::vector<std::string> nucleotide_sequences = find_all_amino_acids(conf);
    conf.amino_acids = nucleotide_sequences;
    apply_mutations(conf);

    // counting energy difference
    double energy_diff = count_difference(conf);
    bool pos_control = positive_control(energy_diff);


    // determination whether it is a positive control or not
    if (pos_control) {
        std::cout << "Positive control was detected" << std::endl;
    } else {
        std::cout << "Positive control was not detected" << std::endl;
    }


    //plot graph due to the result of the positive control

    return 0;
}

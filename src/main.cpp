#include <iostream>
#include <vector>
#include "../inc/sequence_processing.h"
#include "../inc/energy.h"
#include "../inc/reading_conf.h"


// TODO: перевірити чи виконується на СOMT, якщо вийде
// тобто як приклад показати в презентації як працює програма

int main(int argc, char *argv[]) {
    rna_configuration rna_config;

    // example of input data to check sequence processing functions
    std::string rna_sequence = "gcagacggcgctgagcgcggcggcggcgggagcggcgtcgagtgtctccgtgcgcccgtctgtggccaagcagccagcagcctagcagccagtcagcttgccgccggcggccaagcagccaaccatgctcaacttcggtgcctctctccagcagactgcggaggaaagaatggaaatgatttctgaaaggccaaaagagagtatgtattcctggaacaaaactgcagagaaaagtgattttgaagctgtagaagcacttatgtcaatgagctgcagttggaagtctgattttaagaaatacgttgaaaacagacctgttacaccagtatctgatttgtcagaggaagagaatctgcttccgggaacacctgattttcatacaatcccagcattttgtttgactccaccttacagtccttctgactttgaaccctctcaagtgtcaaatctgatggcaccagcgccatctactgtacacttcaagtcactctcagatactgccaaacctcacattgccgcacctttcaaagaggaagaaaagagcccagtatctgcccccaaactccccaaagctcaggcaacaagtgtgattcgtcatacagctgatgcccagctatgtaaccaccagacctgcccaatgaaagcagccagcatcctcaactatcagaacaattcttttagaagaagaacccacctaaatgttgaggctgcaagaaagaacataccatgtgccgctgtgtcaccaaacagatccaaatgtgagagaaacacagtggcagatgttgatgagaaagcaagtgctgcactttatgacttttctgtgccttcctcagagacggtcatctgcaggtctcagccagcccctgtgtccccacaacagaagtcagtgttggtctctccacctgcagtatctgcagggggagtgccacctatgccggtcatctgccagatggttccccttcctgccaacaaccctgttgtgacaacagtcgttcccagcactcctcccagccagccaccagccgtttgcccccctgttgtgttcatgggcacacaagtccccaaaggcgctgtcatgtttgtggtaccccagcccgttgtgcagagttcaaagcctccggtggtgagcccgaatggcaccagactctctcccattgcccctgctcctgggttttccccttcagcagcaaaagtcactcctcagattgattcatcaaggataaggagtcacatctgtagccacccaggatgtggcaagacatactttaaaagttcccatctgaaggcccacacgaggacgcacacaggagaaaagcctttcagctgtagctggaaaggttgtgaaaggaggtttgcccgttctgatgaactgtccagacacaggcgaacccacacgggtgagaagaaatttgcgtgccccatgtgtgaccggcggttcatgaggagtgaccatttgaccaagcatgcccggcgccatctatcagccaagaagctaccaaactggcagatggaagtgagcaagctaaatgacattgctctacctccaacccctgctcccacacagtgacagaccggaaagtgaagagtcagaactaactttggtctcagcgggagccagtggtgatgtaaaaatgcttccactgcaagtctgtggccccacaacgtgggcttaaagcagaagccccacagcctggcacgaaggccccgcctgggttaggtgactaaaagggcttcggccacaggcaggtcacagaaaggcaggtttcatttcttatcacataagagagatgagaaagcttttattcctttgaatattttttgaaggtttcagatgaggtcaacacaggtagcacagattttgaatctgtgtgcatatttgttactttacttttgctgtttatacttgagaccaacttttcaatgtgattcttctaaagcactggtttcaagaatatggaggctggaaggaaataaacattacggtacagacatggagatgtaaaatgagtttgtattattacaaatattgtcatctttttctagagttatcttctttattattcctagtctttccagtcaacatcgtggatgtagtgattaaatatatctagaactatcatttttacactattgtgaatatttggaattgaacgactgtatattgctaagagggcccaaagaattggaatcctccttaatttaattgctttgaagcatagctacaatttgtttttgcatttttgttttgaaagtttaacaaatgactgtatctaggcatttcattatgctttgaactttagtttgcctgcagtttcttgtgtagatttgaaaattgtataccaatgtgttttctgtagactctaagatacactgcactttgtttagaaaaaaaactgaagatgaaatatatattgtaaagaagggatattaagaatcttagataacttcttgaaaaagatggcttatgtcatcagtaaagtacctttatgttatgaggatataatgtgtgctttattgaattagaaaattagtgaccattattcacaggtggacaaatgttgatgttgtcctgttaatttataggcgttttttggggatgtggaggtagttgggtagaaaaattattagaacattcacttttgttaacagtatttctcttttattctgttatatagtggatgatatacacagtggcaaaacaaaagtacattgcttaaaatatatagtgaaaaatgtcactatatcttcccatttaacattgtttttgtatattgggtgtagatttctgacatcaaaacttggacccttggaaaacaaaagttttaattaaaaaaaatccttgtgacttacaatttgcacaatatttcttttgttgtactttatatcttgtttacaataaagaattccctttggta";
    int mutation_amount = 2;
    std::vector<std::string>subsequences_to_change{"threonine", "threonine"};
    std::vector<int> mutation_places{158, 203};

    rna_config.rna_sequence_initial = rna_sequence;
    rna_config.rna_sequence_to_mutate = rna_sequence;
    rna_config.mutation_amount = mutation_amount;
    rna_config.amino_acids = subsequences_to_change;
    rna_config.mutation_places = mutation_places;

    // apply sequence processing functions
    std::vector<std::string> nucleotide_sequences = find_all_amino_acids(rna_config);
    rna_config.amino_acids = nucleotide_sequences;
    apply_mutations(rna_config);
    


    // counting energy difference
    double energy_diff = count_difference(rna_config);
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

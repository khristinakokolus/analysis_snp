#include <iostream>

std::string amino_acid_replacement(std::string &rna_sequence, std::string &amino_acid, int mutation_place) {
    rna_sequence.replace(mutation_place, 3, amino_acid);
    return rna_sequence;
}

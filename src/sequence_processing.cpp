#include <iostream>
#include <vector>
#include "../inc/all_amino_acids.h"
#include "../inc/reading_conf.h"

// checks whether one symbol differs in the sequences of nucleotides
bool one_symbol_diff(std::string& initial_combination, std::string mutated_combination) {
    int counter = 0;
    for(int i = 0; i < initial_combination.size(); i++) {
        if (initial_combination[i] != mutated_combination[i]) {
            counter++;
        }
    }
    if (counter == 1) {
        return true;
    } else {
        return false;
    }
}

// finding needed nucleotide sequence for the mutations from its name
std::string find_needed_amino_acid(std::string& rna_sequence, std::string& amino_acid, const int mutation_place) {
    std::vector<std::string> different_codons = amino_acids_combinations.at(amino_acid);
    std::string nucleotides_combination;
    for (int i = 0; i < different_codons.size(); i++) {
        nucleotides_combination = rna_sequence.substr(mutation_place - 1, 3);
        if(one_symbol_diff(nucleotides_combination, different_codons[i])) {
            return different_codons[i];
        }
    }
    return "none";
}


// finding all such sequences using previous function
std::vector<std::string> find_all_amino_acids(rna_configuration& rna_config) {
    std::vector<std::string> codons_to_mutate;
    std::string amino_acid;
    for (int i = 0; i < rna_config.mutation_amount; i++) {
        amino_acid = find_needed_amino_acid(rna_config.rna_sequence_to_mutate,
                                            rna_config.amino_acids[i],
                                            rna_config.mutation_places[i]);
        codons_to_mutate.push_back(amino_acid);
    }
    return codons_to_mutate;
}


// mutation performance
void amino_acid_replacement(std::string& rna_sequence, std::string& amino_acid, int mutation_place) {
    rna_sequence.replace(mutation_place - 1, 3, amino_acid);
}


// application of all needed mutations for the RNA
void apply_mutations(rna_configuration& rna_config ) {
    for (int i = 0; i < rna_config.mutation_amount; i++) {
        amino_acid_replacement(rna_config.rna_sequence_to_mutate,
                               rna_config.amino_acids[i],
                               rna_config.mutation_places[i]);
    }
}

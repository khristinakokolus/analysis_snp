#include <iostream>
#include <vector>
#include "../inc/reading_conf.h"
#ifndef ANALYSIS_SNP_SEQUENCE_PROCESSING_H
#define ANALYSIS_SNP_SEQUENCE_PROCESSING_H

bool one_symbol_diff(std::string& initial_combination, std::string mutated_combination);
std::string find_needed_amino_acid(std::string& rna_sequence, std::string& amino_acid, const int mutation_place);
std::vector<std::string> find_all_amino_acids(rna_configuration& rna_config);
void amino_acid_replacement(std::string &rna_sequence, std::string &amino_acid, int mutation_place);
void apply_mutations(rna_configuration& rna_config);

#endif //ANALYSIS_SNP_SEQUENCE_PROCESSING_H

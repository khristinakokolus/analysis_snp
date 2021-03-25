#include <iostream>
#include <vector>
#ifndef ANALYSIS_SNP_SEQUENCE_PROCESSING_H
#define ANALYSIS_SNP_SEQUENCE_PROCESSING_H

bool one_symbol_diff(std::string& initial_combination, std::string mutated_combination);
int find_needed_amino_acid(std::string& rna_sequence, std::string& amino_acid, const int mutation_place);
std::vector<std::string> find_all_amino_acids(const int mutations_amount,
                                              std::string& rna_sequence,
                                              std::vector<std::string>& amino_acids,
                                              std::vector <int> mutation_places);
void amino_acid_replacement(std::string &rna_sequence, std::string &amino_acid, int mutation_place);
void apply_mutations(const int mutations_amount, std::string& rna_sequence,
                     std::vector<std::string>& amino_acids, std::vector<int> mutation_places );
#endif //ANALYSIS_SNP_SEQUENCE_PROCESSING_H

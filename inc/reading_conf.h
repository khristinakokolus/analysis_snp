#include <iostream>
#include <vector>
#ifndef ANALYSIS_SNP_READING_CONF_H
#define ANALYSIS_SNP_READING_CONF_H

struct rna_configuration{
    std::string rna_sequence_initial;
    std::string rna_sequence_to_mutate;
    int mutation_amount;
    std::vector<std::string> amino_acids;
    std::vector<int> mutation_places;
};

#endif //ANALYSIS_SNP_READING_CONF_H

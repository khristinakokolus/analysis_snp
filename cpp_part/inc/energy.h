#ifndef ANALYSIS_SNP_ENERGY_COUNT_H
#define ANALYSIS_SNP_ENERGY_COUNT_H

#include <iostream>
std::string energy_search(std::string content);
std::string get_output(const std::string& cmd);
double count_energy(std::string& rna_sequence);
double count_difference(rna_configuration& rna_config);
bool positive_control(const double difference);

#endif //ANALYSIS_SNP_ENERGY_COUNT_H

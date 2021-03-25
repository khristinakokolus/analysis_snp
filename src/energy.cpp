#include <iostream>
#include "../inc/reading_conf.h"


// count energy using function RNAfold from  ViennaRNA package
double count_energy(std::string& rna_sequence) {

    return 0;
}

// count the difference between the energies released by initial RNA sequence and mutated RNA sequence
double count_difference(rna_configuration& rna_config) {
    double initial_energy = count_energy(rna_config.rna_sequence_initial);
    double mutated_energy = count_energy(rna_config.rna_sequence_initial);
    double difference = abs(initial_energy - mutated_energy);
    return difference;
}

//check for the positive control
bool positive_control(const double difference) {
    const int minimal_difference = 20; // for example
    if (difference >= minimal_difference) {
        return true;
    }
    return false;
}

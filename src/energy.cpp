#include <iostream>

double count_energy(std::string& rna_sequence) {

    return 0;
}

double count_difference(std::string& initial_sequence, std::string& mutated_sequence) {
    double initial_energy = count_energy(initial_sequence);
    double mutated_energy = count_energy(mutated_sequence);
    double difference = abs(initial_energy - mutated_energy);
    return difference;
}

bool positive_control(const double difference) {
    const int minimal_difference = 20;
    if (difference >= minimal_difference) {
        return true;
    }
    return false;
}

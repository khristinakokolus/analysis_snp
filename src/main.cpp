#include <iostream>
#include <vector>
#include "../inc/check_input.h"
#include "../inc/plot.h"
#include "../inc/sequence_processing.h"
#include "../inc/energy.h"


int main(int argc, char *argv[]) {
    std::string initial_sequence;
    std::string rna_sequence_to_mutate;
    std::vector<int> positions_to_mutate;
    std::vector<std::string> subsequences_to_change;
    int amount_of_mutations;
    double energy_difference;
    bool positive_control;

    // interactive or console input?
    // how better to get positions and subsequences
    // can be different variants of input - single and multiple mutations

    for (int i = 0; i < amount_of_mutations; i++) {
        amino_acid_replacement(rna_sequence_to_mutate, subsequences_to_change[i], positions_to_mutate[i]);
    }
    energy_difference = count_difference(initial_sequence, rna_sequence_to_mutate);
    positive_control = positive_control(energy_difference);

    if (positive_control) {
        std::cout << "Positive control was detected" << std::endl;
    } else {
        std::cout << "Positive control was not detected" << std::endl;
    }

    //plot needed graph

    return 0;
}

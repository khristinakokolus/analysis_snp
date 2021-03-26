#include <iostream>
#include "../inc/reading_conf.h"
#include <cstdio>
#include <memory>
#include <string>
#include <array>
#include <cstdlib>
#include <fstream>
#include <regex>

std::string energy_search(std::string content) {
    std::smatch match;
    std::regex expr("(-*)\\d+.\\d+");

    while (regex_search(content, match, expr)) {
        for (auto x : match){
            return x;
        }

        std::cout << std::endl;
        content = match.suffix().str();
    }
    return 0;

}

std::string get_output(const std::string& cmd) {
    std::array<char, 128> buffer{};
    std::string result;

    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe)
    {
        std::cerr << "Couldn't start command." << std::endl;
    }
    while (fgets(buffer.data(), 128, pipe) != nullptr) {

        result += buffer.data();
    }

    auto returnCode = pclose(pipe);

    return result;
}



// count energy using function RNAfold from  ViennaRNA package
double count_energy(std::string& rna_sequence) {

    std::ofstream seq("sequence.txt");
    seq << rna_sequence;
    seq.close();

    #ifdef _WIN32
    // need to be a full path to the executable file
    std::string res = get_output("D:\\UCU\\Second\\AKS\\project\\ViennaRNA\\RNAfold.exe sequence.txt");
    #endif

    #ifdef linux
    std::string res = get_output("RNAfold sequence.txt");
    #endif


    double energy = stod(energy_search(res));

    return energy;
}


// count the difference between the energies released by initial RNA sequence and mutated RNA sequence
double count_difference(rna_configuration& rna_config) {
    double initial_energy = count_energy(rna_config.rna_sequence_initial);
    std::cout << "Initial rna sequence free energy: " << initial_energy << std::endl;
    double mutated_energy = count_energy(rna_config.rna_sequence_to_mutate);
    std::cout << "Mutated rna sequence free energy: " << mutated_energy << std::endl;
    double difference = std::abs(initial_energy - mutated_energy);
    std::cout<<"Energy difference: "<<difference<<std::endl;
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

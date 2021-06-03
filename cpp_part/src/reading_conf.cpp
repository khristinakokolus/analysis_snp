#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "../inc/reading_conf.h"


rna_configuration rna_configuration::parse_config(const std::string &filename) {
    rna_configuration conf;
    std::ifstream cFile(filename);
    if (cFile.is_open()) {
        std::string line;
        while (getline(cFile, line)) {
            line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
            if (line[0] == '#' || line.empty()) continue;
            auto delimiterPos = line.find('=');
            auto name = line.substr(0, delimiterPos);
            auto value = line.substr(delimiterPos + 1);
            if (name == "RNAsequence") {
                conf.rna_sequence_initial = value;
                conf.rna_sequence_to_mutate = value;
            }
            else if (name == "mutationsAmount") {
                conf.mutation_amount = std::stoi(value);
            }
            else if (name == "subsequences") {
                char del = ',';
                std::stringstream sstream(value);
                std::string word;
                while (std::getline(sstream, word, ',')) {
                    conf.amino_acids.push_back(word);
                }
            }
            else if (name == "positions"){
                char del = ',';
                std::stringstream sstream(value);
                std::string word;
                while (std::getline(sstream, word, ',')){
                    conf.mutation_places.push_back(std::stoi(word));
                }
            }
            else {
                throw std::runtime_error("Parameter is not valid.\n");
            }
        }
    } else {
        throw std::runtime_error("Couldn't open config file for reading.\n");
    }
    return conf;
}
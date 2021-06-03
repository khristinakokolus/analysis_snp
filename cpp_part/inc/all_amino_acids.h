#include <iostream>
#include <map>
#include <vector>

#ifndef ANALYSIS_SNP_ALL_AMINO_ACIDS_H
#define ANALYSIS_SNP_ALL_AMINO_ACIDS_H

std::map<std::string, std::vector<std::string>> amino_acids_combinations = {
        {"alanine", {"gct", "gcc", "gca", "gcg"}},
        {"arginine", {"cgt", "cgc", "cga", "cgg"}},
        {"asparagine", {"aat", "aac"}},
        {"aspartic acid", {"gat", "gac"}},
        {"cysteine", {"tgt", "tgc"}},
        {"glutamine", {"caa", "cag"}},
        {"glutamic acid", {"gaa", "gag"}},
        {"glycine", {"ggt", "ggc", "gga", "ggg"}},
        {"histidine", {"cat", "cac"}},
        {"isoleucine", {"att", "atc", "ata"}},
        {"leucine", {"ctt", "ctc", "cta", "cug"}},
        {"lysine", {"aaa", "aag"}},
        {"methionine", {"atg"}},
        {"phenylalanine", {"ttt", "ttc"}},
        {"proline", {"cct", "ccc", "cca", "ccg"}},
        {"serine", {"agt", "agc"}},
        {"threonine", {"act", "acc", "aca", "acg"}},
        {"tryptophan", {"tgg"}},
        {"tyrosine", {"tat", "tac"}},
        {"valine", {"gtt", "gtc", "gta", "gtg"}},
};


#endif //ANALYSIS_SNP_ALL_AMINO_ACIDS_H

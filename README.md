# Analysis single nucleotide polymorphism

Welcome to the Analysis single nucleotide polymorphism project!

## Contributors
[Khrystyna Kokolus](https://github.com/khristinakokolus)

[Daryna Hnatenko](https://github.com/monberin)

[Zoryana Herman](https://github.com/zoriankaH)

## Description

The main idea of our project is to analyse the mutations of the given RNA sequence and compare 
minimum free energy of the initial RNA sequence and mutated one. This helps to understand how
the secondary structure of the protein can change due to changes in RNA sequences. In addition to this, 
it can have a different affect on the properties of the protein that changes.


## Prerequisites


If you want to work with this project you should firstly write in the command prompt:


```
git clone https://github.com/khristinakokolus/analysis_snp.git
```

 - **C++ compiler** - needs to support **C++17** standard
 - **CMake** 3.16+


## Usage

First of all to use the program you need to compile project using CMakeLists.txt.

To do this, use such commands

- the last command is to run the program:

```
 cd analysis_snp
 mkdir build 
 cd build
 cmake .. -G"Unix Makefiles"
 make
./analysis_snp ../files/config.dat 
```


## General project layout

---------------------------------FIRST STAGE-------------------------------------------

- investigated RNA using the sequence of KLF-10 
- checked that the structure did not change on the RNA level using different SNP 
- developed program that calculates the difference between free energies of initial RNA sequence and
mutated one
- also, program checks the presence of positive control to demonstrate the effectiveness of the analysis

## First presentation

[First presentation slides](https://docs.google.com/presentation/d/1_QqVUQ53NHF7gMcyIXJ_fm0A76vAPXjJRwrjR3mN050/edit#slide=id.g4dfce81f19_0_45)


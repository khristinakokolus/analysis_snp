# Analysis single nucleotide polymorphism

Welcome to the Analysis single nucleotide polymorphism project!

## Contributors
[Khrystyna Kokolus](https://github.com/khristinakokolus)

[Daryna Hnatenko](https://github.com/monberin)

[Zoryana Herman](https://github.com/zoriankaH)

## Description

The main idea of our project is to analyse protein KLF-10 and mutations of it to find how they can affect a person's health.

First of all, we analysed the mutations of its RNA sequence and compared
minimum free energy of the initial RNA sequence and mutated one using RNAfold tool from [ViennaRNA package](https://www.tbi.univie.ac.at/RNA/). This helps to understand how
the secondary structure of the protein can change due to changes in RNA sequences. In addition to this, it can have a different affect on the properties of the protein that changes.

Then we analysed the structure of the protein using modeling of it. We used PyMol program and [IPBA website](https://www.dsimb.inserm.fr/dsimb_tools/ipba/) for the investigation of the similrity of the mutated structures and initial ones. We worked with RMSD coefficient and other alignment characteristics.


## Prerequisites


If you want to work with this project you should firstly write in the command prompt:


```
git clone https://github.com/khristinakokolus/analysis_snp.git
```

 - **C++ compiler** - needs to support **C++17** standard
 - **CMake** 3.16+
 - **Python3**
 - **ViennaRNA library** from its [website](https://www.tbi.univie.ac.at/RNA/)


## Usage

### RNA part

First of all to use the program you need to compile project using CMakeLists.txt.

To do this, use such commands (the last command is to run the program):

```
 cd analysis_snp/rna_part
 mkdir build 
 cd build
 cmake .. -G"Unix Makefiles"
 make
./analysis_snp ../files/config.dat 
```

### Protein's alignment part

- You need to get the protein structures in pdb format using [I-TASSER server](https://zhanglab.dcmb.med.umich.edu/I-TASSER/)
- After getting the results from the server you need to download the archive, that you need to run the program
- For the program you need two such archives as it compares two structures.
- Then to run it you need:

```
 cd analysis_snp/proteins_alignment_part
 python3 main.py <path to the first archive with pdb model> <path to the second archive with pdb model>
```

- As a result you will get the images of the aligned structures. For example:

![](https://github.com/khristinakokolus/analysis_snp/blob/main/proteins_alignment_part/results/aligned_models/aligned_model1_model2_0.png)

And also you will get for example such text result:

ALIGNMENT INFORMATION

Normalized score	257.30

RMSD				1.43

Alignment length	578

Aligned residues	382

Fraction aligned	66.09 %

GDT TS				54.79


## Final presentation

[Final presentation slides](https://docs.google.com/presentation/d/1IRuM_YE0PGwldhNBjDSiaXo3K0y3PBIOh62zI05HZS4/edit?usp=sharing)


# OOP Lab Experiments (C++)

This folder contains 10 separate C++ programs matching the supplied OOP experiment list.

## Open in VS Code
1. Extract this ZIP file.
2. Open VS Code.
3. Select File -> Open Folder and choose `OOP_Lab_Experiments`.
4. Open an experiment's `main.cpp`.
5. Compile and run from that experiment folder.

## Compile commands
Most experiments (1, 2, 4, 6, 7, 8, 9, 10):
    g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o main
    ./main

Experiments 3 and 5 use C++11 and C++14 features respectively:
    g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o main
    g++ -std=c++14 -Wall -Wextra -pedantic main.cpp -o main

On Windows PowerShell, run:
    .\main.exe

Experiment 10 creates `students.csv` in its current working directory.

Note: Experiment 1 also relates to setting up the GitHub repository. The suggested commit message is included in its source file. Use meaningful commit messages when committing each experiment.

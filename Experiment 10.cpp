// Experiment 10: CSV file handling and file pointers (seekg, seekp, tellg, tellp)
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    double marks;
};

int main() {
    const string filename = "students.csv";

    // Write CSV records using ofstream
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Unable to open file for writing.\n";
        return 1;
    }

    outFile << "Roll,Name,Marks\n";
    outFile << "1,Asha,85.5\n";
    outFile << "2,Kabir,91.0\n";
    outFile << "3,Neha,78.0\n";

    cout << "Output position after writing: " << outFile.tellp() << '\n';
    outFile.close();

    // Read CSV records using ifstream
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Unable to open file for reading.\n";
        return 1;
    }

    cout << "\nFile contents:\n";
    string line;
    while (getline(inFile, line))
        cout << line << '\n';

    cout << "\nCurrent input position: " << inFile.tellg() << '\n';

    // Demonstrate seekg and tellg by returning to the beginning
    inFile.clear();       // Clear EOF state before seeking
    inFile.seekg(0, ios::beg);
    cout << "Position after seekg(0): " << inFile.tellg() << '\n';

    // Read and display the header
    getline(inFile, line);
    cout << "Header: " << line << '\n';
    inFile.close();

    // Demonstrate seekp and tellp by updating the file at its end
    fstream updateFile(filename, ios::in | ios::out);
    if (!updateFile) {
        cerr << "Unable to open file for updating.\n";
        return 1;
    }

    updateFile.seekp(0, ios::end);
    cout << "Output position before appending: " << updateFile.tellp() << '\n';
    updateFile << "4,Dev,88.5\n";
    cout << "Output position after appending: " << updateFile.tellp() << '\n';
    updateFile.close();

    cout << "\nUpdated CSV file created: " << filename << '\n';
    return 0;
}

// Run this program from its experiment folder so students.csv is created there.

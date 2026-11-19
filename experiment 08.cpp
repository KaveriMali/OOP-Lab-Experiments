// Experiment 8: STL containers and algorithms for student marks
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    double marks;
};

int main() {
    vector<Student> students = {
        {103, "Asha", 78.5},
        {101, "Kabir", 91.0},
        {104, "Neha", 84.0},
        {102, "Dev", 67.5}
    };

    // sort: arrange students by marks in descending order
    sort(students.begin(), students.end(),
         [](const Student& a, const Student& b) {
             return a.marks > b.marks;
         });

    cout << "Students sorted by marks:\n";
    for (const auto& student : students)
        cout << student.roll << " " << student.name << " " << student.marks << '\n';

    // find_if: find the first student with marks of at least 85
    auto found = find_if(students.begin(), students.end(),
                         [](const Student& s) { return s.marks >= 85.0; });

    if (found != students.end())
        cout << "\nFirst student with marks >= 85: " << found->name << '\n';

    // map: ordered mapping from roll number to student name
    map<int, string> nameByRoll;
    for (const auto& student : students)
        nameByRoll[student.roll] = student.name;

    cout << "\nNames stored in map:\n";
    for (const auto& entry : nameByRoll)
        cout << entry.first << " -> " << entry.second << '\n';

    // unordered_map: store marks by student name
    unordered_map<string, double> marksByName;
    for (const auto& student : students)
        marksByName[student.name] = student.marks;

    cout << "\nMarks stored in unordered_map:\n";
    for (const auto& entry : marksByName)
        cout << entry.first << " -> " << entry.second << '\n';

    // transform: create a vector containing marks increased by 5 bonus points
    vector<double> bonusMarks(students.size());
    transform(students.begin(), students.end(), bonusMarks.begin(),
              [](const Student& s) { return s.marks + 5.0; });

    cout << "\nMarks after adding 5 bonus points:\n";
    for (double mark : bonusMarks) cout << mark << ' ';
    cout << '\n';

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

int main() {
    float pi = 3.14;
    int age;
    float circleRadius;
    string name;
    bool isStudent = true;

    cout << "Enter Your Name: ";
    cin >> name;

    cout << "Enter Your Age: ";
    cin >> age;

    cout << "Enter a radius of circle: ";
    cin >> circleRadius;

    float circleArea = pi * circleRadius * circleRadius;
    int ageNextYear = age + 1;

    cout << "\nResult\n";
    cout << "Name: " << name << "\n";
    cout << "Age Next Year: " << ageNextYear << "\n";
    cout << "Area of circle: " << circleArea << "\n";

    if (isStudent) {
        cout << "Status: Active Student\n";
    }

    return 0;
}

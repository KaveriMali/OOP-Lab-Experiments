
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int* marks;

public:
    Student() {
        name = "Unknown";
        marks = new int(0);
        cout << "Default Constructor called" << endl;
    }

    Student(string n, int m) {
        name = n;
        marks = new int(m);
        cout << "Parameterized constructor called" << endl;
    }

    Student(const Student& other) {
        name = other.name;
        marks = new int(*other.marks);
        cout << "Copy constructor called" << endl;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Marks: " << *marks << endl;
    }

    ~Student() {
        delete marks;
    }
};

int main() {
    cout << "Default Constructor" << endl;
    Student s1;
    s1.display();

    cout << "\nParameterized Constructor" << endl;
    Student s2("ABC", 90);
    s2.display();

    cout << "\nCopy Constructor" << endl;
    Student s3 = s2;
    s3.display();

    return 0;
}

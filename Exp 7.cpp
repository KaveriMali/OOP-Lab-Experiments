#include <iostream>
#include <string>
using namespace std;

class complex
{
    int real, imag;
public:
    complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }

    void display()
    {
        cout << real << "+" << imag << "i" << endl;
    }

    void display(string msg)
    {
        cout << msg << real << "+" << imag << "i" << endl;
    }
    complex operator+(complex c)
    {
        complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
};

int main()
{
    complex c1(3, 4);
    complex c2(2, 5);

    c1.display();
    c1.display("First complex number: ");

    complex c3 = c1 + c2;

    cout << "Addition: ";
    c3.display();

    return 0;
}

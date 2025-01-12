#include <iostream>
using namespace std;

class Complex {
public:
    double real;
    double image;

public:
    Complex(float r = 0, float i = 0) {
        real = r;
        image = i;
    }

    friend Complex operator+(Complex obj1, Complex obj2);
    friend Complex operator-(Complex obj1, Complex obj2);

    void display() {
        cout << real << "+" << image << "i" << endl;
    }
};

Complex operator+(Complex obj1, Complex obj2) {
    Complex temp;
    temp.real = obj1.real + obj2.real;
    temp.image = obj1.image + obj2.image;
    return temp;
}

Complex operator-(Complex obj1, Complex obj2) {
    Complex temp;
    temp.real = obj1.real - obj2.real;
    temp.image = obj1.image - obj2.image;
    return temp;
}

int main() {
    float a, b, c, d;
    cout << "Enter c1\n";
    cin >> a >> b;

    Complex c1(a, b);
    cout << "Enter c2\n";
    cin >> c >> d;

    Complex c2(c, d);
    Complex c3 = c1 + c2;
    c3.display();

    Complex c4 = c1 - c2;
    c4.display();

    return 0;
}

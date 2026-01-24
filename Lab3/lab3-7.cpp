#include <iostream>
#include <string>
using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double r = 0, double i = 0) : real(r), imaginary(i) {}

    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }
    void setReal(double r) { real = r; }
    void setImaginary(double i) { imaginary = i; }

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imaginary * other.imaginary,
            real * other.imaginary + imaginary * other.real);
    }

    bool operator==(const Complex& other) const {
        return real == other.real && imaginary == other.imaginary;
    }

    friend ostream& operator<<(ostream& os, const Complex& c);
    friend istream& operator>>(istream& is, Complex& c);

    void display() const {
        cout << real << " + " << imaginary << "i" << endl;
    }
};

ostream& operator<<(ostream& os, const Complex& c) {
    os << c.real;
    if (c.imaginary >= 0) {
        os << " + " << c.imaginary << "i";
    }
    else {
        os << " - " << -c.imaginary << "i";
    }
    return os;
}

istream& operator>>(istream& is, Complex& c) {
    cout << "������� �������������� �����: ";
    is >> c.real;
    cout << "������� ������ �����: ";
    is >> c.imaginary;
    return is;
}

int main() {
    Complex c1(3.0, 4.0);
    Complex c2(1.5, -2.5);

    cout << "=== ������������ ������ ����������� ����� ===" << endl;

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    cout << "\n=== �������������� �������� ===" << endl;
    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex product = c1 * c2;

    cout << "c1 + c2 = " << sum << endl;
    cout << "c1 - c2 = " << diff << endl;
    cout << "c1 * c2 = " << product << endl;

    cout << "\n=== ��������� ===" << endl;
    Complex c3(3.0, 4.0);
    cout << "c1 = " << c1 << endl;
    cout << "c3 = " << c3 << endl;
    cout << "c1 == c3: " << (c1 == c3 ? "true" : "false") << endl;
    cout << "c1 == c2: " << (c1 == c2 ? "true" : "false") << endl;

    cout << "\n=== ���� ������������ ����� ===" << endl;
    Complex c4;
    cin >> c4;
    cout << "��������� �����: " << c4 << endl;

    cout << "\n=== �������������� �������� ===" << endl;
    Complex result = c1 + c2 * c3;
    cout << "c1 + c2 * c3 = " << result << endl;

    return 0;
}
#include <iostream>
using namespace std;

struct Complex {
    double real;
    double imag;
};
 
// ôóíêöèÿ ñëîæåíèÿ
Complex plus(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

// ôóíêöèÿ âû÷èòàíèÿ
Complex minus(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

// ôóíêöèÿ óìíîæåíèÿ (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
Complex multiply(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

void print(Complex c) {
    if (c.imag >= 0) {
        cout << "(" << c.real << " + " << c.imag << "i)";
    }
    else {
        cout << "(" << c.real << " - " << -c.imag << "i)";
    }
}

int main() {

    Complex num1 = { 3, 2 };
    Complex num2 = { 1, -4 };

    cout << "ÑËÎÆÅÍÈÅ:" << endl;
    Complex sum = plus(num1, num2);
    print(num1); cout << " + "; print(num2); cout << " = "; print(sum);
    cout << endl;
    cout << endl;

    cout << "ÂÛ×ÈÒÀÍÈÅ:" << endl;
    Complex diff = minus(num1, num2);
    print(num1); cout << " - "; print(num2); cout << " = "; print(diff);
    cout << endl;
    cout << endl;

    cout << "ÓÌÍÎÆÅÍÈÅ:" << endl;
    Complex product = multiply(num1, num2);
    print(num1); cout << " * "; print(num2); cout << " = "; print(product);
    cout << endl;

    return 0;
}
#include <iostream>
using namespace std;

void swapValues1(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Просто обмен значениями: a = " << a << ", b = " << b << endl;
}

void swapValues2(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "Указатели: *a = " << *a << ", *b = " << *b << endl;
}

void swapValues3(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Ссылки: a = " << a << ", b = " << b << endl;
}

int main() {
    int x = 5, y = 10;

    cout << "1. Передача по значению:" << endl;
    swapValues1(x, y);
    cout << "x = " << x << ", y = " << y << endl;

    x = 5; y = 10;

    cout << "2. Передача по указателю:" << endl;
    swapValues2(&x, &y);
    cout << "x = " << x << ", y = " << y << endl;

    x = 5; y = 10;

    cout << "3. Передача по ссылке:" << endl;
    swapValues3(x, y);
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
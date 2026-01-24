#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10;
    int arr1[SIZE];
    int arr2[SIZE];

    int* ptr = arr1;

    *ptr = 0;
    ptr++;
    *ptr = 1;
    ptr++;

    int* prev1 = arr1 + 1;
    int* prev2 = arr1;

    for (int i = 2; i < SIZE; i++) {
        *ptr = *prev1 + *prev2;
        ptr++;
        prev1++;
        prev2++;
    }

    cout << "Массив Фибоначчи: ";
    ptr = arr1;
    for (int i = 0; i < SIZE; i++) {
        cout << *ptr << " ";
        ptr++;
    }
    cout << endl;

    cout << "\nSum:" << endl;
    int sum = 0;
    ptr = arr1;
    for (int i = 0; i < SIZE; i++) {
        sum += *ptr;
        ptr++;
    }
    cout << "Sum: " << sum << endl;

    cout << "\nMin:" << endl;
    ptr = arr1;
    int min_value = *ptr;
    ptr++;

    for (int i = 1; i < SIZE; i++) {
        if (*ptr < min_value) {
            min_value = *ptr;
        }
        ptr++;
    }
    cout << "Min: " << min_value << endl;

    cout << "\n4. Копирование в обратном порядке:" << endl;
    int* source_ptr = arr1 + SIZE - 1;
    int* dest_ptr = arr2;

    for (int i = 0; i < SIZE; i++) {
        *dest_ptr = *source_ptr;
        dest_ptr++;
        source_ptr--;
    }

    cout << "Массив в обратном порядке: ";
    ptr = arr2;
    for (int i = 0; i < SIZE; i++) {
        cout << *ptr << " ";
        ptr++;
    }
    cout << endl;

    return 0;
}

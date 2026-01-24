#include <iostream>
using namespace std;

void arrayInfo(int* arr, int size) {
    int sum = 0;

    cout << "size" << size << endl;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    cout << "sum" << sum << endl;
    cout << "first element: " << *arr << endl;
    cout << "last element: " << *(arr + size - 1) << endl;

}

int main() {
    int numbers1[] = { 1, 2, 3};
    int size1 = sizeof(numbers1) / sizeof(numbers1[0]);

    int numbers2[] = { 12, 43, 53, 40, 535};
    int size2 = sizeof(numbers2) / sizeof(numbers2[0]);
    cout << "1 arr ;";
    arrayInfo(numbers1, size1);
    cout << "2 arr  : ";
    arrayInfo(numbers2, size2);

    return 0;
}

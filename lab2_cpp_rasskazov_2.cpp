#include <iostream>

using namespace std;

int main() {
    const int MAX_SIZE = 256;
    char str[MAX_SIZE];

    cout << "Ввод: ";
    cin.getline(str, MAX_SIZE);

    //*
    int length = 0;
    char* ptr = str;
    while (*ptr != '\0') {
        length++;
        ptr++;
    }
    cout << "Длина: " << length << endl;
    
    //*
    char* start = str;
    char* end = str + length - 1;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
    cout << "Перевернутая строка: " << str << endl;

    //*
    char target_char;
    cout << "Ввод символа для поиска: ";
    cin >> target_char;

    int count = 0;
    ptr = str;
    while (*ptr != '\0') {
        if (*ptr == target_char) {
            count++;
        }
        ptr++;
    }
    cout << target_char << " " << count << " раз(а)" << endl;

    return 0;
}

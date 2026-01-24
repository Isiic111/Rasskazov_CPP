#include <iostream>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

struct Student {
    string name;
    Date birthday;
    int grades[5];
};

void printStudent(const Student& s) {
    cout << s.name << ", дата рождения: " << s.birthday.day << "." << s.birthday.month << "." << s.birthday.year << endl;
    cout << "Оценки: ";
    for (int i = 0; i < 5; i++) {
        cout << s.grades[i] << " ";
    }
}

double getAverageRating(const Student& s) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += s.grades[i];
    }
    return sum / 5;
}

int main() {

    Student students[5] = {
        {"Abcd Efgh", {15, 5, 2000}, {5, 4, 5, 4, 5}},
        {"1234 4321", {20, 8, 2001}, {3, 4, 3, 4, 3}},
        {"ivan ivanov", {10, 3, 2000}, {5, 5, 5, 5, 5}},
        {"artem rasskazov", {5, 12, 2001}, {4, 4, 4, 4, 4}},
        {"bogdan malyj", {25, 7, 2000}, {5, 4, 5, 5, 4}}
    };

    cout << "Все студенты:" << endl;
    for (int i = 0; i < 5; i++) {
        printStudent(students[i]);
        cout << ", средний балл: " << getAverageRating(students[i]) << endl;
    }

    cout << "\nСтуденты со средним баллом выше 4.0:" << endl;
    for (int i = 0; i < 5; i++) {
        if (getAverageRating(students[i]) >= 4.0) {
            printStudent(students[i]);
            cout << "\nСредний балл: " << getAverageRating(students[i]) << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
    double averageGrade;
    int grades[5];

public:
    Student(string studentName, int studentAge) {
        setName(studentName);
        setAge(studentAge);
        for (int i = 0; i < 5; i++) {
            grades[i] = 0;
        }
        averageGrade = 0.0;
    }

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    double getAverageGrade() const {
        return averageGrade;
    }

    int getGrade(int index) const {
        if (index >= 0 && index < 5) {
            return grades[index];
        }
        return -1;
    }

    void setName(string studentName) {
        if (!studentName.empty()) {
            name = studentName;
        }
        else {
            cout << "Ошибка: имя не может быть пустым" << endl;
        }
    }

    void setAge(int studentAge) {
        if (studentAge >= 16 && studentAge <= 100) {
            age = studentAge;
        }
        else {
            cout << "Ошибка: возраст должен быть от 16 до 21" << endl;
            age = 18;
        }
    }

    void setGrade(int index, int grade) {
        if (index >= 0 && index < 5) {
            if (grade >= 2 && grade <= 5) {
                grades[index] = grade;
                calculateAverageGrade();
            }
            else {
                cout << "Ошибка: оценка должна быть от 2 до 5" << endl;
            }
        }
        else {
            cout << "Ошибка: индекс должен быть от 0 до 4" << endl;
        }
    }

    void calculateAverageGrade() {
        double sum = 0;
        int count = 0;
        for (int i = 0; i < 5; i++) {
            if (grades[i] > 0) {
                sum += grades[i];
                count++;
            }
        }
        if (count > 0) {
            averageGrade = sum / count;
        }
        else {
            averageGrade = 0.0;
        }
    }

    void displayInfo() const {
        cout << "Информация о студенте:" << endl;
        cout << "Имя: " << name << endl;
        cout << "Возраст: " << age << " лет" << endl;
        cout << "Оценки: ";
        for (int i = 0; i < 5; i++) {
            cout << grades[i] << " ";
        }
        cout << endl;
        cout << "Средний балл: " << averageGrade << endl;
    }

    bool hasScholarship() const {
        return averageGrade >= 4.5;
    }
};

int main() {

    Student student("Рассказов Артём", 21);

    student.setGrade(0, 5);
    student.setGrade(1, 4);
    student.setGrade(2, 5);
    student.setGrade(3, 3);
    student.setGrade(4, 4);

    student.displayInfo();

    if (student.hasScholarship()) {
        cout << "Студент получает стипендию" << endl;
    }
    else {
        cout << "Стипендия не назначена" << endl;
    }

    Student invalidStudent("", 15);
    invalidStudent.setGrade(0, 6);
    invalidStudent.setGrade(10, 4);

    invalidStudent.displayInfo();

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
    string address;

public:
    Person(string n, int a, string addr) : name(n), age(a), address(addr) {}
    virtual void displayInfo() const {
        cout << "���: " << name << ", �������: " << age << ", �����: " << address << endl;
    }
    virtual ~Person() {}
};

class Student : public Person {
private:
    string studentId;
    double averageGrade;

public:

    Student(string n, int a, string addr, string id, double grade)
        : Person(n, a, addr), studentId(id), averageGrade(grade) {}

    void displayInfo() const override {
        cout << "�������: " << name << ", �������: " << age
            << ", ID: " << studentId << ", ������� ����: " << averageGrade << endl;
    }

    void updateGrade(double newGrade) {
        averageGrade = newGrade;
    }

    double getGrade() const {
        return averageGrade;
    }

    string getStudentId() const {
        return studentId;
    }
};

class Professor : public Person {
private:
    string department;
    double salary;
    int yearsOfExperience;

public:
    Professor(string n, int a, string addr, string dept, double sal, int exp)
        : Person(n, a, addr), department(dept), salary(sal), yearsOfExperience(exp) {}

    void displayInfo() const override {
        cout << "���������: " << name << ", �������: " << age
            << ", �������: " << department << ", ��������: " << salary
            << " ���., ����: " << yearsOfExperience << " ���" << endl;
    }

    double calculateExperienceBonus() const {
        return salary * 0.05 * yearsOfExperience;
    }

    double getTotalSalary() const {
        return salary + calculateExperienceBonus();
    }
};

int main() {
    Student student("���� ������", 20, "��. ������������, 15", "S12345", 4.3);
    Professor prof("������ ������", 45, "��. �������������, 10", "������������ �����", 50000, 15);

    student.displayInfo();
    prof.displayInfo();

    cout << "\n�������������� ����������:" << endl;
    cout << "�������� ���������� �� ����: " << prof.calculateExperienceBonus() << " ���." << endl;
    cout << "����� �������� ����������: " << prof.getTotalSalary() << " ���." << endl;

    student.updateGrade(4.7);
    cout << "����������� ������� ���� ��������: " << student.getGrade() << endl;
    student.displayInfo();

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}
    virtual void display() const {
        cout << "���: " << name << ", �������: " << age << endl;
    }
};

class Employee {
protected:
    string position;
    double salary;

public:
    Employee(string pos, double sal) : position(pos), salary(sal) {}
    virtual void work() const {
        cout << "��������� ������ ��� ���������" << endl;
    }
};

class Teacher : public Person, public Employee {
private:
    string subject;
    int experienceYears;

public:
    Teacher(string n, int a, string pos, double sal, string subj, int exp)
        : Person(n, a), Employee(pos, sal), subject(subj), experienceYears(exp) {}

    void display() const override {
        cout << "�������������: " << name << ", �������: " << age << endl;
        cout << "���������: " << position << ", ��������: " << salary << endl;
        cout << "�������: " << subject << ", ����: " << experienceYears << " ���" << endl;
    }

    void work() const override {
        cout << "��������� �������: " << subject << endl;
    }

    void gradeStudents() const {
        cout << name << " ��������� ���������" << endl;
    }

    void prepareLesson() const {
        cout << name << " ��������� � ����� �� " << subject << endl;
    }
};

class Researcher {
protected:
    string researchArea;
    int publicationsCount;

public:
    Researcher(string area, int publications)
        : researchArea(area), publicationsCount(publications) {}

    void conductResearch() const {
        cout << "�������� ������������ � �������: " << researchArea << endl;
    }
};

class Professor : public Teacher, public Researcher {
public:
    Professor(string n, int a, string pos, double sal, string subj, int exp,
        string area, int publications)
        : Teacher(n, a, pos, sal, subj, exp),
        Researcher(area, publications) {}

    void display() const override {
        cout << "���������: " << Person::name << ", �������: " << age << endl;
        cout << "���������: " << position << ", ��������: " << salary << endl;
        cout << "�������: " << subject << ", ����: " << experienceYears << " ���" << endl;
        cout << "������� ������������: " << researchArea << endl;
        cout << "���������� ����������: " << publicationsCount << endl;
    }

    void work() const override {
        cout << "��������� " << Person::name << " ��������:" << endl;
        Teacher::work();
        conductResearch();
    }

    void supervisePhD() const {
        cout << "��������� ����������� � ������� " << researchArea << endl;
    }
};

int main() {
    Teacher teacher("���� ���������", 35, "������� �������������", 50000,
        "����������", 10);

    Professor professor("���� ��������", 55, "���������� ��������", 100000,
        "������", 25, "��������� ��������", 50);

    cout << "=== ������������ �������������� ������������ ===" << endl;

    cout << "\n--- ������������� ---" << endl;
    teacher.display();
    teacher.work();
    teacher.gradeStudents();
    teacher.prepareLesson();

    cout << "\n--- ��������� ---" << endl;
    professor.display();
    professor.work();
    professor.gradeStudents();
    professor.conductResearch();
    professor.supervisePhD();

    cout << "\n=== ����������� ===" << endl;

    Person* personPtr = &professor;
    Employee* employeePtr = &professor;

    cout << "\n����� ��������� �� Person:" << endl;
    personPtr->display();

    cout << "\n����� ��������� �� Employee:" << endl;
    employeePtr->work();

    return 0;
}
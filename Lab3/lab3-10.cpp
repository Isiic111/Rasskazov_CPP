#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

class UniversityMember {
protected:
    string name;
    string id;
    string email;

public:
    UniversityMember(string n, string i, string e) : name(n), id(i), email(e) {}
    virtual ~UniversityMember() {}

    virtual void displayInfo() const = 0;
    virtual void work() const = 0;
    virtual string getRole() const = 0;

    string getName() const { return name; }
    string getId() const { return id; }
    string getEmail() const { return email; }
};

class Student : public UniversityMember {
private:
    string major;
    int year;
    double gpa;
    vector<string> courses;

public:
    Student(string n, string i, string e, string m, int y)
        : UniversityMember(n, i, e), major(m), year(y), gpa(0.0) {}

    void displayInfo() const override {
        cout << "�������: " << name << " (ID: " << id << ")" << endl;
        cout << "Email: " << email << endl;
        cout << "�������������: " << major << ", ���: " << year << endl;
        cout << "GPA: " << gpa << endl;
        cout << "�����: ";
        for (const auto& course : courses) {
            cout << course << " ";
        }
        cout << endl;
    }

    void work() const override {
        cout << name << " ������ � �������� ������" << endl;
    }

    string getRole() const override {
        return "�������";
    }

    void enrollCourse(const string& course) {
        courses.push_back(course);
    }

    void dropCourse(const string& course) {
        auto it = find(courses.begin(), courses.end(), course);
        if (it != courses.end()) {
            courses.erase(it);
        }
    }

    void calculateGPA() {
        if (!courses.empty()) {
            gpa = 3.0 + (rand() % 20) / 10.0;
        }
    }

    double getGPA() const { return gpa; }
    string getMajor() const { return major; }
};

class Professor : public UniversityMember {
private:
    string department;
    string office;
    double salary;
    vector<string> teachingCourses;

public:
    Professor(string n, string i, string e, string dept, string off, double sal)
        : UniversityMember(n, i, e), department(dept), office(off), salary(sal) {}

    void displayInfo() const override {
        cout << "���������: " << name << " (ID: " << id << ")" << endl;
        cout << "Email: " << email << endl;
        cout << "�������: " << department << ", �������: " << office << endl;
        cout << "��������: " << salary << endl;
        cout << "������������� �����: ";
        for (const auto& course : teachingCourses) {
            cout << course << " ";
        }
        cout << endl;
    }

    void work() const override {
        cout << name << " ��������� � �������� ������������" << endl;
    }

    string getRole() const override {
        return "���������";
    }

    void assignCourse(const string& course) {
        teachingCourses.push_back(course);
    }

    void removeCourse(const string& course) {
        auto it = find(teachingCourses.begin(), teachingCourses.end(), course);
        if (it != teachingCourses.end()) {
            teachingCourses.erase(it);
        }
    }

    double calculateSalary() const {
        return salary + teachingCourses.size() * 5000;
    }

    string getDepartment() const { return department; }
};

class Course {
private:
    string courseCode;
    string courseName;
    int credits;
    Professor* instructor;
    vector<Student*> enrolledStudents;

public:
    Course(string code, string name, int cred)
        : courseCode(code), courseName(name), credits(cred), instructor(nullptr) {}

    void addStudent(Student* student) {
        enrolledStudents.push_back(student);
        student->enrollCourse(courseName);
    }

    void removeStudent(const string& studentId) {
        auto it = find_if(enrolledStudents.begin(), enrolledStudents.end(),
            [&](Student* s) { return s->getId() == studentId; });
        if (it != enrolledStudents.end()) {
            (*it)->dropCourse(courseName);
            enrolledStudents.erase(it);
        }
    }

    void setInstructor(Professor* prof) {
        instructor = prof;
        if (prof) {
            prof->assignCourse(courseName);
        }
    }

    void displayCourseInfo() const {
        cout << "����: " << courseCode << " - " << courseName << endl;
        cout << "�������: " << credits << endl;
        if (instructor) {
            cout << "�������������: " << instructor->getName() << endl;
        }
        else {
            cout << "�������������: �� ��������" << endl;
        }
        cout << "����������� �������� (" << enrolledStudents.size() << "):" << endl;
        for (const auto& student : enrolledStudents) {
            cout << "  - " << student->getName() << " (" << student->getId() << ")" << endl;
        }
    }

    string getCourseCode() const { return courseCode; }
    string getCourseName() const { return courseName; }
    int getCredits() const { return credits; }
};

class University {
private:
    string name;
    vector<unique_ptr<UniversityMember>> members;
    vector<unique_ptr<Course>> courses;
    static int totalUniversities;

public:
    University(string n) : name(n) {
        totalUniversities++;
    }

    ~University() {
        totalUniversities--;
    }

    void addMember(unique_ptr<UniversityMember> member) {
        members.push_back(move(member));
    }

    void addCourse(unique_ptr<Course> course) {
        courses.push_back(move(course));
    }

    UniversityMember* findMember(const string& id) {
        for (auto& member : members) {
            if (member->getId() == id) {
                return member.get();
            }
        }
        return nullptr;
    }

    Course* findCourse(const string& code) {
        for (auto& course : courses) {
            if (course->getCourseCode() == code) {
                return course.get();
            }
        }
        return nullptr;
    }

    void displayAllMembers() const {
        cout << "=== ��� ����� ������������ " << name << " ===" << endl;
        for (const auto& member : members) {
            member->displayInfo();
            cout << "-------------------" << endl;
        }
    }

    void displayAllCourses() const {
        cout << "=== ��� ����� ������������ " << name << " ===" << endl;
        for (const auto& course : courses) {
            course->displayCourseInfo();
            cout << "-------------------" << endl;
        }
    }

    static int getTotalUniversities() {
        return totalUniversities;
    }
};

int University::totalUniversities = 0;

int main() {
    University university("����������� �����������");

    cout << "=== �������� ��������������� ������� ===" << endl;

    auto student1 = make_unique<Student>("���� ������", "S001", "ivan@university.com",
        "������������ �����", 2);
    auto student2 = make_unique<Student>("���� ������", "S002", "petr@university.com",
        "����������", 1);
    auto student3 = make_unique<Student>("���� ��������", "S003", "anna@university.com",
        "������", 3);

    auto professor1 = make_unique<Professor>("������ �������", "P001", "smirnov@university.com",
        "������������ �����", "�-101", 80000);
    auto professor2 = make_unique<Professor>("������ �������", "P002", "kozlova@university.com",
        "����������", "�-205", 75000);

    university.addMember(move(student1));
    university.addMember(move(student2));
    university.addMember(move(student3));
    university.addMember(move(professor1));
    university.addMember(move(professor2));

    auto course1 = make_unique<Course>("CS101", "�������� � ����������������", 4);
    auto course2 = make_unique<Course>("MATH201", "�������� �������", 3);
    auto course3 = make_unique<Course>("PHYS150", "����� ������", 5);

    university.addCourse(move(course1));
    university.addCourse(move(course2));
    university.addCourse(move(course3));

    Course* cs101 = university.findCourse("CS101");
    Professor* prof1 = dynamic_cast<Professor*>(university.findMember("P001"));
    if (cs101 && prof1) {
        cs101->setInstructor(prof1);
    }

    Course* math201 = university.findCourse("MATH201");
    Professor* prof2 = dynamic_cast<Professor*>(university.findMember("P002"));
    if (math201 && prof2) {
        math201->setInstructor(prof2);
    }

    Student* stud1 = dynamic_cast<Student*>(university.findMember("S001"));
    Student* stud2 = dynamic_cast<Student*>(university.findMember("S002"));
    Student* stud3 = dynamic_cast<Student*>(university.findMember("S003"));

    if (cs101 && stud1 && stud2) {
        cs101->addStudent(stud1);
        cs101->addStudent(stud2);
    }

    if (math201 && stud2 && stud3) {
        math201->addStudent(stud2);
        math201->addStudent(stud3);
    }

    if (stud1) stud1->calculateGPA();
    if (stud2) stud2->calculateGPA();
    if (stud3) stud3->calculateGPA();

    cout << "\n=== ���������� � ������� ===" << endl;
    cout << "����� �������������: " << University::getTotalUniversities() << endl;

    university.displayAllMembers();
    university.displayAllCourses();

    cout << "\n=== ������������ ������������ ===" << endl;
    UniversityMember* member1 = university.findMember("S001");
    UniversityMember* member2 = university.findMember("P001");

    if (member1) {
        cout << "����: " << member1->getRole() << endl;
        member1->work();
        member1->displayInfo();
    }

    if (member2) {
        cout << "\n����: " << member2->getRole() << endl;
        member2->work();
        member2->displayInfo();
    }

    return 0;
}
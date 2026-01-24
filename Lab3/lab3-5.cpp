#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    int year;
    bool isAvailable;

public:
    Book(string t, string a, string i, int y)
        : title(t), author(a), isbn(i), year(y), isAvailable(true) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getIsbn() const { return isbn; }
    int getYear() const { return year; }
    bool getIsAvailable() const { return isAvailable; }

    void setTitle(const string& t) { title = t; }
    void setAuthor(const string& a) { author = a; }
    void setYear(int y) { year = y; }

    void borrow() {
        if (isAvailable) {
            isAvailable = false;
        }
    }

    void returnBook() {
        isAvailable = true;
    }

    void displayInfo() const {
        cout << "��������: " << title << endl;
        cout << "�����: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "���: " << year << endl;
        cout << "������: " << (isAvailable ? "��������" : "������") << endl;
    }
};

class Library {
private:
    string name;
    string address;
    vector<Book> books;

public:
    Library(string n, string addr) : name(n), address(addr) {}

    void addBook(const Book& book) {
        books.push_back(book);
    }

    void removeBook(const string& isbn) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getIsbn() == isbn) {
                books.erase(it);
                break;
            }
        }
    }

    Book* findBook(const string& title) {
        for (auto& book : books) {
            if (book.getTitle() == title) {
                return &book;
            }
        }
        return nullptr;
    }

    bool borrowBook(const string& isbn) {
        for (auto& book : books) {
            if (book.getIsbn() == isbn && book.getIsAvailable()) {
                book.borrow();
                return true;
            }
        }
        return false;
    }

    bool returnBook(const string& isbn) {
        for (auto& book : books) {
            if (book.getIsbn() == isbn && !book.getIsAvailable()) {
                book.returnBook();
                return true;
            }
        }
        return false;
    }

    void displayAllBooks() const {
        cout << "��� ����� � ���������� \"" << name << "\":" << endl;
        for (const auto& book : books) {
            book.displayInfo();
            cout << "-------------------" << endl;
        }
    }

    void displayAvailableBooks() const {
        cout << "��������� ����� � ���������� \"" << name << "\":" << endl;
        for (const auto& book : books) {
            if (book.getIsAvailable()) {
                book.displayInfo();
                cout << "-------------------" << endl;
            }
        }
    }
};

int main() {
    Library library("����������� ����������", "��. ������, 1");

    library.addBook(Book("����� � ���", "��� �������", "1234567890", 1869));
    library.addBook(Book("������������ � ���������", "����� �����������", "1234567891", 1866));
    library.addBook(Book("������ � ���������", "������ ��������", "1234567892", 1967));

    cout << "=== ������������ ������ ���������� ===" << endl;

    library.displayAllBooks();

    library.displayAvailableBooks();

    cout << "������ ����� � ISBN 1234567890: ";
    if (library.borrowBook("1234567890")) {
        cout << "������� ������" << endl;
    }
    else {
        cout << "�� ������� ������" << endl;
    }

    Book* foundBook = library.findBook("������������ � ���������");
    if (foundBook) {
        cout << "������� �����: ";
        foundBook->displayInfo();
    }

    cout << "��������� ������ ����� � ISBN 1234567890: ";
    if (library.borrowBook("1234567890")) {
        cout << "������� ������" << endl;
    }
    else {
        cout << "�� ������� ������" << endl;
    }

    cout << "������� ����� � ISBN 1234567890: ";
    if (library.returnBook("1234567890")) {
        cout << "������� ����������" << endl;
    }
    else {
        cout << "�� ������� �������" << endl;
    }

    library.removeBook("1234567892");
    cout << "����� �������� �����:" << endl;
    library.displayAllBooks();

    return 0;
}
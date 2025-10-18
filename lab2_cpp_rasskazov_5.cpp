#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    int year;
    double price;
};

void printBooks(Book* books, int size) {
    cout << "\nВсе книги:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Книга " << i + 1 << endl;
        cout << "  Название: " << books[i].title << endl;
        cout << "  Автор: " << books[i].author << endl;
        cout << "  Год: " << books[i].year << endl;
        cout << "  Цена: " << books[i].price << endl;
        cout << endl;
    }
}

void findMostExpensiveBook(Book* books, int size) {

    int maxwin = 0;
    for (int i = 1; i < size; i++) {
        if (books[i].price > books[maxwin].price) {
            maxwin = i;
        }
    }

    cout << "\nmaxwin книга" << endl;
    cout << "Название: " << books[maxwin].title << endl;
    cout << "Автор: " << books[maxwin].author << endl;
    cout << "Год: " << books[maxwin].year << endl;
    cout << "Цена: " << books[maxwin].price << endl;
}

int main() {
    int n;

    cout << "Кол-во книг:";
    cin >> n;
    cin.ignore();

    Book* library = new Book[n];

    cout << "\nИнформация о книгах:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Книга " << i + 1 << ":" << endl;

        cout << "  Название: ";
        getline(cin, library[i].title);

        cout << "  Автор: ";
        getline(cin, library[i].author);

        cout << "  Год издания: ";
        cin >> library[i].year;

        cout << "  Цена: ";
        cin >> library[i].price;
        cin.ignore();
        cout << endl;
    }

    printBooks(library, n);

    findMostExpensiveBook(library, n);

    delete[] library;

    return 0;
}
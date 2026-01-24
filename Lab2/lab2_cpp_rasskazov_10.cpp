#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    int year;
};

void sortBooksByYear(Book* books, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (books[j].year > books[j + 1].year) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

Book* findBookByAuthor(Book* books, int size, string author) {
    for (int i = 0; i < size; i++) {
        if (books[i].author == author) {
            return &books[i];
        }
    }
    return nullptr;
}

void printBook(Book book) {
    cout << book.title << " . " << book.author << " . " << book.year << endl;
}

int main() {
    Book* books = new Book[4];

    books[0] = { "Война и мир", "Толстой", 1869 };
    books[1] = { "Преступление и наказание", "Достоевский", 1866 };
    books[2] = { "Мастер и Маргарита", "Булгаков", 1967 };
    books[3] = { "Евгений Онегин", "Пушкин", 1833 };

    cout << "Исходный список:" << endl;
    for (int i = 0; i < 4; i++) {
        printBook(books[i]);
    }

    sortBooksByYear(books, 4);

    cout << "\nПосле сортировки по году:" << endl;
    for (int i = 0; i < 4; i++) {
        printBook(books[i]);
    }

    cout << "\nПоиск книг:" << endl;

    Book* found = findBookByAuthor(books, 4, "Толстой");
    if (found != nullptr) {
        cout << "Найдена: ";
        printBook(*found);
    }
    else {
        cout << "Книга Толстого не найдена" << endl;
    }

    found = findBookByAuthor(books, 4, "Чехов");
    if (found != nullptr) {
        cout << "Найдена: ";
        printBook(*found);
    }
    else {
        cout << "Книга Чехова не найдена" << endl;
    }

    delete[] books;

    return 0;
}
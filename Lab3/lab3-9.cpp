#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
using namespace std;

template<typename T>
class Stack {
private:
    vector<T> elements;
    int capacity;

public:
    Stack(int size = 10) : capacity(size) {}

    void push(const T& element) {
        if (isFull()) {
            throw overflow_error("���� ����������");
        }
        elements.push_back(element);
    }

    T pop() {
        if (isEmpty()) {
            throw underflow_error("���� ����");
        }
        T topElement = elements.back();
        elements.pop_back();
        return topElement;
    }

    T top() const {
        if (isEmpty()) {
            throw underflow_error("���� ����");
        }
        return elements.back();
    }

    bool isEmpty() const {
        return elements.empty();
    }

    bool isFull() const {
        return elements.size() >= capacity;
    }

    int size() const {
        return elements.size();
    }

    int getCapacity() const {
        return capacity;
    }

    void display() const {
        cout << "����: ";
        for (const auto& elem : elements) {
            cout << elem << " ";
        }
        cout << endl;
    }
};

template<typename T>
class Queue {
private:
    vector<T> elements;
    int capacity;

public:
    Queue(int size = 10) : capacity(size) {}

    void enqueue(const T& element) {
        if (isFull()) {
            throw overflow_error("������� �����������");
        }
        elements.push_back(element);
    }

    T dequeue() {
        if (isEmpty()) {
            throw underflow_error("������� �����");
        }
        T frontElement = elements.front();
        elements.erase(elements.begin());
        return frontElement;
    }

    T front() const {
        if (isEmpty()) {
            throw underflow_error("������� �����");
        }
        return elements.front();
    }

    bool isEmpty() const {
        return elements.empty();
    }

    bool isFull() const {
        return elements.size() >= capacity;
    }

    int size() const {
        return elements.size();
    }

    int getCapacity() const {
        return capacity;
    }

    void display() const {
        cout << "�������: ";
        for (const auto& elem : elements) {
            cout << elem << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "=== ������������ ��������� ������� ===" << endl;

    cout << "\n--- STACK � int ---" << endl;
    Stack<int> intStack(5);

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.display();

    cout << "������� �������: " << intStack.top() << endl;
    cout << "������: " << intStack.size() << endl;

    cout << "��������: " << intStack.pop() << endl;
    intStack.display();

    cout << "\n--- STACK � double ---" << endl;
    Stack<double> doubleStack(3);

    doubleStack.push(1.5);
    doubleStack.push(2.7);
    doubleStack.push(3.9);
    doubleStack.display();

    cout << "������� �������: " << doubleStack.top() << endl;
    cout << "������? " << (doubleStack.isFull() ? "��" : "���") << endl;

    cout << "\n--- STACK � string ---" << endl;
    Stack<string> stringStack(4);

    stringStack.push("Hello");
    stringStack.push("World");
    stringStack.push("C++");
    stringStack.push("Templates");
    stringStack.display();

    cout << "\n--- QUEUE � int ---" << endl;
    Queue<int> intQueue(4);

    intQueue.enqueue(100);
    intQueue.enqueue(200);
    intQueue.enqueue(300);
    intQueue.display();

    cout << "������ �������: " << intQueue.front() << endl;
    cout << "��������: " << intQueue.dequeue() << endl;
    intQueue.display();

    cout << "\n--- QUEUE � string ---" << endl;
    Queue<string> stringQueue(3);

    stringQueue.enqueue("������");
    stringQueue.enqueue("������");
    stringQueue.enqueue("������");
    stringQueue.display();

    cout << "������ � �������: " << stringQueue.front() << endl;

    cout << "\n--- ��������� ������ ---" << endl;
    Stack<int> smallStack(2);
    smallStack.push(1);
    smallStack.push(2);

    try {
        smallStack.push(3);
    }
    catch (const overflow_error& e) {
        cout << "������: " << e.what() << endl;
    }

    Queue<int> emptyQueue;
    try {
        emptyQueue.dequeue();
    }
    catch (const underflow_error& e) {
        cout << "������: " << e.what() << endl;
    }

    return 0;
}
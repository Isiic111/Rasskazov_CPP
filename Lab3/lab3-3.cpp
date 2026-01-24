#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Shape {
protected:
    string color;
    string name;

public:
    Shape(string n, string c) : name(n), color(c) {}
    virtual ~Shape() {}

    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;
    virtual void draw() const = 0;

    virtual void displayInfo() const {
        cout << "Фигура: " << name << ", Цвет: " << color << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(string c, double r) : Shape("Круг", c), radius(r) {}

    double calculateArea() const override {
        return M_PI * radius * radius;
    }

    double calculatePerimeter() const override {
        return 2 * M_PI * radius;
    }

    void draw() const override {
        cout << "Круг (радиус: " << radius << ")" << endl;
    }

    void displayInfo() const override {
        Shape::displayInfo();
        cout << "Радиус: " << radius << ", Площадь: " << calculateArea()
            << ", Периметр: " << calculatePerimeter() << endl;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(string c, double w, double h) : Shape("Прямоугольник", c), width(w), height(h) {}

    double calculateArea() const override {
        return width * height;
    }

    double calculatePerimeter() const override {
        return 2 * (width + height);
    }

    void draw() const override {
        cout << "Прямоугольник (" << width << " × " << height << ")" << endl;
    }

    void displayInfo() const override {
        Shape::displayInfo();
        cout << "Ширина: " << width << ", Высота: " << height
            << ", Площадь: " << calculateArea()
            << ", Периметр: " << calculatePerimeter() << endl;
    }
};

class Triangle : public Shape {
private:
    double sideA, sideB, sideC;

public:
    Triangle(string c, double a, double b, double c) : Shape("Треугольник", c), sideA(a), sideB(b), sideC(c) {}

    double calculateArea() const override {
        double s = calculatePerimeter() / 2;
        return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    }

    double calculatePerimeter() const override {
        return sideA + sideB + sideC;
    }

    void draw() const override {
        cout << "Треугольник (" << sideA << ", " << sideB << ", " << sideC << ")" << endl;
    }

    void displayInfo() const override {
        Shape::displayInfo();
        cout << "Стороны: " << sideA << ", " << sideB << ", " << sideC
            << ", Площадь: " << calculateArea()
            << ", Периметр: " << calculatePerimeter() << endl;
    }
};

int main() {
    vector<Shape*> shapes;
    shapes.push_back(new Circle("Красный", 5.0));
    shapes.push_back(new Rectangle("Синий", 4.0, 6.0));
    shapes.push_back(new Triangle("Зеленый", 3.0, 4.0, 5.0));


    cout << "ПОЛИМОРФИЗМ" << endl;

    for (size_t i = 0; i < shapes.size(); ++i) {
        cout << "\n--- Фигура " << i + 1 << " ---" << endl;
        shapes[i]->displayInfo();
        shapes[i]->draw();
        cout << "Площадь: " << shapes[i]->calculateArea() << endl;
        cout << "Периметр: " << shapes[i]->calculatePerimeter() << endl;
    }

    for (auto shape : shapes) {
        delete shape;
    }

    return 0;
}
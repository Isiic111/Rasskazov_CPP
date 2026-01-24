#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string brand;
    string model;
    int year;
    double fuelLevel;

public:
    Vehicle(string b, string m, int y) : brand(b), model(m), year(y), fuelLevel(100) {}
    virtual ~Vehicle() {}

    virtual void startEngine() = 0;
    virtual void stopEngine() = 0;
    virtual void refuel(double amount) = 0;

    virtual void displayInfo() const {
        cout << brand << " " << model << " (" << year << ")" << endl;
        cout << "Уровень топлива: " << fuelLevel << "%" << endl;
    }

    double getFuelLevel() const { return fuelLevel; }
    void setFuelLevel(double level) {
        if (level >= 0 && level <= 100) fuelLevel = level;
    }
};

class Car : public Vehicle {
private:
    int doors;
    string transmission;

public:
    Car(string b, string m, int y, int d, string trans)
        : Vehicle(b, m, y), doors(d), transmission(trans) {}

    void startEngine() override {
        cout << brand << " " << model << ": Двигатель запущен" << endl;
    }

    void stopEngine() override {
        cout << brand << " " << model << ": Двигатель остановлен" << endl;
    }

    void refuel(double amount) override {
        double newLevel = fuelLevel + amount;
        if (newLevel > 100) {
            newLevel = 100;
        }
        setFuelLevel(newLevel);
        cout << "Заправлено " << amount << "%. Текущий уровень: " << fuelLevel << "%" << endl;
    }

    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << "Количество дверей: " << doors << endl;
        cout << "Трансмиссия: " << transmission << endl;
    }
};

class Motorcycle : public Vehicle {
private:
    bool hasFairing;

public:
    Motorcycle(string b, string m, int y, bool fairing)
        : Vehicle(b, m, y), hasFairing(fairing) {}

    void startEngine() override {
        cout << brand << " " << model << ": Двигатель заведен" << endl;
    }

    void stopEngine() override {
        cout << brand << " " << model << ": Двигатель заглушен" << endl;
    }

    void refuel(double amount) override {
        double newLevel = fuelLevel + amount;
        if (newLevel > 100) {
            newLevel = 100;
        }
        setFuelLevel(newLevel);
        cout << "Заправлено " << amount << "%. Текущий уровень: " << fuelLevel << "%" << endl;
    }

    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << "Обтекатель: " << (hasFairing ? "есть" : "нет") << endl;
    }

};

int main() {
    Vehicle* garage[3];

    garage[0] = new Car("Toyota", "Camry", 2022, 4, "автоматическая");
    garage[1] = new Car("Honda", "Civic", 2023, 2, "механическая");
    garage[2] = new Motorcycle("Yamaha", "YZF-R6", 2021, true);

    for (int i = 0; i < 3; ++i) {
        cout << "\n--- Транспортное средство " << i + 1 << " ---" << endl;
        garage[i]->displayInfo();
        garage[i]->startEngine();
        garage[i]->refuel(30);
        garage[i]->stopEngine();
    }

    for (int i = 0; i < 3; ++i) {
        delete garage[i];
    }

    return 0;
}
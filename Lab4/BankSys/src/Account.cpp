#include "Account.h"
#include <sstream>
#include <iomanip>

// Инициализация статической переменной
int Account::accountCounter = 1000;  // Начинаем с 1000

Account::Account() 
    : accountNumber(generateAccountNumber()), clientId(0), balance(0.0),
      type(AccountType::CURRENT), active(true) {}

Account::Account(int clientId, double initialBalance, 
                 AccountType accType, const Date& openDate)
    : accountNumber(generateAccountNumber()), clientId(clientId), 
      balance(initialBalance), type(accType), openingDate(openDate), active(true) {}

bool Account::deposit(double amount) {
    if (amount <= 0 || !active) return false;
    balance += amount;
    return true;
}

bool Account::withdraw(double amount) {
    if (amount <= 0 || !active || balance < amount) return false;
    balance -= amount;
    return true;
}

bool Account::transfer(Account& target, double amount) {
    if (!active || !target.active || amount <= 0 || balance < amount) return false;
    balance -= amount;
    target.balance += amount;
    return true;
}

std::string Account::getTypeString() const {
    switch (type) {
        case AccountType::CURRENT: return "Текущий";
        case AccountType::SAVINGS: return "Сберегательный";
        default: return "Неизвестный";
    }
}

std::string Account::getInfo() const {
    std::ostringstream oss;
    oss << "Счет №" << accountNumber 
        << " (клиент " << clientId << ")"
        << ", Тип: " << getTypeString()
        << ", Баланс: " << std::fixed << std::setprecision(2) << balance
        << ", Дата открытия: " << openingDate.toString()
        << " [" << (active ? "активен" : "закрыт") << "]";
    return oss.str();
}

int Account::generateAccountNumber() {
    return ++accountCounter;
}
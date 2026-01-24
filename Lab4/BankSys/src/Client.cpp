#include "Client.h"
#include <iostream>

// Инициализация статической переменной
int Client::clientCounter = 0;

Client::Client() : id(++clientCounter), type(ClientType::REGULAR) {}

Client::Client(const std::string& fName, const std::string& lName, 
               const Address& addr, const Date& regDate)
    : id(++clientCounter), firstName(fName), lastName(lName), 
      address(addr), registrationDate(regDate), type(ClientType::REGULAR) {}

void Client::displayInfo() const {
    std::cout << "ID: " << id << "\n";
    std::cout << "Имя: " << firstName << " " << lastName << "\n";
    std::cout << "Адрес: " << address.toString() << "\n";
    std::cout << "Дата регистрации: " << registrationDate.toString() << "\n";
    std::cout << "Тип: Обычный клиент\n";
}

std::string Client::getFullInfo() const {
    return "ID: " + std::to_string(id) + 
           ", Имя: " + firstName + " " + lastName +
           ", Адрес: " + address.toString() +
           ", Дата регистрации: " + registrationDate.toString();
}
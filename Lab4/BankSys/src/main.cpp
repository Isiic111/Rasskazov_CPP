#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <windows.h>
#include "Bank.h"
#include "Address.h"
#include "Date.h"

void setupConsole() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    system("chcp 65001 > nul");
}

class ConsoleUI {
private:
    Bank& bank;
    
    void clearInput() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    int readInt(const std::string& prompt) {
        int value;
        while (true) {
            std::cout << prompt;
            if (std::cin >> value) {
                clearInput();
                return value;
            }
            std::cout << "Ошибка: введите целое число\n";
            clearInput();
        }
    }
    
    double readDouble(const std::string& prompt) {
        double value;
        while (true) {
            std::cout << prompt;
            if (std::cin >> value && value >= 0) {
                clearInput();
                return value;
            }
            std::cout << "Ошибка: введите положительное число\n";
            clearInput();
        }
    }
    
    std::string readString(const std::string& prompt) {
        std::string value;
        std::cout << prompt;
        std::getline(std::cin, value);
        return value;
    }
    
    Address readAddress() {
        std::string street = readString("Улица и дом: ");
        std::string city = readString("Город: ");
        std::string postalCode = readString("Почтовый индекс: ");
        std::string country = readString("Страна: ");
        
        return Address(street, city, postalCode, country);
    }
    
public:
    ConsoleUI(Bank& b) : bank(b) {}
    
    void showMainMenu() {
        while (true) {
            std::cout << "\n=== БАНКОВСКАЯ СИСТЕМА ===\n";
            std::cout << "1. Меню сотрудника\n";
            std::cout << "2. Меню клиента\n";
            std::cout << "3. Общая информация\n";
            std::cout << "0. Выход\n";
            std::cout << "Выбор: ";
            
            int choice = readInt("");
            
            switch (choice) {
                case 1:
                    employeeMenu();
                    break;
                case 2:
                    clientMenu();
                    break;
                case 3:
                    bank.displayBankInfo();
                    break;
                case 0:
                    std::cout << "Выход из программы...\n";
                    return;
                default:
                    std::cout << "Неверный выбор\n";
            }
        }
    }
    
    void employeeMenu() {
        while (true) {
            std::cout << "\n--- МЕНЮ СОТРУДНИКА ---\n";
            std::cout << "1. Добавить клиента\n";
            std::cout << "2. Удалить клиента\n";
            std::cout << "3. Открыть счет\n";
            std::cout << "4. Закрыть счет\n";
            std::cout << "5. Список всех клиентов\n";
            std::cout << "6. Список всех счетов\n";
            std::cout << "7. История операций\n";
            std::cout << "0. Назад\n";
            std::cout << "Выбор: ";
            
            int choice = readInt("");
            
            switch (choice) {
                case 1:
                    addClient();
                    break;
                case 2:
                    removeClient();
                    break;
                case 3:
                    openAccount();
                    break;
                case 4:
                    closeAccount();
                    break;
                case 5:
                    bank.displayAllClients();
                    break;
                case 6:
                    bank.displayAllAccounts();
                    break;
                case 7:
                    bank.displayAllTransactions();
                    break;
                case 0:
                    return;
                default:
                    std::cout << "Неверный выбор\n";
            }
        }
    }
    
    void clientMenu() {
        int clientId = readInt("Введите ID клиента: ");
        
        Client* client = bank.getClient(clientId);
        if (!client) {
            std::cout << "Клиент не найден\n";
            return;
        }
        
        while (true) {
            std::cout << "\n--- КАБИНЕТ КЛИЕНТА ---\n";
            std::cout << "Клиент: " << client->getFirstName() 
                      << " " << client->getLastName() << "\n";
            std::cout << "1. Мои данные\n";
            std::cout << "2. Мои счета\n";
            std::cout << "3. Пополнить счет\n";
            std::cout << "4. Снять средства\n";
            std::cout << "5. Перевод между счетами\n";
            std::cout << "6. Мои операции\n";
            std::cout << "0. Назад\n";
            std::cout << "Выбор: ";
            
            int choice = readInt("");
            
            switch (choice) {
                case 1:
                    client->displayInfo();
                    break;
                case 2:
                    showClientAccounts(clientId);
                    break;
                case 3:
                    depositToAccount();
                    break;
                case 4:
                    withdrawFromAccount();
                    break;
                case 5:
                    transferBetweenAccounts();
                    break;
                case 6:
                    bank.displayClientTransactions(clientId);
                    break;
                case 0:
                    return;
                default:
                    std::cout << "Неверный выбор\n";
            }
        }
    }
    
    void addClient() {
        std::cout << "\n--- ДОБАВЛЕНИЕ КЛИЕНТА ---\n";
        
        std::string firstName = readString("Имя: ");
        std::string lastName = readString("Фамилия: ");
        
        std::cout << "Адрес:\n";
        Address address = readAddress();
        
        std::cout << "Тип клиента:\n";
        std::cout << "1. Обычный\n";
        std::cout << "2. Премиум\n";
        int typeChoice = readInt("Выбор: ");
        
        int clientId;
        if (typeChoice == 1) {
            clientId = bank.addClient(firstName, lastName, address, ClientType::REGULAR);
            std::cout << "Обычный клиент добавлен. ID: " << clientId << "\n";
        } else if (typeChoice == 2) {
            int level = readInt("Уровень премиум (1-3): ");
            double discount = readDouble("Скидка (%): ");
            clientId = bank.addClient(firstName, lastName, address, 
                                     ClientType::PREMIUM, level, discount);
            std::cout << "Премиум клиент добавлен. ID: " << clientId << "\n";
        } else {
            std::cout << "Неверный выбор типа клиента\n";
        }
    }
    
    void removeClient() {
        std::cout << "\n--- УДАЛЕНИЕ КЛИЕНТА ---\n";
        int clientId = readInt("Введите ID клиента для удаления: ");
        
        if (bank.removeClient(clientId)) {
            std::cout << "Клиент успешно удален\n";
        } else {
            std::cout << "Не удалось удалить клиента (возможно, есть активные счета)\n";
        }
    }
    
    void openAccount() {
        std::cout << "\n--- ОТКРЫТИЕ СЧЕТА ---\n";
        int clientId = readInt("Введите ID клиента: ");
        
        std::cout << "Тип счета:\n";
        std::cout << "1. Текущий\n";
        std::cout << "2. Сберегательный\n";
        int typeChoice = readInt("Выбор: ");
        
        AccountType accType;
        if (typeChoice == 1) {
            accType = AccountType::CURRENT;
        } else if (typeChoice == 2) {
            accType = AccountType::SAVINGS;
        } else {
            std::cout << "Неверный выбор типа счета\n";
            return;
        }
        
        double initialBalance = readDouble("Начальный баланс: ");
        
        int accountNumber = bank.openAccount(clientId, initialBalance, accType);
        if (accountNumber > 0) {
            std::cout << "Счет успешно открыт. Номер: " << accountNumber << "\n";
        } else {
            std::cout << "Не удалось открыть счет (клиент не найден)\n";
        }
    }
    
    void closeAccount() {
        std::cout << "\n--- ЗАКРЫТИЕ СЧЕТА ---\n";
        int accountNumber = readInt("Введите номер счета: ");
        
        if (bank.closeAccount(accountNumber)) {
            std::cout << "Счет успешно закрыт\n";
        } else {
            std::cout << "Не удалось закрыть счет (баланс не нулевой или счет не найден)\n";
        }
    }
    
    void showClientAccounts(int clientId) {
        auto accounts = bank.getClientAccounts(clientId);
        
        if (accounts.empty()) {
            std::cout << "У клиента нет счетов\n";
            return;
        }
        
        std::cout << "\n--- СЧЕТА КЛИЕНТА ---\n";
        for (const auto& account : accounts) {
            std::cout << account->getInfo() << "\n";
        }
    }
    
    void depositToAccount() {
        std::cout << "\n--- ПОПОЛНЕНИЕ СЧЕТА ---\n";
        int accountNumber = readInt("Номер счета: ");
        double amount = readDouble("Сумма: ");
        
        if (bank.deposit(accountNumber, amount)) {
            std::cout << "Счет успешно пополнен\n";
        } else {
            std::cout << "Ошибка при пополнении счета\n";
        }
    }
    
    void withdrawFromAccount() {
        std::cout << "\n--- СНЯТИЕ СО СЧЕТА ---\n";
        int accountNumber = readInt("Номер счета: ");
        double amount = readDouble("Сумма: ");
        
        if (bank.withdraw(accountNumber, amount)) {
            std::cout << "Средства успешно сняты\n";
        } else {
            std::cout << "Ошибка при снятии средств\n";
        }
    }
    
    void transferBetweenAccounts() {
        std::cout << "\n--- ПЕРЕВОД МЕЖДУ СЧЕТАМИ ---\n";
        int fromAccount = readInt("Счет-отправитель: ");
        int toAccount = readInt("Счет-получатель: ");
        double amount = readDouble("Сумма перевода: ");
        
        if (bank.transfer(fromAccount, toAccount, amount)) {
            std::cout << "Перевод успешно выполнен\n";
        } else {
            std::cout << "Ошибка при выполнении перевода\n";
        }
    }
};

int main() {
    setupConsole();
    
    Bank bank("Тинькофф");
    
    Address addr1("ул. Ленина, 10", "Москва", "101000", "Россия");
    Address addr2("пр. Мира, 25", "Санкт-Петербург", "190000", "Россия");
    
    int client1 = bank.addClient("Иван", "Иванов", addr1, ClientType::REGULAR);
    int client2 = bank.addClient("Петр", "Петров", addr2, ClientType::PREMIUM, 2, 5.0);
    
    bank.openAccount(client1, 10000.0, AccountType::CURRENT);
    bank.openAccount(client1, 50000.0, AccountType::SAVINGS);
    bank.openAccount(client2, 25000.0, AccountType::CURRENT);
    
    ConsoleUI ui(bank);
    ui.showMainMenu();
    
    return 0;
}
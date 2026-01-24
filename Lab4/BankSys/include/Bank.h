#ifndef BANK_H
#define BANK_H

#include <vector>
#include <memory>
#include <unordered_map>
#include <string>
#include "Client.h"
#include "PremiumClient.h"
#include "Account.h"
#include "Transaction.h"

class Bank {
private:
    std::string name;
    std::vector<std::unique_ptr<Client>> clients;
    std::vector<Account> accounts;
    std::vector<Transaction> transactions;
    
    std::unordered_map<int, int> clientIdToIndex;
    std::unordered_map<int, int> accountNumberToIndex;
    
    Client* findClientById(int id);
    Account* findAccountByNumber(int number);
    bool validateAmount(double amount) const;
    
public:
    Bank(const std::string& bankName);
    
    // Управление клиентами
    int addClient(const std::string& firstName, const std::string& lastName,
                  const Address& address, ClientType type = ClientType::REGULAR,
                  int premiumLevel = 0, double discountRate = 0.0);
    bool removeClient(int clientId);
    Client* getClient(int clientId);
    std::vector<Client*> getAllClients() const;
    
    // Управление счетами
    int openAccount(int clientId, double initialBalance = 0.0,
                    AccountType type = AccountType::CURRENT);
    bool closeAccount(int accountNumber);
    Account* getAccount(int accountNumber);
    std::vector<Account*> getClientAccounts(int clientId) const;
    
    // Банковские операции
    bool deposit(int accountNumber, double amount);
    bool withdraw(int accountNumber, double amount);
    bool transfer(int fromAccount, int toAccount, double amount);
    
    // Отчетность
    void displayBankInfo() const;
    void displayAllClients() const;
    void displayAllAccounts() const;
    void displayAllTransactions() const;
    void displayClientTransactions(int clientId) const;
    void displayAccountTransactions(int accountNumber) const;
    
    // Статистика
    int getActiveClientsCount() const;
    int getActiveAccountsCount() const;
    double getTotalBankBalance() const;
    
    // Поиск
    Client* searchClientByName(const std::string& name) const;
    std::vector<Account*> searchAccountsByType(AccountType type) const;
};

#endif
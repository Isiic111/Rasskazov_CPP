#include "Bank.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

Bank::Bank(const std::string& bankName) : name(bankName) {}

Client* Bank::findClientById(int id) {
    for (auto& client : clients) {
        if (client->getId() == id) {
            return client.get();
        }
    }
    return nullptr;
}

Account* Bank::findAccountByNumber(int number) {
    for (auto& account : accounts) {
        if (account.getAccountNumber() == number) {
            return &account;
        }
    }
    return nullptr;
}

bool Bank::validateAmount(double amount) const {
    return amount > 0;
}

int Bank::addClient(const std::string& firstName, const std::string& lastName,
                    const Address& address, ClientType type,
                    int premiumLevel, double discountRate) {
    std::unique_ptr<Client> client;
    
    if (type == ClientType::REGULAR) {
        client = std::make_unique<Client>(firstName, lastName, address, Date::getCurrentDate());
    } else {
        client = std::make_unique<PremiumClient>(firstName, lastName, address, 
                                                 Date::getCurrentDate(), premiumLevel, discountRate);
    }
    
    int clientId = client->getId();
    clientIdToIndex[clientId] = clients.size();
    clients.push_back(std::move(client));
    
    return clientId;
}

bool Bank::removeClient(int clientId) {
    for (const auto& account : accounts) {
        if (account.getClientId() == clientId && account.isActive()) {
            return false;
        }
    }
    
    auto it = std::remove_if(clients.begin(), clients.end(),
        [clientId](const std::unique_ptr<Client>& client) {
            return client->getId() == clientId;
        });
    
    if (it != clients.end()) {
        clients.erase(it, clients.end());
        clientIdToIndex.erase(clientId);
        return true;
    }
    
    return false;
}

Client* Bank::getClient(int clientId) {
    return findClientById(clientId);
}

std::vector<Client*> Bank::getAllClients() const {
    std::vector<Client*> result;
    for (const auto& client : clients) {
        result.push_back(client.get());
    }
    return result;
}

int Bank::openAccount(int clientId, double initialBalance, AccountType type) {
    Client* client = findClientById(clientId);
    if (!client) return -1;
    
    Account account(clientId, initialBalance, type, Date::getCurrentDate());
    int accountNumber = account.getAccountNumber();
    accountNumberToIndex[accountNumber] = accounts.size();
    accounts.push_back(account);
    
    return accountNumber;
}

bool Bank::closeAccount(int accountNumber) {
    Account* account = findAccountByNumber(accountNumber);
    if (!account || !account->isActive()) return false;
    
    if (account->getBalance() != 0.0) return false;
    
    account->setActive(false);
    return true;
}

Account* Bank::getAccount(int accountNumber) {
    return findAccountByNumber(accountNumber);
}

std::vector<Account*> Bank::getClientAccounts(int clientId) const {
    std::vector<Account*> result;
    for (const auto& account : accounts) {
        if (account.getClientId() == clientId) {
            result.push_back(const_cast<Account*>(&account));
        }
    }
    return result;
}

bool Bank::deposit(int accountNumber, double amount) {
    if (!validateAmount(amount)) return false;
    
    Account* account = findAccountByNumber(accountNumber);
    if (!account || !account->isActive()) return false;
    
    bool success = account->deposit(amount);
    if (success) {
        transactions.push_back(Transaction(accountNumber, accountNumber, amount, TransactionType::DEPOSIT));
    }
    return success;
}

bool Bank::withdraw(int accountNumber, double amount) {
    if (!validateAmount(amount)) return false;
    
    Account* account = findAccountByNumber(accountNumber);
    if (!account || !account->isActive()) return false;
    
    bool success = account->withdraw(amount);
    if (success) {
        transactions.push_back(Transaction(accountNumber, accountNumber, amount, TransactionType::WITHDRAWAL));
    }
    return success;
}

bool Bank::transfer(int fromAccount, int toAccount, double amount) {
    if (!validateAmount(amount)) return false;
    
    Account* from = findAccountByNumber(fromAccount);
    Account* to = findAccountByNumber(toAccount);
    
    if (!from || !to || !from->isActive() || !to->isActive()) return false;
    
    bool success = from->transfer(*to, amount);
    if (success) {
        transactions.push_back(Transaction(fromAccount, toAccount, amount, TransactionType::TRANSFER));
    }
    return success;
}

void Bank::displayBankInfo() const {
    std::cout << "\n=== ИНФОРМАЦИЯ О БАНКЕ ===\n";
    std::cout << "Название: " << name << "\n";
    std::cout << "Всего клиентов: " << clients.size() << "\n";
    std::cout << "Всего счетов: " << accounts.size() << "\n";
    std::cout << "Всего транзакций: " << transactions.size() << "\n";
    
    double totalBalance = 0.0;
    for (const auto& account : accounts) {
        if (account.isActive()) {
            totalBalance += account.getBalance();
        }
    }
    std::cout << "Общий баланс: " << std::fixed << std::setprecision(2) << totalBalance << "\n";
}

void Bank::displayAllClients() const {
    std::cout << "\n=== ВСЕ КЛИЕНТЫ ===\n";
    if (clients.empty()) {
        std::cout << "Клиентов нет\n";
        return;
    }
    
    for (const auto& client : clients) {
        client->displayInfo();
        std::cout << "---\n";
    }
}

void Bank::displayAllAccounts() const {
    std::cout << "\n=== ВСЕ СЧЕТА ===\n";
    if (accounts.empty()) {
        std::cout << "Счетов нет\n";
        return;
    }
    
    for (const auto& account : accounts) {
        std::cout << account.getInfo() << "\n";
    }
}

void Bank::displayAllTransactions() const {
    std::cout << "\n=== ВСЕ ТРАНЗАКЦИИ ===\n";
    if (transactions.empty()) {
        std::cout << "Транзакций нет\n";
        return;
    }
    
    for (const auto& transaction : transactions) {
        std::cout << transaction.getInfo() << "\n";
    }
}

void Bank::displayClientTransactions(int clientId) const {
    std::cout << "\n=== ТРАНЗАКЦИИ КЛИЕНТА ===\n";
    auto clientAccounts = getClientAccounts(clientId);
    if (clientAccounts.empty()) {
        std::cout << "У клиента нет счетов\n";
        return;
    }
    
    bool found = false;
    for (const auto& transaction : transactions) {
        int from = transaction.getFromAccount();
        int to = transaction.getToAccount();
        
        for (const auto& account : clientAccounts) {
            if (account->getAccountNumber() == from || account->getAccountNumber() == to) {
                std::cout << transaction.getInfo() << "\n";
                found = true;
                break;
            }
        }
    }
    
    if (!found) {
        std::cout << "Транзакций не найдено\n";
    }
}

int Bank::getActiveClientsCount() const { return clients.size(); }
int Bank::getActiveAccountsCount() const { 
    int count = 0;
    for (const auto& account : accounts) {
        if (account.isActive()) count++;
    }
    return count;
}
double Bank::getTotalBankBalance() const {
    double total = 0.0;
    for (const auto& account : accounts) {
        if (account.isActive()) {
            total += account.getBalance();
        }
    }
    return total;
}
Client* Bank::searchClientByName(const std::string& name) const { return nullptr; }
std::vector<Account*> Bank::searchAccountsByType(AccountType type) const { return {}; }
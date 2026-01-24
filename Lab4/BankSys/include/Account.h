#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Date.h"
#include "enums.h"
#include <string>

class Account {
private:
    int accountNumber;
    int clientId;
    double balance;
    AccountType type;
    Date openingDate;
    bool active;
    
    static int accountCounter;
    
public:
    Account();
    Account(int clientId, double initialBalance, 
            AccountType accType, const Date& openDate);
    
    int getAccountNumber() const { return accountNumber; }
    int getClientId() const { return clientId; }
    double getBalance() const { return balance; }
    AccountType getType() const { return type; }
    Date getOpeningDate() const { return openingDate; }
    bool isActive() const { return active; }
    
    void setClientId(int id) { clientId = id; }
    void setActive(bool act) { active = act; }
    
    bool deposit(double amount);
    bool withdraw(double amount);
    bool transfer(Account& target, double amount);
    
    std::string getTypeString() const;
    std::string getInfo() const;
    
    static int getTotalAccounts() { return accountCounter; }
    static int generateAccountNumber();
    
    bool operator==(const Account& other) const {
        return accountNumber == other.accountNumber;
    }
};

#endif
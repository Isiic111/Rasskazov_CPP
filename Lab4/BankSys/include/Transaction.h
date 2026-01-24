#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Date.h"
#include "enums.h"
#include <string>

class Transaction {
private:
    int transactionId;
    int fromAccount;
    int toAccount;
    double amount;
    Date transactionDate;
    TransactionType type;
    
    static int transactionCounter;
    
public:
    Transaction(); // Конструктор по умолчанию
    Transaction(int from, int to, double amt, TransactionType tType);
    
    int getId() const { return transactionId; }
    int getFromAccount() const { return fromAccount; }
    int getToAccount() const { return toAccount; }
    double getAmount() const { return amount; }
    Date getTransactionDate() const { return transactionDate; }
    TransactionType getType() const { return type; }
    
    std::string getTypeString() const;
    std::string getInfo() const;
    
    static int getTotalTransactions() { return transactionCounter; }
};

#endif
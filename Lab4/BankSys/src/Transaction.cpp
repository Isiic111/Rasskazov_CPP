#include "Transaction.h"
#include <sstream>
#include <iomanip>

int Transaction::transactionCounter = 0;

Transaction::Transaction() 
    : transactionId(++transactionCounter), fromAccount(0), toAccount(0), 
      amount(0.0), type(TransactionType::DEPOSIT) {
    // Дата устанавливается автоматически
}

Transaction::Transaction(int from, int to, double amt, TransactionType tType)
    : transactionId(++transactionCounter), 
      fromAccount(from), 
      toAccount(to),
      amount(amt), 
      transactionDate(Date::getCurrentDate()), // Текущая дата
      type(tType) {}

std::string Transaction::getTypeString() const {
    switch (type) {
        case TransactionType::DEPOSIT: return "Пополнение";
        case TransactionType::WITHDRAWAL: return "Снятие";
        case TransactionType::TRANSFER: return "Перевод";
        default: return "Неизвестно";
    }
}

std::string Transaction::getInfo() const {
    std::ostringstream oss;
    oss << "Транзакция #" << transactionId
        << ", Тип: " << getTypeString()
        << ", Сумма: " << std::fixed << std::setprecision(2) << amount
        << ", От счета: " << fromAccount
        << ", К счету: " << toAccount
        << ", Дата: " << transactionDate.toString();
    return oss.str();
}
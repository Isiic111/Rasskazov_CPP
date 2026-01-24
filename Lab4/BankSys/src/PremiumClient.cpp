#include "PremiumClient.h"
#include <iostream>
#include <sstream>
#include <iomanip>

PremiumClient::PremiumClient() : premiumLevel(1), discountRate(0.0) {
    type = ClientType::PREMIUM;
}

PremiumClient::PremiumClient(const std::string& fName, const std::string& lName,
                           const Address& addr, const Date& regDate,
                           int level, double discount)
    : Client(fName, lName, addr, regDate), premiumLevel(level), discountRate(discount) {
    type = ClientType::PREMIUM;
}

void PremiumClient::displayInfo() const {
    Client::displayInfo();
    std::cout << "Уровень премиум: " << premiumLevel << "\n";
    std::cout << "Скидка: " << std::fixed << std::setprecision(2) << discountRate << "%\n";
}

std::string PremiumClient::getFullInfo() const {
    std::ostringstream oss;
    oss << Client::getFullInfo()
        << ", Уровень премиум: " << premiumLevel
        << ", Скидка: " << std::fixed << std::setprecision(2) << discountRate << "%";
    return oss.str();
}

double PremiumClient::calculateTransactionFee(double amount) const {
    return amount * (1.0 - discountRate / 100.0);
}
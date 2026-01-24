#ifndef PREMIUM_CLIENT_H
#define PREMIUM_CLIENT_H

#include "Client.h"

class PremiumClient : public Client {
private:
    int premiumLevel;
    double discountRate;
    
public:
    PremiumClient();
    PremiumClient(const std::string& fName, const std::string& lName,
                  const Address& addr, const Date& regDate,
                  int level, double discount);
    
    int getPremiumLevel() const { return premiumLevel; }
    double getDiscountRate() const { return discountRate; }
    
    void setPremiumLevel(int level) { premiumLevel = level; }
    void setDiscountRate(double rate) { discountRate = rate; }
    
    void displayInfo() const override;
    std::string getFullInfo() const override;
    
    double calculateTransactionFee(double amount) const;
};

#endif
#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address {
private:
    std::string street;
    std::string city;
    std::string postalCode;
    std::string country;
    
public:
    Address();
    Address(const std::string& st, const std::string& ct, 
            const std::string& pc, const std::string& co);
    
    std::string getStreet() const { return street; }
    std::string getCity() const { return city; }
    std::string getPostalCode() const { return postalCode; }
    std::string getCountry() const { return country; }
    
    void setStreet(const std::string& st) { street = st; }
    void setCity(const std::string& ct) { city = ct; }
    void setPostalCode(const std::string& pc) { postalCode = pc; }
    void setCountry(const std::string& co) { country = co; }
    
    std::string toString() const;
};

#endif
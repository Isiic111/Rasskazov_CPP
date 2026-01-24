#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "Address.h"
#include "Date.h"
#include "enums.h"

class Client {
protected:
    int id;
    std::string firstName;
    std::string lastName;
    Address address;
    Date registrationDate;
    ClientType type;
    
    static int clientCounter;
    
public:
    Client();
    Client(const std::string& fName, const std::string& lName, 
           const Address& addr, const Date& regDate);
    virtual ~Client() = default;
    
    int getId() const { return id; }
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    Address getAddress() const { return address; }
    Date getRegistrationDate() const { return registrationDate; }
    ClientType getType() const { return type; }
    
    void setFirstName(const std::string& fName) { firstName = fName; }
    void setLastName(const std::string& lName) { lastName = lName; }
    void setAddress(const Address& addr) { address = addr; }
    
    virtual void displayInfo() const;
    virtual std::string getFullInfo() const;
    
    static int getTotalClients() { return clientCounter; }
    
    bool operator==(const Client& other) const {
        return id == other.id;
    }
};

#endif
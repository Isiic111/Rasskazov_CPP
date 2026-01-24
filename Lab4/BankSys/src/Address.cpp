#include "Address.h"

Address::Address() : street(""), city(""), postalCode(""), country("") {}

Address::Address(const std::string& st, const std::string& ct, 
                 const std::string& pc, const std::string& co)
    : street(st), city(ct), postalCode(pc), country(co) {}

std::string Address::toString() const {
    return street + ", " + city + ", " + postalCode + ", " + country;
}
//
// Created by Ewelina Szeliga on 15.04.2022.
//

#ifndef CUSTOMER_SERVICES_CUSTOMER_H
#define CUSTOMER_SERVICES_CUSTOMER_H


#include <string>
#include <ctime>

class Customer {
    std::string name;
    int VATIdentyficationNumber;
    tm creationDate;
    std::string address;

public:
    Customer(const std::string &name, int vatIdentyficationNumber, const std::string &address);

    const std::string &getName() const;

    int getVatIdentyficationNumber() const;

    tm getCreationDate() const;

    const std::string &getAddress() const;
};

#endif //CUSTOMER_SERVICES_CUSTOMER_H

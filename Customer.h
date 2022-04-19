//
// Created by Ewelina Szeliga on 15.04.2022.
//

#ifndef CUSTOMER_SERVICES_CUSTOMER_H
#define CUSTOMER_SERVICES_CUSTOMER_H


#include <string>
#include <ctime>
//#include "CustomerContainer.h"

class Customer {
    std::string name;
    std::string VATIdentyficationNumber;
    tm creationDate;
    std::string address;

public:
    Customer(const std::string &name, std::string vatIdentyficationNumber, const std::string &address);

    const std::string &getName() const;

    const std::string &getVatIdentyficationNumber() const;

    tm getCreationDate() const;

    const std::string &getAddress() const;

    friend class CustomerContainer;
};

std::ostream &operator<<(std::ostream &result, const Customer *customer);

#endif //CUSTOMER_SERVICES_CUSTOMER_H

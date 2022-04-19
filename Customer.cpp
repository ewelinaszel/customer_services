//
// Created by Ewelina Szeliga on 15.04.2022.
//

#include "Customer.h"
#include "CustomerContainer.h"
#include <iostream>

Customer::Customer(const std::string &name, std::string vatIdentyficationNumber, const std::string &address)
        : name(name), VATIdentyficationNumber(vatIdentyficationNumber), address(address) {
    time_t now = time(0);
    creationDate = *localtime(&now);
}

const std::string &Customer::getName() const {
    return name;
}

const std::string &Customer::getVatIdentyficationNumber() const {
    return VATIdentyficationNumber;
}

tm Customer::getCreationDate() const {
    return creationDate;
}

const std::string &Customer::getAddress() const {
    return address;
}

std::ostream &operator<<(std::ostream &result, const Customer *customer) {
    result << customer->getName();
    result << ", ";
    result << customer->getAddress() << ", ";
    result << customer->getVatIdentyficationNumber() << ", ";
    result << customer->getCreationDate().tm_mday << "-" << customer->getCreationDate().tm_mon << "-"
           << customer->getCreationDate().tm_year << " ";
    result << customer->getCreationDate().tm_hour << ":" << customer->getCreationDate().tm_min << ":"
           << customer->getCreationDate().tm_sec;
    return result;
}

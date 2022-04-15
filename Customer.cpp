//
// Created by Ewelina Szeliga on 15.04.2022.
//

#include "Customer.h"


Customer::Customer(const std::string &name, int vatIdentyficationNumber, const std::string &address)
        : name(name), VATIdentyficationNumber(vatIdentyficationNumber), address(address) {
    time_t now = time(0);
    creationDate = *localtime(&now);
}

const std::string &Customer::getName() const {
    return name;
}

int Customer::getVatIdentyficationNumber() const {
    return VATIdentyficationNumber;
}

tm Customer::getCreationDate() const {
    return creationDate;
}

const std::string &Customer::getAddress() const {
    return address;
}

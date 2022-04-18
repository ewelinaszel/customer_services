//
// Created by Ewelina Szeliga on 15.04.2022.
//

#include <stdexcept>
#include "CustomerContainer.h"


void CustomerContainer::addCustomer(Customer* customer) {
    customerList.push_back(customer);
}

void CustomerContainer::editCustomer(Customer *customer, std:: string name, int VATIdentyficationNumber, std::string address) {

    if (!contains(customer)){
        throw std::invalid_argument("Customer not avaliable in list. Cannot edit.");
    }

    customer->name = name;
    customer->address = address;
    customer->VATIdentyficationNumber = VATIdentyficationNumber;
}

void CustomerContainer::deleteCustomer(Customer *customer) {
    for (std::vector<Customer *>::iterator it = customerList.begin(); it != customerList.end(); ++it) {
        if (customer == *it) {
            customerList.erase(it);
        }
    }
}

const std::vector<Customer *> &CustomerContainer::getCustomerList() const {
    return customerList;
}

bool CustomerContainer::contains(Customer *customer) {
    for (std::vector<Customer *>::iterator it = customerList.begin(); it != customerList.end(); ++it) {
        if (customer == *it) {
            return true;
        }
    }
    return false;
}

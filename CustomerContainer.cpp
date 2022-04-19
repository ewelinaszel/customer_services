//
// Created by Ewelina Szeliga on 15.04.2022.
//

#include <stdexcept>
#include "CustomerContainer.h"
#include "Customer.h"


void CustomerContainer::addCustomer(Customer* customer) {
    if (repeats(customer)){
        throw std::invalid_argument("VATIdentyficationNumber exists. Cannot add customer.");
    }
    customerList.push_back(customer);
}

void CustomerContainer::editCustomer(Customer *customer, std:: string name, std::string VATIdentyficationNumber, std::string address) {

    if (!contains(customer)){
        throw std::invalid_argument("Customer not avaliable in list. Cannot edit.");
    }

    if (!name.empty()) customer->name = name;
    if (!address.empty()) customer->address = address;
    if (!VATIdentyficationNumber.empty()) customer->VATIdentyficationNumber = VATIdentyficationNumber;
}

void CustomerContainer::deleteCustomer(Customer *customer) {
    for (std::vector<Customer *>::iterator it = customerList.begin(); it != customerList.end(); ++it) {
        if (customer == *it) {
            customerList.erase(it);
            return;
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

Customer *CustomerContainer::getCustomerAtIndex(int index) const {
    return customerList.at(index);
}

bool CustomerContainer::repeats(Customer* customer){
    for (std::vector<Customer *>::iterator it = customerList.begin(); it != customerList.end(); ++it) {
        if(customer->VATIdentyficationNumber == (*it)->VATIdentyficationNumber){
            return true;
        }
    }
    return false;
}
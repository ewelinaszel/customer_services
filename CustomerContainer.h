//
// Created by Ewelina Szeliga on 15.04.2022.
//

#ifndef CUSTOMER_SERVICES_CUSTOMERCONTAINER_H
#define CUSTOMER_SERVICES_CUSTOMERCONTAINER_H

#include <vector>
#include "Customer.h"


class CustomerContainer {
    std:: vector <Customer *> customerList;

    bool contains(Customer *customer);

public:

    void addCustomer(Customer *customer);

    void editCustomer(Customer *customer, std:: string name, std::string VATIdentyficationNumber, std::string address);

    void deleteCustomer(Customer *customer);

    const std::vector<Customer *> &getCustomerList() const;

    Customer* getCustomerAtIndex(int index) const;

    bool repeats(Customer* customer);


};


#endif //CUSTOMER_SERVICES_CUSTOMERCONTAINER_H

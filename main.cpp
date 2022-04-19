#include <iostream>
#include "CustomerContainer.h"


CustomerContainer customerContainer;

void showMenu(){
    std::cout << "MENU" << std::endl;
    std::cout << "[0]\tFinish" << std::endl;
    std::cout << "[1]\tList customers" << std::endl;
    std::cout << "[2]\tAdd customer" << std::endl;
    std::cout << "[3]\tEdit customer" << std::endl;
    std::cout << "[4]\tDelete customer" << std::endl;
}

void showCustomersList(){
    int index=0;
    for( auto it = customerContainer.getCustomerList().begin(); it != customerContainer.getCustomerList().end(); ++it ){
        Customer * c = *it;
        std::cout << "["<<index++<<"]\t" << c << std::endl;
    }
}

Customer* selectCustomer() {
    int index;
    showCustomersList();
    std::cout << "Select the number of customer: ";
    std::cin >> index;
    return customerContainer.getCustomerAtIndex(index);
}

int main() {
    bool isRunning = true;
    int choice;
    while (isRunning) {
        showMenu();

        std::string name;
        std::string address;
        std::string VATIdentyficationNumber;
        Customer* customer;

        std::cout << "Select number: ";
        std::cin >> choice;
        switch (choice) {
            case 0:
                isRunning = false;
                break;
            case 1:
                showCustomersList();
                break;
            case 2:
                std::cout << "Name: ";
                std::cin.ignore();
                std::getline(std::cin,name);
                std::cout<< "Address: ";
                std::getline(std::cin,address);
                std::cout<< "VATIdentyficationNumber: ";
                std::cin >> VATIdentyficationNumber;
                try {
                    customerContainer.addCustomer(new Customer(name, VATIdentyficationNumber, address));
                }
                catch (std::invalid_argument &e) {
                    std::cerr << e.what() << std::endl;
                }
                break;
            case 3:
                customer = selectCustomer();
                std::cout << "Name: ";
                std::cin.ignore();
                std::getline(std::cin,name);
                std::cout<< "Address: ";
                std::getline(std::cin,address);
                std::cout<< "VATIdentyficationNumber: ";
                std::cin >> VATIdentyficationNumber;

                try {
                    customerContainer.editCustomer(customer, name, VATIdentyficationNumber, address);
                }
                catch (std::invalid_argument &e) {
                    std::cerr << e.what() << std::endl;
                }
                break;
            case 4:
                customer = selectCustomer();
                customerContainer.deleteCustomer(customer);
                break;
            default:
                std::cout<<"Given number is wrong. Select number from 0 to 4"<<std::endl;
        }
    }

    return 0;
}
cmake_minimum_required(VERSION 3.20)
project(customer_services)

set(CMAKE_CXX_STANDARD 14)

add_executable(customer_services main.cpp Customer.cpp Customer.h CustomerContainer.cpp CustomerContainer.h)

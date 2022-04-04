/**
  Student Name: Alan Benitez
  File Name: Customer.hpp
  Assignment number 2

  This class is where I declare the variables and methods that I will be using in Customer.cpp,
  and is the header file
**/

#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
#include <queue>
#include <list>

class Customer{
private:
    float arrivalTime;
    float startOfServiceTime;
    float departureTime;
    float transactionTime;
    char type;
    
public:
    Customer(float arrivalTime);
    Customer(float arrivalTime, float transactionTime, float departureTime, char type);
    void SetTransactionTime(float transactionTime);
    float GetTransactionTime();
    float GetArrivalTime();
    char GetType();
    void SetDepartureTime(float time);
    float GetDepartureTime();
};
#endif 
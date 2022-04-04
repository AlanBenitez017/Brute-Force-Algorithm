/**
  Student Name: Alan Benitez
  File Name: Customer.cpp
  Assignment number 2

  This class is where I have my getters and setters for a customer, as well as overloaded constructors
**/

#include "Customer.hpp"

//Overloaded constructor
Customer::Customer(float arrivalTime){
    this->arrivalTime = arrivalTime;
    this->transactionTime = 0;
    this->departureTime = 0.00;
    this->type = 'A';
}

//Overloaded Constructor
Customer::Customer(float arrivalTime, float transTime, float departureTime, char type){
    this->arrivalTime = arrivalTime;
    this->transactionTime = transTime;
    this->departureTime = departureTime;
    this->type = type;
}

//transaction time getter
float Customer::GetTransactionTime(){
    return this->transactionTime;
}

//Transaction time setter
void Customer::SetTransactionTime(float transactionTime){
    this->transactionTime = transactionTime;
}

//Arrival time getter
float Customer::GetArrivalTime(){
    return this->arrivalTime;
}

//Type getter
char Customer::GetType(){
    return this->type;
}

//Departure time getter
float Customer::GetDepartureTime(){
    return this->departureTime;
}

//Departure time setter
void Customer::SetDepartureTime(float departureTime){
    this->departureTime = departureTime;
}
/**
  Student Name: Alan Benitez
  File Name: Calculations.cpp
  Assignment number 2

  This class is where I perform the calculations needed for the simulation
**/

#include <iostream>
#include "Calculations.hpp"
#include <math.h>
#include <random>

using namespace std;

//This method does the factorial
float Calculations::Factorial(float i){    
    if(i <= 1)
    {
        return 1;
    }
    else
    {
        return i * Factorial(i - 1);
    }
}

//This method calculates the percentIdleTime
float Calculations::percentIdleTime(float lambda, float M, float mu){
    float Po, sum, one = 0.0;
    one = lambda/mu;
    
    for(int i = 0; i <= M - 1; i++){
        sum = sum + (1/Factorial(i)) * pow(one, i);        
    }
    
    Po = 1 / (sum + (1/Factorial(M)) * pow(one, M) * ((M * mu))/(M*mu - lambda));        
    return Po;
}

//This method calculates the average number of people
float Calculations::avgNumOfPeople(float lambda, float M, float mu){
    float one, two, three, five, seven, nine;
    
    one = lambda * mu;
    two = pow(lambda / mu, M);
    three = one * two;
    five = pow((M * mu) - lambda, 2);
    seven = three / (Factorial(M-1) * five);
    nine = (seven * percentIdleTime(lambda, M, mu)) + (lambda/mu);
    
    return nine;
}

//This method calculates the average customer time
float Calculations::avgCustomerTime(float lambda, float M, float mu){
    return avgNumOfPeople(lambda, M, mu)/lambda;
}

//This method calculates the average number of customers in the queue
float Calculations::avgNumOfCustomersInQ(float lambda, float M, float mu){
    return avgNumOfPeople(lambda, M, mu) - (lambda/mu);
}

//This method calculates the average time that the customers will have to wait in the queue
float Calculations::avgTimeOfCustomersInQ(float lambda, float M, float mu){
    return avgNumOfCustomersInQ(lambda, M, mu)/ lambda;
}

//This method generates the next random interval
float Calculations::genNextRandomInterval(int avg){
    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); 
    float intTime = -1 * (1.0/avg) * log(r); 
    return intTime;
}

float Calculations::utilizationFactor(float lambda, float M, float mu){
    return lambda/(M*mu);
}



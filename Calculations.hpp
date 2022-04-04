/**
  Student Name: Alan Benitez
  File Name: Calculations.cpp
  Assignment number 2

  This class is the header of the Calculation.cpp class, where I declare the variables and methods
**/
#ifndef CALCULATIONS_HPP
#define CALCULATIONS_HPP
#include <math.h>

using namespace std;

class Calculations{
    private:
        
    public:

        float Factorial(float i);
        float percentIdleTime(float lambda, float M, float mu);
        float avgNumOfPeople(float lambda, float M, float mu);
        float avgCustomerTime(float lambda, float M, float mu);
        float avgNumOfCustomersInQ(float lambda, float M, float mu);
        float avgTimeOfCustomersInQ(float lambda, float M, float mu);
        float genNextRandomInterval(int avg);   
        float utilizationFactor(float lambda, float M, float mu);     
            
};
#endif 
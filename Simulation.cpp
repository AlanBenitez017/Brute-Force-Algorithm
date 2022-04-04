/**
  Student Name: Alan Benitez
  File Name: Simulation.cpp
  Assignment number 2

  This class is where I basically Run the code and do all the steps necessary to make the work done
**/
#include "Simulation.hpp"
#include "Customer.hpp"
#include "Calculations.hpp"
#include <iostream>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include <functional>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void Simulation::Run(){

    //Declaring some variables that will be used
    Calculations f;
    int n, mu;
    float lambda, M = 0.0;

    priority_queue<Customer *, vector<Customer *>, greater<Customer *>> priorityQueue;
    queue<Customer * > FIFO;
    
    cout << "Please enter the number of arrivals you wish to simulate: " << endl;
    cin >> n;

    cout << "Please enter the average arrivals in a time period: " << endl;
    cin >> lambda;
    
    cout << "Please enter the average number served in a time period: " << endl;
    cin >> mu;
    
    cout << "Please enter the number of service channels: " << endl;
    cin >> M;
    
    //Pushing Customers to the priority queue
    for(int i = 0; i < M; i++){
        Customer * c = new Customer(f.genNextRandomInterval(mu));
        priorityQueue.push(c);
    }
    
    //Creating more variables that I will be using to perform the simulation
    int serveCount = M;
    int processed = 0;
    float totalArriveTime;
    float totalProcessingTime;
    float totDepartTime;
    
    //The actual simulation
    cout << "Simulation begins" << endl;
    while(!priorityQueue.empty()){
        Customer * c = priorityQueue.top();
        priorityQueue.pop();
        float currTime = c->GetArrivalTime();
            if(c->GetType() == 'A'){
                if(serveCount > 0){
                    serveCount--;
                    c->SetTransactionTime(f.genNextRandomInterval(mu));
                    c->SetDepartureTime(currTime + c->GetTransactionTime());
                    Customer * departCust = new Customer(0, 0, c->GetDepartureTime(), 'D');
                    priorityQueue.push(departCust);
                    processed++;
                    totalArriveTime =  totalArriveTime + currTime;
                    totalProcessingTime = totalProcessingTime + c->GetTransactionTime();
                }
                else{
                    FIFO.push(c);
                    clientsWaiting--;
                }
            }
            else {
                serveCount++;
                if(!FIFO.empty()){
                    Customer * front = FIFO.front();
                    FIFO.pop();
                    front->SetTransactionTime(f.genNextRandomInterval(mu));
                    front->SetDepartureTime(currTime + front->GetTransactionTime());
                    Customer * dc = new Customer(0, 0,front->GetDepartureTime(),'D');
                    priorityQueue.push(dc);
                    serveCount--;
                    processed++;
                    totDepartTime = totDepartTime + front->GetDepartureTime();
                }   
            }
        if(processed < n && priorityQueue.size() < M){
            for(int i = 0; i < M; i++){
                Customer * c = new Customer(f.genNextRandomInterval(mu));
                priorityQueue.push(c);
            }
        }
    }

    //Final outputs to the console
    cout << "Simulation Ends" << endl << endl;
    cout << "Final Statistics:" << endl << endl;
    cout << "Total number of people processed: " << processed << endl; 

    cout << "Analytical Model" << endl;
    cout << "   Po = " << f.percentIdleTime(lambda, M, mu) << endl;
    cout << "   L = " << f.avgNumOfPeople(lambda, M, mu) << endl;
    cout << "   W = " << f.avgCustomerTime(lambda, M, mu) << endl;
    cout << "   Lq = " << fixed << setprecision(3) << f.avgNumOfCustomersInQ(lambda, M, mu) << endl;
    cout << "   Wq = " << fixed << setprecision(4) << f.avgTimeOfCustomersInQ(lambda, M, mu) << endl;
    cout << "   Rho = " << f.utilizationFactor(lambda, M, mu) << endl;

    cout << "Simulation Model" << endl;
    cout << "Probability of having to wait for service: " << (clientsWaiting/static_cast<float>(processed)) << endl;
    cout << "   Po = " << fixed << setprecision(1) << (totalArriveTime/processed) << endl;
    cout << "   W = " << fixed << setprecision(3) << f.avgCustomerTime(lambda, M, mu) << endl;
    cout << "   Wq = " << fixed << setprecision(4) << f.avgTimeOfCustomersInQ(lambda, M, mu) << endl;
    cout << "   Rho = " << lambda/(M*mu) << endl;

}

/* 
   File:   main
   Author: Tejash Bhakta
   Created on November 14, 2016, 10:00 AM
   Purpose: Calculate gross pay for an employee from the array 
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declaration of Variables
    short emp=7;
    long int empId[emp]={5658845, 4520125, 7895122, 
                       8777541, 8451277, 1302850, 7580489};
    int hours[emp];
    float payRate[emp], wages[emp];
    
    //Display the id number and input the number of hours worked against it
    cout<<"Enter the hours worked and pay rate of the employees based on their eid"<<endl;
    cout<<"Eid\t hours worked \tPay Rate"<<endl;
    for(int i=0 ; i<emp; i++){
        cout<<empId[i]<<":  ";
        cin>>hours[i]>>payRate[i];
    }
    
    //Process values -> Map inputs to Outputs
    for(int i=0; i<emp; i++){
        wages[i]=hours[i]*payRate[i];
    }
    
    //Display Output
    cout<<"------Payroll------"<<endl;
    cout<<"Eid \t Wages"<<endl;
    for(int i=0; i<emp; i++){
        cout<<empId[i]<<"  "<<wages[i]<<endl;
    }
    //Exit Program
    return 0;
}

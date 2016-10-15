/* 
   File:   main
   Author: Tejash Bhakta
   Created on October 15, 2016, 9:41 AM
   Purpose: To calculate the membership fees in next 6 years 
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>    //Formatting
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const int PERCENT=100; //Conversion to percentage
//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    float memPrice, rateInc=4.0f, prcInc; //Membership Price, Rate of increase, Price Increased
    short numYrs;                 //Number of years
    
    //Input number and validation
    do{
        cout<<"Enter the price of membership : ";
        cin>>memPrice;
        
        cout<<"Number of years the price rate increase : ";
        cin>>numYrs;
        
    }
    while(numYrs<=0 || memPrice<=0);
    
    //Process values 
        for(int i=1; i<=numYrs; i++){
            prcInc=(memPrice*rateInc/PERCENT)+memPrice;
            cout<<fixed<<setprecision(2);
            cout<<"The price after "<<i<<" year(s) at the rate of "<<rateInc<<"% would be $"<<setw(8)<<prcInc<<endl;
            memPrice=prcInc;
        }
    

    //Exit Program
    return 0;
}

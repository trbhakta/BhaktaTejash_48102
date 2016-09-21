/* 
   File:   main
   Author: Tejash Bhakta
   Created on September 19, 2016, 9:10 AM
   Purpose: Calculate the Annual Pay 
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>    //Foramt Library
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
 
//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    float payAmt, weeks, payPrd, anlPay;
    //Input values
    cout<<"Enter the amount paid each pay period."<<endl;
    cin>>payAmt;
    cout<<"Enter number of pay period."<<endl;
    cin>>payPrd;
    //Process values -> Map inputs to Outputs
    
 
    anlPay = payPrd*payAmt;
    //Display Output
    cout<<"Amount paid in each pay Period = $"<<payAmt<<endl;
    cout<<"Number of Pay Periods          =  "<<payPrd<<endl;
    cout<<"Annual Pay                     = $"<<setw(10)<<showpoint<<anlPay<<endl;
    

    //Exit Program
    return 0;
}
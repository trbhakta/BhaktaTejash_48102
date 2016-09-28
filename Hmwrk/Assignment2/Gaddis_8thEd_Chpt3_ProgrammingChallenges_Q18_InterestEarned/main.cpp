/* 
   File:   main
   Author: Tejash Bhakta
   Created on September 25, 2016, 9:41 AM
   Purpose:  To calculate amount after the input of Principle,Rate and number of timers compounded
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>    //Formatting
#include <cMath>      //Math Library
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const int PERCENT=100; // Conversion of percentage
//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    float prncple, rate, a, intAmt,savAmt; //Principle, Rate of Interest, interest in amount, Final Amount
    unsigned short timeCmpd;  // Times Compounded
    
    //Input values
    
    cout<<"Enter the Principle deposited"<<endl;
    cin>>prncple;
    cout<<"Enter the interest rate in percent"<<endl;
    cin>>rate;
    cout<<"Enter number of times the interest is Compounded"<<endl;
    cin>>timeCmpd;
    
    //Process values -> Map inputs to Outputs
    
    savAmt= prncple*pow(1+(rate/(PERCENT*timeCmpd)),timeCmpd); //Calculating final amount after one year of deposit
    intAmt= savAmt-prncple;                                    //Subtracting final amount with principle gives how much interest paid
    
    //Display Output

    cout<<"Interest Rate      : "<<setw(10)<<rate<<" %"<<endl;
    cout<<"Times Compounded   : $"<<setw(10)<<timeCmpd<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"Principle          : $"<<setw(10)<<prncple<<endl;
    cout<<"Interest           : $"<<setw(10)<<intAmt<<endl;
    cout<<"Amount in Savings  : $"<<setw(10)<<savAmt<<endl;
   
    //Exit Program
    return 0;
}
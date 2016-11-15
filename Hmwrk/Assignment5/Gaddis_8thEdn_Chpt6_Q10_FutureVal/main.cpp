/* 
 * File:   main.cpp
 * Author: Tejash Bhakta
 * Created on November 4, 2016, 9:07 AM
 * Purpose:  Future Value
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
#include <cMath>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
const float PERCENT=100.0f;

//Function Prototypes Here
float futVal(float, float, int);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float prstAmt, mnthRte;
    int nMonths;
    
    //Input or initialize values Here
    cout<<"Input the Amount cuurently in your account:"<<endl;
    cin>>prstAmt;
    cout<<"What is the Interest Rate?"<<endl;
    cin>>mnthRte;
    cout<<"Enter the months for which money to be held in the bank"<<endl;
    cin>>nMonths;
    
    //Process and Output
    cout<<"---The Future Value---"<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"Current Amount in the bank: $ "<<setw(7)<<prstAmt<<endl;
    cout<<"Monthly Rate              :   "<<setw(7)<<mnthRte<<"%"<<endl;
    cout<<"Number of Months          :   "<<setw(7)<<nMonths<<endl;
    cout<<"The Future Value          : $ "<<setw(7)<<futVal(prstAmt,mnthRte,nMonths)<<endl;    

    //Exit
    return 0;
}

//Function Name futVal
//Input present amount, month rate, and number of months
//Ouput the future value
float futVal(float amount, float rate, int months){
    return amount*pow(1+(rate/PERCENT),months);
}
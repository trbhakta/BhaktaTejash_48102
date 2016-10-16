/* 
   File:   main
   Author: Tejash Bhakta
   Created on October 12, 2016, 9:41 AM
   Purpose:  Computes the annual after-tax cost of anew house
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>    //Formatting
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const int PERCENT=100;  //Conversion of percentage
//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
  float prcHouse, downPmt,              //Price of House, Down Payment
        loanBal,  loanInt, anlMort,     //Initial Loan Payment, Interest, Annual mortgage
        taxSave, annualCst;             //Tax Savings, Annual Cost
  char yn;  
    //Purpose of Program 
  cout<<"This program calculates the annual cost of your house after tax cost"<<endl;
    
    
    //All calculations
    do{
       //Validations 
        do{
      cout<<"Input the price of your house"<<endl<<"$ ";
      cin>>prcHouse;
      
      cout<<"Input your Down Payment"<<endl<<"$ ";
      cin>>downPmt;
    }while(prcHouse<=0);
        loanBal=prcHouse-downPmt;         //Calculation of initial loan payment
        loanInt=6*loanBal/100;            //Loan Interest
        taxSave=35*loanInt/PERCENT;       //Calculation of tax savings
        anlMort=(3*loanBal/100)+loanInt;  //Annual Mortgage
        annualCst=anlMort-taxSave;        //Annual Cost
       
        //Output the values and calculation
       cout<<fixed<<setprecision(2);
       cout<<"The price of house   = $"<<setw(8)<<prcHouse<<endl;
       cout<<"Down Payment         = $"<<setw(8)<<downPmt<<endl;
       cout<<"Initial Loan Balance = $"<<setw(8)<<loanBal<<endl;
       cout<<"Tax Savings          = $"<<setw(8)<<taxSave<<endl;
       cout<<"Loan Interest Amount = $"<<setw(8)<<loanInt<<endl;
       cout<<"Annual Mortgage      = $"<<setw(8)<<anlMort<<endl;
       cout<<"Annual Cost after tax= $"<<setw(8)<<annualCst<<endl;
       
       //Continue of program
      
      cout<<endl<<"Do you wish to compute the cost again?(y/n)"<<endl;
      cin>>yn;
    }while(yn=='y' || yn=='Y');  
    
    //Display Output

    //Exit Program
    return 0;
}

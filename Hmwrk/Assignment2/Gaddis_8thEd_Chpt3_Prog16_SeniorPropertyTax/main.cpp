/* 
   File:   main
   Author: Tejash Bhakta
   Created on September 22, 2016, 11:55 AM
   Purpose: To calculate property tax for senior citizens with an exemption of $5000, 
            in addition to allowance of quarterly payments for Madison County
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>    //Formatting Library
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

const int EXEMPT = 5000; //Exemption of $5000 dollar on assessed value
const int TAX = 60;      //Property Tax on assessment value is 60%
const int PERCENT=100;   //Percentage Conversion

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {

    //Declaration of Variables

    float prcPrty, curRate, asmVal, prptTax, qtrPmt; // Price of Property, current Rate, Assessment Value, Quarterly Payment     
    //Input values
    
    cout<<"Enter the actual value of your property"<<endl;
    cin>>prcPrty;
    
    cout<<"Enter the current tax rate for each 100$ of assessed value"<<endl;
    cin>>curRate;
    
    //Process values -> Map inputs to Outputs
    
    asmVal = (prcPrty * TAX / PERCENT) - EXEMPT; 
    prptTax = (asmVal/100)*curRate;
    qtrPmt  = prptTax/4;
    
    //Display Output
    cout<<setprecision(2)<<fixed;
    cout<<"The actual price of your property = $"<<setw(10)<<prcPrty<<endl;
    cout<<"Current Tax Rate                  = $"<<setw(10)<<curRate<<endl;
    
    cout<<"Assessment Value of property      = $"<<setw(10)<<(prcPrty * TAX / PERCENT)<<endl;
    cout<<"Exemption on Assessed value       = $"<<setw(10)<<EXEMPT<<endl;
    cout<<"Assessment Value after deduction  = $"<<setw(10)<<asmVal<<endl;
    cout<<"Your Property Tax would be        = $"<<setw(10)<<prptTax<<endl;
    cout<<"Quarterly Payment of              = $"<<setw(10)<<qtrPmt<<endl;
    
    //Exit Program
    return 0;
}
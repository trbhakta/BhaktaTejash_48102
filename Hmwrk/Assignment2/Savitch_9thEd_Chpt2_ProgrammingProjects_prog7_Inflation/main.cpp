/* 
   File:   main
   Author: Tejash Bhakta
   Created on September 23, 2016, 9:41 AM
   Purpose: Change the rate of an item according to inflation rate over following years 
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>    //Formatting Library
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const int PERCENT =100; //Conversion Percent
//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    float rateInf, costPrdt, prcInc, Budgt; //Rate of Inflation, Cost of Product, Price Increased, Budgt
    int numItms, numYrs;     //Quantity of items, Number of years
    
    //Input values
    
    cout<<"Enter the quantity of the item."<<endl;
    cin>>numItms;
    
    cout<<"Enter the cost of the product in present year"<<endl;
    cin>>costPrdt;
    
    cout<<"Enter the inflation rate in percentage"<<endl;
    cin>>rateInf;
   
    cout<<"Enter number of years after which the items need to be purchased"<<endl;
    cin>>numYrs;
    
    //Process values -> Map inputs to Outputs
    int i=numYrs;  //Duplicating Number of Years
    float dupCost=costPrdt; //Duplicating Product Cost
    
    while (i > 0){
        prcInc = (dupCost*rateInf/PERCENT) + dupCost;
        dupCost = prcInc;
        i--;
    }
    Budgt=numItms*prcInc;
    
    //Display Output
    
    cout<<"Price of the product in present year = $"<<setw(8)<<costPrdt<<endl;
    cout<<"Quantity of Product                  =  "<<setw(8)<<numItms<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"Rate of Inflation                    =  "<<setw(8)<<rateInf<<"%"<<endl;
    cout<<"The Price of the product after "<<numYrs<<" years   = $"<<setw(8)<<prcInc<<endl;
    cout<<"Total Budget for "<<numItms<<"years = $"<<setw(8)<<Budgt<<endl;
    //Exit Program
    return 0;
}
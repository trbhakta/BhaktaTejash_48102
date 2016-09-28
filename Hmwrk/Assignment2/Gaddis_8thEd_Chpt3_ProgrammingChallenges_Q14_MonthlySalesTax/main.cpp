/* 
   File:   main
   Author: Tejash Bhakta
   Created on September 25, 2016, 11:41 AM
   Purpose: To calculate the monthly sales tax of a retail company 
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>    //Formatting
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const int PERCENT=100;  //Conversion percentage
//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    string         month;          //To input Month
    unsigned short year;
    float          totAmt, sales, cntySales, steSales, totSales,  //Total amount collected, county sales tax, state sales tax, total sales tax 
                   cntyTax=2.0f, steTax=4.0f, totTax=6.0f; //County Tax, State Tax, Total Tax  
    //Input values
    cout<<"Enter the month to see the Sales Report"<<endl;
    cin>>month;
    
    cout<<"Enter the year"<<endl;
    cin>>year;
    
    cout<<"Input the total amount collected at the register"<<endl;
    cin>>totAmt;
    
    //Process values -> Map inputs to Outputs
    
    sales     = totAmt/1.06;
    cntySales = sales*cntyTax/PERCENT;
    steSales  = sales*steTax/PERCENT;
    
            
    //Display Output
    cout<<"Month: "<<month<<"   Year: "<<year<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"Total Collected : $ "<<setw(8)<<totAmt<<endl;;
    cout<<"Sales           : $ "<<setw(8)<<sales<<endl;
    cout<<"County Sales Tax: $ "<<setw(8)<<cntySales<<endl;
    cout<<"State Sales Tax : $ "<<setw(8)<<steSales<<endl;
    cout<<"Total Sales Tax : $ "<<setw(8)<<cntySales+steSales<<endl;
    //Exit Program
    return 0;
}

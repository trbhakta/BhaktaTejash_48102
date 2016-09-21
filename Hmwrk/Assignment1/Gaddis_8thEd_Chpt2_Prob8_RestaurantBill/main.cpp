/* 
   File:   main
   Author: Tejash Bhakta
   Created on August 29, 2016, 5:00 PM
   Purpose: Calculate the subtotal and total sum of items with tax. 
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>     //Format Librabry
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const float TAX=7.0f; //Sales Tax = 7%
const float PERCENT=100; //Conversion to Percentage
//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    float itm1,itm2, itm3, itm4, itm5;
    float subtot, total;
    //Input values
    itm1= 15.95;
    itm2= 24.95;
    itm3= 6.95;
    itm4= 12.95;
    itm5= 3.95; 
    //Process values -> Map inputs to Outputs
    subtot= itm1+itm2+itm3+itm4+itm5;
    total= subtot+(subtot*TAX/PERCENT);
    //Display Output
    cout<<"The Price of item 1 = $"<<itm1<<endl;
    cout<<"The Price of item 2 = $"<<itm2<<endl;
    cout<<"The Price of item 3 = $"<<itm3<<endl;
    cout<<"The Price of item 4 = $"<<itm4<<endl;
    cout<<"The Price of item 5 = $"<<itm5<<endl;
    cout<<"Subtotal            = $"<<subtot<<endl;
    cout<<"Sales Tax           = "<<TAX<<"%"<<endl;
    cout<<setprecision(4)<<"Total               = $"<<total<<endl;
    //Exit Program
    return 0;
}

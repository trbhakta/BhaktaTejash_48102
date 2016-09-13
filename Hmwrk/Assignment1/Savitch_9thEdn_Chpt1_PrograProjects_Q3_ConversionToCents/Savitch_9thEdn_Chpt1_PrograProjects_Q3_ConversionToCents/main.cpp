/* 
   File:   main
   Author: Tejash Bhakta
   Created on September 9, 2016, 10:15 AM
   Purpose: Input no. of Quarters, nickels and dimes, and then converting to cents  
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const char QUARTER=25;
const char NICKEL =5;
const char DIME=10;
//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    short Num_Quar, Num_Nickel, Num_Dime;
    int totCents, Quar_Cents, Nick_Cents, Dime_Cents;
    //Input values
    cout<<"How many Dimes do you have?"<<endl;
    cin>>Num_Dime;
    cout<<"How many Quarters do you have?"<<endl;
    cin>>Num_Quar;
     cout<<"How many Nickel do you have?"<<endl;
    cin>>Num_Nickel;
    //Process values -> Map inputs to Outputs
    Quar_Cents= QUARTER*Num_Quar;
    Nick_Cents= NICKEL*Num_Nickel;
    Dime_Cents= DIME*Num_Dime;
    totCents= Quar_Cents + Nick_Cents + Dime_Cents;
    
    //Display Output
    cout<<"You have "<<Num_Dime<<" Dime(s)"<<endl;
    cout<<"You have "<<Num_Quar<<" Quarter(s)"<<endl;
    cout<<"You have "<<Num_Nickel<<" Nickel(s)"<<endl;
    cout<<"The coins are worth "<<totCents<<" cents"<<endl;
    //Exit Program
    return 0;
}
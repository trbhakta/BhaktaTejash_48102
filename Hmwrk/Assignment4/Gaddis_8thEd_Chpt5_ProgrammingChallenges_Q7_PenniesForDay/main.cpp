/* 
   File:   main
   Author: Tejash Bhakta
   Created on October 15, 2016, 10:41 AM
   Purpose:  To calculate pennies when it doubles for each working day 
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    int numDays;    //no. of days worked
    int pennies=1;  //Total pennies starting with day 1
    long totPenny=0;// Total Pennies
    //Values and validations
    do{
        cout<<"Enter the number of days worked : ";
        cin>>numDays;
    }
    while(numDays<=0 || numDays>31);
    
    cout<<"Penny for Day 1  3 = 1"<<endl;
    //Calculating pennies for number of days worked
        for(int i=2; i<=numDays; i++){
            pennies*=2;
            cout<<"Pennies for Day "<<i<<" = "<<pennies<<endl;
            totPenny+=pennies;
        }
    //Display Output
    cout<<endl<<"Number of days worked = "<<numDays<<endl;
    cout<<"Total pennies altogether = "<<totPenny<<" pennies"<<endl;
    cout<<"which equals to $"<<totPenny/100<<" dollars and "<<totPenny%100<<" cents.";
    //Exit Program
    return 0;
}

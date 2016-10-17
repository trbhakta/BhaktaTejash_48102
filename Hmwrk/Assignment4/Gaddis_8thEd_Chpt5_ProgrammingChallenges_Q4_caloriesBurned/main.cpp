/* 
   File:   main
   Author: Tejash Bhakta
   Created on October 7, 2016, 9:41 AM
   Purpose: To calculate calories burned after 5, 10 ,15, 20, 25 and 30 minutes 
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>    //formatting
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    float calories, totCal;   //Calories in a minute , total calories
    int minutes;

    //Input calories per minute and total minutes
    do{
        cout<<"Enter the amount of calories burned in a minute"<<endl;
        cin>>calories;
        
        cout<<"Enter the number of minutes exercised"<<endl;
        cin>>minutes;
    }while(calories<0 || minutes<0);
    
    //Output the calories per minute
    cout<<"Amount of calories burned in a minute = "<<setw(6)<<calories<<" cal"<<endl;
    //Process the calories per every 5 min
        for(int i=5; i<=minutes; i+=5){
            totCal=calories*i;
            cout<<"Amount of calories burned in "<<i<<" mins ="<<setw(6)<<totCal<<" Cal"<<endl;
                       
        }
    
    //Display Output

    //Exit Program
    return 0;
}

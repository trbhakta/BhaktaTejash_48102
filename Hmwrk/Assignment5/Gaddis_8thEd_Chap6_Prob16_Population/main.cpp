/* 
   File:   main
   Author: Tejash Bhakta
   Created Nov 3, 2016, 12:00 PM
   Purpose:  Calculate population increased or decreased based on birth rate and death rate
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
int popln(int,float,float);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    int   pop, death, birth, years;//per year
    float bRate, dRate;
    
    //Input values
    cout<<"This program calculates the population as a function of time"<<endl;
    cout<<"Population?"<<endl;
    cin>>pop;
    cout<<"Birth Rate per year?"<<endl;
    cin>>birth;
    cout<<"Death Rate per year?"<<endl;
    cin>>death;
    cout<<"How many years to predict?"<<endl;
    cin>>years;
    
    //Process values -> Map inputs to Outputs
    bRate=1.0f*birth/pop;
    dRate=1.0f*death/pop;
    for(int year=1;year<=years;year++){
        pop=popln(pop,dRate,bRate);
        cout<<"Year "<<year<<" = population of "<<pop<<endl;
    }
    
    //Display Output

    //Exit Program
    return 0;
}

int popln(int pop,float death,float birth){
    return pop*(1+birth-death);
}
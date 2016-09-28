/* 
   File:   main
   Author: Tejash Bhakta
   Created on September 25, 2016, 9:41 PM
   Purpose: To find the sum of Negative, Positive and Total sum of input numbers 
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {

    //Declaration of Variables
    int i, inpNum, posSum=0, negSum=0, total=0;    //i for initializing, input number, positive sum, negative sum, total sum 
    
 
    //Process values -> Map inputs to Outputs
    while(i<=10){                    // Program runs ten times to input ten numbers
    cout<<"Enter any positive or negative number"<<endl;
    cin>>inpNum;
    
    if(inpNum>0){
        posSum=posSum+inpNum;       //if number is positive, this is store its sum
    }
    else{
        negSum=negSum+inpNum;       //if number is negative, this is store its sum    
    }
      total=total+inpNum;           //Total sum of all numbers
      i++;
    }
    //Display Output
    cout<<"Sum of all positive numbers inputted  : "<<posSum<<endl;
    cout<<"Sum of all negative numbers inputted  : "<<negSum<<endl;
    cout<<"Total sum of all numbers              : "<<total<<endl;

    //Exit Program
    return 0;
}

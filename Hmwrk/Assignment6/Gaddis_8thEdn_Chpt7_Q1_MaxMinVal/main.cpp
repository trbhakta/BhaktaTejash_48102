/* 
   File:   main
   Author: Tejash Bhakta
   Created on November 14, 2016, 9:41 AM
   Purpose: Obtaining Largest and Smallest value in an Array
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
int max(int[]);
int min(int[]);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    int number=10, maxVal, minVal;
    int val[number];
    
    //Input values
    cout<<"Enter 10 numbers to store in the array"<<endl;
   for(int i=0;i<number;i++){
       cout<<"number "<<i+1<<": ";
       cin>>val[i];
   } 
    
    //Checking the maximum number
      maxVal=max(val);
    
    //Checking the minimum number 
      minVal=min(val);
    
    //Display Output
    cout<<"The Maximum number is: "<<maxVal<<endl;
    cout<<"The Minimum number is: "<<minVal<<endl;
    
    //Exit Program
    return 0;
}
//Function max
//input array values
//output the maximum number
int max(int value[]){
    int max=value[0];
    for(int i=1; i<10; i++){
        if(value[i]>max)max=value[i];
    }
    return max;
}

//Function min
//input array values
//output the minimum number
int min(int value[]){
    int min=value[0];
    for(int i=1; i<10; i++){
        if(value[i]<min)min=value[i];
    }
    return min;
}
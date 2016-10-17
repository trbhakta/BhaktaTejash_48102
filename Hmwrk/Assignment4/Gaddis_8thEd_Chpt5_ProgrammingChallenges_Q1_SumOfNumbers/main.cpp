/* 
   File:   main
   Author: Tejash Bhakta
   Created on October 10, 2016, 11:41 AM
   Purpose: To find the sum of consecutive numbers 
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
    int numRange, sum;   //The range from 0,number to find the sum, Sum of the numbers
    //Validations and calculations
    do{
       cout<<"Input the number till which to find the sum"<<endl;
       cin>>numRange;
    }while(numRange<0);
    
    //The sum of the consecutive numbers
    for(int i=1; i<=numRange; i++){
           sum+=i;
       }
      cout<<"The sum of numbers from 0 to "<<numRange<<" is "<<sum; 
    
    
    //Exit Program
    return 0;
}

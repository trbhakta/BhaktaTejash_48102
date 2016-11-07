/* 
   File:   main
   Author: Tejash Bhakta
   Created Nov 1, 2016, 5:30 PM
   Purpose:  Find all Primes between 1 to 100
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cmath>      //Square root
#include <iomanip>    //formatting
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
bool  isPrime(int);

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare counter
    int count=0,columns=5;
    
    //Display Output
    for(int i=1;i<=100;i++){
        if(isPrime(i)){
            cout<<setw(3)<<i<<" ";
            count++;
            if(count==columns){
                cout<<endl;
                count=0;
            }
        }
    }

    //Exit Program
    return 0;
}

//Function isPrime
//Input integer 
//Return true if Prime and False if Composite
bool isPrime(int n){
    if(n<2)return false;
    for(int i=2;i<=sqrt(n);i++){//Efficient
        if(n%i==0)return false;
    }
    return true;
}
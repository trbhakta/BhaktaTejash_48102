/* 
   File:   main
   Author: Tejash Bhakta
   Created on September 9, 2016, 9:41 AM
   Purpose: To find Sum and Product of two integers 
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
    int num_1, num_2, sum, product;
    
    //Input values
    cout<<"Enter two numbers to find their sum and product"<<endl;
    cin<<num_1<<num_2;
            
    //Process values -> Map inputs to Outputs
    sum= num_1+ num_2;
    product= num_1 * num_2;
    //Display Output
    cout<<"Given number 1 = "<<num_1<<endl;
    cout<<"Given number 2 = "<<num_2<<endl;
    cout<<"The sum of the numbers  = "<<sum<<endl;
    cout<<"The product of the numbers =  "<<product<<endl<<endl;
    cout<<"This is the end of the program"<<endl;
    
    //Exit Program
    return 0;
}
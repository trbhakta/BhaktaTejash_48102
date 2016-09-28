/*
   File:   main
   Author: Tejash Bhakta
   Created on September 25, 2016, 10:41 PM
   Purpose: To calculate the BMR of a person according to gender and 
            figuring out number of chocolate to be eaten for maintaining weight 
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
    char gender;                     //to input M ->Male or F->Female
    unsigned short age, numChoc;  //Age in years, weight in pounds, height in inches, no. chocolates, BMR
    float weight, height, bmr;    //weight in pounds, height in inches, Basal Metabolic Rate
    
    //Input values
    cout<<"Enter your age in years"<<endl;
    cin>>age;
    
    cout<<"Enter your height in inches"<<endl;
    cin>>height;
    
    cout<<"Enter your weight in pounds"<<endl;
    cin>>weight;
    
    cout<<"Input 'M' for male and 'F' for female"<<endl;
    cin>>gender;
    
    //Process values -> Map inputs to Outputs
    if(gender=='M'){
        bmr = 66+(6.3*weight)+(12.9*height)+(6.8*age);  // BMR formula for male    
    }
    else if(gender=='F'){
        bmr= 655+(4.3*weight)+(4.7*height)+(4.7*age);   // BMR formula for female
    }
   
    numChoc= bmr/230; //chocolate calories = 230
    
    //Output
    cout<<" You are a     "<<gender<<endl;
    cout<<" Your weight = "<<weight<<endl;
    cout<<" Your height = "<<height<<endl;
    cout<<" BMR         = "<<bmr<<endl;
    cout<<"Number of chocolates to be eaten to maintain the weight = "<<numChoc<<endl;

    //Exit Program
    return 0;
}

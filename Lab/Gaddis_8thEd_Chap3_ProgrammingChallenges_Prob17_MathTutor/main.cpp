/* 
   File:   main
   Author: Tejash Bhakta
   Created on September 14th, 2016, 10:22 AM
   Purpose:  Develop a program to project random numbers and add them 
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cstdlib>    //Random number seed
#include <ctime>      //Seed the random number generator
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declaration of Variables
    unsigned short num1,num2,result,answer;
    
    //Input values
    num1=rand()%900+100;//3 digit random number
    num2=rand()%900+100;//3 digit random number
    
    //Process values -> Map inputs to Outputs
    result=num1+num2;
    
    //Display Output
    cout<<"Solve the following addition problem"<<endl;
    cout<<"   "<<num1<<endl;
    cout<<" + "<<num2<<endl;
    cout<<"_______"<<endl;
    
    //Ask user for the answer
    cout<<endl<<"What is the answer?"<<endl;
    cin>>answer;
    cout<<endl;
    
    //Determine if correct or not
    if(answer==result){
        cout<<"The answer is correct : "<<result<<endl;
    }
    else{
        cout<<"No. The answer should be : "<<result<<endl;
    }
    //Exit Program
    return 0;
}
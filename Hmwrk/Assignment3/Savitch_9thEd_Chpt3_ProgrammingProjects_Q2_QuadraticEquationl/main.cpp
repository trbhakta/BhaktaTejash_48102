/* 
   File:   main
   Author: Tejash Bhakta
   Created on October 1, 2016, 4:50 PM
   Purpose:  Calculating algebraic Equation Solutions 
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cmath>      //Math Library
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    float a,b,c;
    
    //Input values
    cout<<"Solution to Quadratic ax^2+bx+c=0"<<endl;
    cout<<"Input 3 float data types a b c"<<endl;
    cin>>a>>b>>c;
    
    //Process values -> Map inputs to Outputs and display
    float vb4sqrt= pow(b,2)-4*a*c;
    if(a==0){
        if(b==0){
            cout<<"This is not an algebraic equation"<<endl;
        }else{
            cout<<"The solution is x = "<<-c/b<<endl;
        }
    }else if(vb4sqrt>0){
        cout<<"x = ("<<((-b+sqrt(vb4sqrt))/(2*a))<<" , "
                     <<((-b-sqrt(vb4sqrt))/(2*a))<<")"<<endl;
    }else{
        cout<<"x = ("<<(-b/(2*a))<<"+"<<( sqrt(-vb4sqrt)/(2*a))<<"i, "
                     <<(-b/(2*a))<<"+"<<(-sqrt(-vb4sqrt)/(2*a))<<"i)"<<endl;
    }

    //Exit Program
    return 0;
}
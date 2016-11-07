/* 
   File:   main
   Author: Tejash Bhakta
   Created October 28, 2016, 3:00 PM
   Purpose:  Conversion of temperature from Celsius to Fahrenheit
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>    //Format
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
float tempCnv(float);
float tempCnv(float,float,float,float,float);


//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare freezing and boiling pts of water
    //for degree Fahrenheit and Celsius 
    int begF, endF;
    
    //Input values
    cout<<"Enter the range of temperature from starting to ending temperature(in Fahrenheit)"<<endl;
    cin>>begF>>endF;
    
    //Process values --Call Function and Display Output    
    cout<<"Degree F   Degree C "<<endl;
    cout<<fixed<<setprecision(2)<<showpoint;
    if(begF<endF){
        for(int degF=begF; degF<=endF; degF++){
            cout<<setw(6)<<degF
                <<setw(12)<<tempCnv(degF)<<endl;
        }
    }
    else if(begF>endF){
        for(int degF=begF; degF>=endF; degF--){
            cout<<setw(6)<<degF
                <<setw(12)<<tempCnv(degF)<<endl;
        }
    }
    //Exit Program
    return 0;
}

//Temperature conversion from degree Fahrenheit to Celsius
//Input
//  f->Fahrenheit
//Output
//  c->Celsius
float tempCnv(float f){
    return (f-32.0f)*5/9;
}

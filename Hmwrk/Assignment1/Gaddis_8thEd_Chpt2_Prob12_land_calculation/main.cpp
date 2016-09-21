/* 
   File:   main
   Author: Tejash Bhakta
   Created on August 29, 2016, 2:00 PM
   Purpose: Convert the land in square feet to acres 
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const float CNVSFAC= 43560; // 1 acre = 43560 sqft
//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declaration of Variables
  float sqft ; // Square feet
  float cnversn; //Conversion to acres
  
    //Input values
  cout<<"Enter the area of land in square ft"<<endl;
  cin>>sqft;
  cout<<endl;
  
  //Process values -> Map inputs to Outputs
  cnversn= sqft/CNVSFAC;

  //Display Output
  cout<<"Land in sqft :"<<sqft<< " sqft"<<endl;
  cout<<"1 acre = "<<CNVSFAC<<" Square Feet"<<endl;
  cout<<"This land is equivalent to "<<cnversn<<" acres."<<endl;
    //Exit Program
    return 0;
}

/* 
   File:   main
   Author: Tejash Bhakta
   Created on September 25, 2016, 2:41 AM
   Purpose:  
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>    //Formatting
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    unsigned short temp1, temp2; //Temperature 1 and 2 in Celsius, Difference between two degrees
    float velocity;              //Velocity of sound 
    
    //Input values
    cout<<"Enter the starting degree"<<endl;
    cin>>temp1;
    
    cout<<"Enter the ending degree"<<endl;
    cin>>temp2;
    
    //Process values -> Map inputs to Outputs
   
    //If starting point is less than ending point:- this program works.
    while(temp1<=temp2){
        velocity = 331.3 + 0.61 *temp1;  //Approximated formula of velocity of  sound in dry air
        cout<<fixed<<setprecision(2);
        cout<<"At "<<temp1<<" degrees Celsius, the velocity of sound is "<<velocity<<" m/s"<<endl;
        temp1+=1;
    }
    
    //Exit Program
    return 0;
}

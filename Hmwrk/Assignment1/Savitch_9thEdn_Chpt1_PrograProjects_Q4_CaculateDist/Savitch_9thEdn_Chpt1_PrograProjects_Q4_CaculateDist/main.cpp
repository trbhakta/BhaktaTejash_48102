/* 
   File:   main
   Author: Tejash Bhakta 
   Created on September 9, 2016, 11:00 AM
   Purpose: Calculate the distance of Free Fall in given Seconds
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const float GRAVITY = 32;
//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    float Time_Sec, totDist;
    //Input values
    cout<<"Enter time in Seconds to calculate the distance in Free Fall"<<endl;
    cin>>Time_Sec;
    
    //Process values -> Map inputs to Outputs
    totDist= GRAVITY*(Time_Sec*Time_Sec)/2; 
    //Display Output
    cout<<"The object will fall at an accelaration of "<<GRAVITY<<" ft/sec, in time "<<Time_Sec<<" seconds, and the distance travelled by it will be "<<totDist<<" feet"<<endl;
    //Exit Program
    return 0;
}
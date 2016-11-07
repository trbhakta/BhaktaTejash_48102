/* 
   File:   main
   Author: Tejash Bhakta
   Created October 29, 2016, 9:41 AM
   Purpose: Calculate the falling distance due to gravity 
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>    //Formatting
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const float GRAVITY=9.8f;
//Function prototypes
float dist(int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    int sec;
    float distance;
    
    //Input values
    cout<<"Input the time(in seconds) to calculate the distance of falling object "<<endl;
    cin>>sec;
    
    //Display Output
    for(int i=1;i<=sec;i++){
        cout<<fixed<<setprecision(2);
        cout<<"The distance traveled by the object in "<<setw(2)<<i<<" sec is "<<setw(7)<<dist(i)<<" mts."<<endl;
    }
    //Exit Program
    return 0;
}

//Function dist
//Input the seconds and gravity constant
//Outputs the Distance
float dist(int sec){
    return 0.5*GRAVITY*sec*sec;
}
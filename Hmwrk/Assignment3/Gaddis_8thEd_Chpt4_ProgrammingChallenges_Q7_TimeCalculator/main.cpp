/* 
   File:   main
   Author: Tejash Bhakta
   Created on October 4, 2016, 11:41 PM
   Purpose: To convert the total seconds into days, hours, minutes and seconds 
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const int HRSDAY = 24;       //Hours in a day
const int MINHR = 60;       //Minutes in an hour
const int SECMIN = 60;      //Seconds in a minute
//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    int totSec, days, hours, mins, sec;
    
    //Taking values
    cout<<"Input the total seconds to be converted"<<endl;
    cin>>totSec;
    
    //Process values -> Map inputs to Outputs
    if(totSec>=60){
        sec=totSec%SECMIN;
        mins=totSec/SECMIN;
        cout<<"Minutes in "<<totSec<<" is "<<mins<<" minutes and "<<sec<<" seconds."<<endl<<endl;
    }
    if(totSec>=3600){
        sec=totSec%SECMIN;
        mins=totSec/SECMIN;
        hours=mins/MINHR;
        mins=mins%MINHR;
        cout<<"Hours in "<<totSec<<" is "<<hours<<" hours, "<<mins<<" minutes and "<<sec<<" seconds."<<endl<<endl;
    }
    if(totSec>=86400){
        sec=totSec%SECMIN;
        mins=totSec/SECMIN;
        hours=mins/MINHR;
        mins=mins%MINHR;
        days=hours/HRSDAY;
        hours=hours%HRSDAY;
        cout<<"Days in "<<totSec<<" are "<<days<<" days, "<<hours<<" hours, "<<mins<<" minutes and "<<sec<<" seconds."<<endl<<endl;
    }
    else{
        cout<<totSec<<" seconds";
    }
    
    //Display Output

    //Exit Program
    return 0;
}

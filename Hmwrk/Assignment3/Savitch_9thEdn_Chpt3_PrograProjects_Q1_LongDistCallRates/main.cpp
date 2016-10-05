/* 
   File:   main
   Author: Tejash Bhakta
   Created on October 01, 2016, 8:41 AM
   Purpose: Compute the rate of long distance call depending on the rate schedule 
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
    unsigned short  tmHrs, tmMin, durCall; //Hours, Minutes, duration of Call
    float rate, charges;        //rate of the call, charges
    char day1,day2,c;          //for two char name for days of week, c to store colon between hours and minutes
    
    //Input values
    cout<<"Program calculates the call charges depending on day and duration of call"<<endl;
    cout<<"\nEnter the first two characters of the day. Eg. Mo -> Monday etc"<<endl;
    cin>>day1>>day2;
    
    cout<<"Enter the time of the call in 24 hr clock(HH:MM)"<<endl;
    cin>>tmHrs>>c>>tmMin;
    cin.clear();
    cin.ignore(10000, '\n');
    
    cout<<"Enter the duration (in minutes) of the call"<<endl;
    cin>>durCall;
    
    //Processing and Validations
    //Validation of time in 24 hour
    if((tmHrs<0 || tmHrs>24) || (tmMin<0 || tmMin>60)){
        cout<<"Enter valid time"<<endl;
        return 1;                         //return Failure
    }
    
    //Processing the rate
        if((day1=='m' || day1=='M') && (day2=='o' || day2=='O')){
            if     (tmHrs>=8 && tmHrs<=18)rate=0.40;        //rate =$0.40 per min for Monday 8:00am to 6:00pm
            else if(tmHrs<8 || tmHrs>18)  rate=0.25;        //rate =$0.25 per min for Monday before 8am and after 6pm  
        }
        else if((day1=='t' || day1=='T') && (day2=='u' || day2=='U')){
            if     (tmHrs>=8 && tmHrs<=18)rate=0.40;        //rate =$0.40 per min for Tuesday 8:00am to 6:00pm
            else if(tmHrs<8 || tmHrs>18)  rate=0.25;        //rate =$0.25 per min for Tuesday before 8am and after 6pm  
        }
        else if((day1=='w' || day1=='W') && (day2=='e' || day2=='E')){
            if     (tmHrs>=8 && tmHrs<=18)rate=0.40;        //rate =$0.40 per min for Wednesday 8:00am to 6:00pm
            else if(tmHrs<8 || tmHrs>18)  rate=0.25;        //rate =$0.25 per min for Wednesday before 8am and after 6pm  
        }
        else if((day1=='t' || day1=='T') && (day2=='h' || day2=='H')){
            if     (tmHrs>=8 && tmHrs<=18)rate=0.40;        //rate =$0.40 per min for Thursday 8:00am to 6:00pm
            else if(tmHrs<8 || tmHrs>18)  rate=0.25;        //rate =$0.25 per min for Thursday before 8am and after 6pm  
        }
        else if((day1=='f' || day1=='F') && (day2=='r' || day2=='R')){
            if     (tmHrs>=8 && tmHrs<=18)rate=0.40;        //rate =$0.40 per min for Friday 8:00am to 6:00pm
            else if(tmHrs<8 || tmHrs>18)  rate=0.25;        //rate =$0.25 per min for Friday before 8am and after 6pm  
        }
        else if((day1=='s' || day1=='S' && day2=='a' || day2=='A')){
          rate=0.15;                                    //rate =$0.15 per min for every Saturday  
        }
        else if((day1=='s' || day1=='S') && (day2=='u' || day2=='U')){
          rate=0.15;                                   //rate =$0.15 per min for every Sunday  
        }
        else {
        cout<<"Day Error. Input valid day of week"<<endl;
        return 1;            //Return Failure
        }
    
    //Calculating charges
    charges= rate*durCall;

    //Output
    cout<<"Day of week      : "<<day1<<day2<<endl;
    cout<<"Time             : "<<tmHrs<<c<<tmMin<<endl;
    cout<<"Duration of call : "<<durCall<<" minutes"<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"Rate for that period: $"<<setw(8)<<rate<<" per minute"<<endl;
    cout<<"Total charges       : $"<<setw(8)<<charges<<endl;
    
    //Exit Program
    return 0;
}

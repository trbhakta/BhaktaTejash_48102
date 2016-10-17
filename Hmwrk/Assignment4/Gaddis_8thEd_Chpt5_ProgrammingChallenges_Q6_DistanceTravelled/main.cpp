/* 
   File:   main
   Author: Tejash Bhakta
   Created on October 8, 2016, 4:41 PM
   Purpose: To calculate the distance traveled in following hours  
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
    float speed, distance; //Speed in mph, distance to be calculated
    int  time;             //time traveled
    //Input values and validations
    do{
        cout<<"Enter your average speed in mph"<<endl;
        cin>>speed;
        
        cout<<"Enter number of hours traveled"<<endl;
        cin>>time;
    }while(speed<0 || time<=1);
    
    //output the format
    cout<<" Hours       |"<<"Distance Travelled"<<endl;
    cout<<"------------------------------------"<<endl;
    
    //calculation of distance
    for(int i=1; i<=time; i++){
        distance=speed*i;
        cout<<"  "<<i<<"          |   "<<setw(5)<<distance<<" miles"<<endl;
    }
    

    //Exit Program
    return 0;
}

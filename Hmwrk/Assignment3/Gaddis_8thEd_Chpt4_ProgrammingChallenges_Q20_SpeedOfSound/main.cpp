/* 
   File:   main
   Author: Tejash Bhakta
   Created on October 1, 2016, 9:41 AM
   Purpose: To calculate the amount of time taken by sound wave in different mediums 
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
    char medium;                   //for obtaing the medium as in W, S, or A
    unsigned short spdAir= 1100,   //Speed in Air ft per sec 
                   spdWater= 4900, //Speed in Water ft per sec
                   spdStl= 16400;  //Speed in Steel ft per sec
    float            totDist;          //Total Distance
    
    //Input values
    cout<<"This program calculates time depending on speed of sound wave in Air, Water or Steel"<<endl;
    cout<<"Enter the medium to calculate the time taken by the wave : A-air, W-water or S-steel"<<endl;
    cin>>medium;
    cout<<"Enter the total distance traveled by the wave"<<endl;
    cin>>totDist;
    
    //Process values -> Map inputs to Outputs
    if(medium == 'A'){                     //if medium is Air
        
        cout<<"Time taken in air for "<<totDist<<" ft would be ";
        cout<<fixed<<showpoint<<setprecision(4)<<totDist*spdAir<<" ft/sec"<<endl;
    }
    else if (medium == 'W'){              //if medium is Water
        cout<<"Time taken in water for "<<totDist<<" ft would be ";
        cout<<fixed<<showpoint<<setprecision(4)<<totDist*spdWater<<" ft/sec"<<endl;
    }
    else if (medium == 'S'){              ////if medium is Steel
        cout<<"Time taken in steel for "<<totDist<<" ft would be ";
        cout<<fixed<<showpoint<<setprecision(4)<<totDist*spdStl<<" ft/sec"<<endl;              
    }
    else cout<<"Enter the correct medium A, W or S";   
    
    //Display Output

    //Exit Program
    return 0;
}

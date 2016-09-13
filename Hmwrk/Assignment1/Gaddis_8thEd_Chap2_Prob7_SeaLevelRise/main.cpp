/* 
   File:   main
   Author: Tejash Bhakta        
   Created on SEPTEMBER 13, 2016, 11:50 AM
   Purpose: To Calculate when homeowners in Riverside will have 
            beach front houses 
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cstdlib>

using namespace std;

//User Libraries

//Global Constants
const float CNVMMFT = 304.8f;// Conversion from millimeter to feet from Google
const float CNVMMM = 1000.0f;// Conversion from millimeter to meters from Google

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {

     //Declaration of Variables
    
 float rate = 1.5;             //the rate the sea rises is 1.5mm/year    
 int nYear1=5, nYear2=7, nYear3=10; //Years to calculate rise
 float rise1, rise2, rise3;        //Solutions for the 3 years above   
 int nYrBch;                       //Number of years your home is beach front property
 float elevRiv=860.0f;                //Elevation of Riverside in feet according to wikipedia 
 
    
    //Process values -> Map inputs to Outputs
   rise1= rate*nYear1;
   rise2= rate*nYear2;
   rise3= rate*nYear3;
   nYrBch=(elevRiv/rate)*CNVMMFT;
   
  
    //Display Output
   cout<<"The rate of sea level rise = "<<rate<<" mm/year"<<endl;
   cout<<"The sea level rise in"<<nYear1<<" years = "<<rise1<<" mm"<<endl;
   cout<<"The sea level rise in"<<nYear2<<" years = "<<rise2<<" mm"<<endl; 
   cout<<"The sea level rise in"<<nYear3<<" years = "<<rise3<<" mm"<<endl;
   cout<<"At this rate, Riverside won't have beach front properties in "<<nYrBch<<" years."<<endl;
   cout<<"This rise equates to "<<nYrBch*rate/CNVMMM<<" meters"<<endl;
   //Exit Program
    return 0;
}
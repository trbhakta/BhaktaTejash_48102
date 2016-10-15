/* 
 * File:   main.cpp
 * Author: Tejash Bhakta
 * Created on September 29, 2016, 12:04 PM
 * Purpose: To determine the Band of Radiation from Wave Length 
 */

//System Libraries Here
#include <iostream>     //Input Output
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables


//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float waveLen;
    
    //Input or initialize values Here
    cout<<"What is the wavelength in Meters: "<<endl;
    cout<<"This program determines the band of radiation"<<endl;
    cin>>waveLen;
    
    //Process/Calculations Here
    if      (waveLen>1e-2f) cout<<"Radio Band"<<endl;
    else if (waveLen>1e-3f) cout<<"Micro Wave Band"<<endl;
    else if (waveLen>7e-7f) cout<<"Infrared Band Wave"<<endl;
    else if (waveLen>4e-7f) cout<<"Visible Band"<<endl;
    else if (waveLen>1e-8f) cout<<"Ultra-Violet Band"<<endl;
    else if (waveLen>1e-11f)cout<<"X-Ray Band"<<endl;
    else                    cout<<"Gamma Ray Wave"<<endl;
    //Exit
    return 0;
}


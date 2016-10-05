/* 
   File:   main
   Author: Tejash Bhakta
   Created on October 3, 2016, 5:41 PM
   Purpose: Mixing primary colors to get secondary color 
 */

//System Libraries
#include <iostream>   //Input/Output objects

using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    string color1, color2;
    
    //Getting colors
    cout<<"Program takes primary colors as inputs and provides secondary color as output\n\n";
    cout<<"Enter any two primary colors red, blue or yellow"<<endl;
    cin>>color1>>color2;
    
    //Input Validations and processing
    if((color1=="red" && color2=="blue") || (color1=="blue" && color2=="red")){
        cout<<"Mixing of "<<color1<<" and "<<color2<<" will give PURPLE as secondary color"<<endl;
    }
    else if((color1=="red" && color2=="yellow") || (color1=="yellow" && color2=="red")){
        cout<<"Mixing of "<<color1<<" and "<<color2<<" will give ORANGE as secondary color"<<endl;
    }
    else if((color1=="blue" && color2=="yellow") || (color1=="yellow" && color2=="blue")){
        cout<<"Mixing of "<<color1<<" and "<<color2<<" will give GREEN as secondary color"<<endl;
    }
    else
        cout<<"Please input a primary color i.e red, blue or green";
    

    //Exit Program
    return 0;
}

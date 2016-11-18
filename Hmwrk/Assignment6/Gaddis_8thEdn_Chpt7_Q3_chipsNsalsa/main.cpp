/* 
   File:   main
   Author: Tejash Bhakta
   Created on November 17, 2016, 9:41 PM
   Purpose: Using parallel arrays 
            Storing number of jars beside respective salsa flavors 
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    string salsa [5]={"mild","medium","sweet","hot","zesty"};
    int jars[5];
    int total=0;
    //Input values
    for(int i=0;i<5;i++){
        cout<<"Enter the number of jars for "<<salsa[i]<<" salsa"<<endl;
        cin>>jars[i];
    }
    
    //Process values 
    //individual sales
    cout<<endl<<"The Sales Report"<<endl;
    int max=jars[0], min=jars[0];
    string high=salsa[0], low=salsa[0];
    for(int i=0;i<5;i++){
        cout<<setw(9)<<salsa[i]<<" salsa: "<<jars[i]<<endl;
        total+=jars[i];
        if(max<jars[i])high=salsa[i];
        if(min>jars[i])low=salsa[i];
    }
  
    cout<<"The Total sales : "<<total<<" jars"<<endl;
    cout<<"Highest selling Salsa: "<<high<<endl;
    cout<<"Lowest selling Salsa: "<<low<<endl;
    
    //Exit Program
    return 0;
}

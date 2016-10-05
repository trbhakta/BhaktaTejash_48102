/* 
   File:   main
   Author: Tejash Bhakta
   Created on October 01, 2016, 10:41 AM
   Purpose:  
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
    float dist,wgtPkg, rate, charges; //Distance,Weight of Package, rate per 500 miles, total charges
    
    //Input values
    cout<<"This program calculates the charges of a package on weight and distance"<<endl;
    cout<<"Enter the weight of package between 0kg to 20kgs"<<endl;
    cin>>wgtPkg;
    
    cout<<"Enter the distance between 10mi to 3000mi"<<endl;
    cin>>dist;
    
    //Validations 
    if(wgtPkg<=0 || wgtPkg>20){
        cout<<"Weight Error. Enter between 0 to 20kgs"<<endl;
        return 1;
    }
    if(dist<10 || dist>3000){
        cout<<"Distance Error. Enter between 10 miles to 3000 miles"<<endl;
        return 1;
    }
   
    //Processing Rates
    if      (wgtPkg>0 && wgtPkg<=2) rate=1.10;  //0-2 -> rate $1.10
    else if (wgtPkg>2 && wgtPkg<=6) rate=2.20;  //2-5 -> rate $2.20
    else if (wgtPkg>6 && wgtPkg<=10) rate=3.70; //6-10 ->rate $3.70
    else if (wgtPkg>10 && wgtPkg<=20) rate=4.80;//10-20 ->rate $4.80

    //Calculating charges
    
    charges=rate*dist/500;
    
    //Output
    cout<<fixed<<setprecision(2);
    cout<<"Weight Of Package =  "<<setw(8)<<wgtPkg<<" kg"<<endl;
    cout<<"Shipping Distance =  "<<setw(8)<<dist<<" mi"<<endl;
    cout<<"Rate per 500 miles= $"<<setw(8)<<rate<<endl;
    cout<<"Total Charges     = $"<<setw(8)<<charges<<endl;
    
    //Exit Program
    return 0;
}

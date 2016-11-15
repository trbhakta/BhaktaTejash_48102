/* 
 * File:   main.cpp
 * Author: Tejash Bhakta
 * Created on November 5, 2016, 9:07 PM
 * Purpose:  Overloaded Function to calculate charges
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
float charges(int,float,float,float);
float charges(float,float);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    char patient; 
    int days;
    float dRate, medChg, hosChg;
    
    //Input or initialize values Here
    do{
        cout<<"Were you inpatient(i) or outpatient(o)"<<endl;
        cin>>patient;
    }while(patient!='i' && patient!='o');
    
    //Process
    if(patient=='i'){
        do{
            cout<<"Number of days spent in Hospital"<<endl;
            cin>>days;
            cout<<"Daily Rate Charged"<<endl;
            cin>>dRate;
            cout<<"Medication Charges"<<endl;
            cin>>medChg;
            cout<<"Hospital Service Charges"<<endl;
            cin>>hosChg;
            cout<<endl<<"In-Patient Charges---"<<endl;
        }while(days<0 && dRate<0 && medChg<0 && hosChg<0);
        cout<<"Your Total Charges is :$ "<<charges(days,dRate,medChg,hosChg)<<endl;
    }
    else{
        do{
            cout<<"Medication Charges"<<endl;
            cin>>medChg;
            cout<<"Hospital Service Charges"<<endl;
            cin>>hosChg;
            cout<<endl<<"Out Patient Charges---"<<endl;
        }while(medChg<0 && hosChg<0);
        cout<<"Your Total Charges is :$ "<<charges(medChg,hosChg)<<endl;
    }             
    
    //Exit
    return 0;
}

//Function Name charges
//Input number of days, daily rate, medication charge, service charge
//Output charges
float charges(int days, float rate, float med, float hosp){
    return (days*rate)+med+hosp;
}
float charges(float med, float hosp){
    return med+hosp;
}
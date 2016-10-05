/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on October 4, 2016, 11:07 AM
 * Purpose:  Input three numbers and sort in ascending order
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables


//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
   
    //Declare all Variables Here
    short num1, num2, num3;   
    
    //Input or initialize values Here
    
    cout<<"Input numbers to place them from lowest to highest"<<endl;
    cout<<"Enter three numbers in any order"<<endl;
    cin>>num1>>num2>>num3;
    //Process/Calculations Here
    
    if(num1<num2 && num1<num3){
        if(num2<num3) cout<<num1<<" "<<num2<<" "<<num3;
        else          cout<<num1<<" "<<num3<<" "<<num2;
    }
    else if(num2<num1 && num2<num3){
        if(num1<num3) cout<<num2<<" "<<num1<<" "<<num3;
        else          cout<<num2<<" "<<num3<<" "<<num1;
    }
    else if(num3<num1 && num3<num2){
        if(num1<num2) cout<<num3<<" "<<num1<<" "<<num2;
        else          cout<<num3<<" "<<num2<<" "<<num1;
    } 
    
    //Output Located Here
   

    //Exit
    return 0;
}


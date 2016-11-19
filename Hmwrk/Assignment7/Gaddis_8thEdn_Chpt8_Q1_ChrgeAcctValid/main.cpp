/* 
   File:   main
   Author: Tejash Bhakta
   Created November 19, 2016, 11:41 AM
   Purpose:  To check whether a number is present in the array
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void prntAry(int[],int);
bool check(int[],int,int);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    const int SIZE=18;
    int number[SIZE]={5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
                      8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
                      1005231, 6545231, 3852085, 7576651, 7881200, 4581002};
    int user;
    
    //Display values
    prntAry(number,SIZE);
    
    //Take a number from the user
    cout<<endl<<"Enter a number to check whether present in the array"<<endl;
    cin>>user;
    
    //Check if the number present in the array
    if(check(number,SIZE,user))cout<<"The number is present in the array"<<endl;
    else cout<<"The number not in the array"<<endl;

    //Exit Program
    return 0;
}
//Function name prntArry
//Input the array and its size
//Output the values from the array
void prntAry(int num[],int n){
    cout<<"Numbers in the array"<<endl;
    for(int i=0;i<n;i++){
        cout<<num[i]<<" ";
        if(i%6==5)cout<<endl;
    }
}
//function name check
//Input the array of numbers, its size and the number from the user
//Output true if number present else false
bool check(int num[],int n,int usr){
    for(int i=0;i<n;i++){
        if(num[i]==usr)return true;
    }
    return false;
}
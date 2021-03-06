/* 
   File:   main
   Author: Tejash Bhakta
   Created on August 29, 2016, 9:41 AM
   Purpose:  To check Lottery won or not from the list of lottery tickets using linear search
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
bool check(int[],unsigned short,int);
void prntAry(int[],unsigned short);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    unsigned short size=10;
    int lotNum[size]={13579, 26791, 26792, 33445, 55555,
                      62483, 77777, 79422, 85647, 93121};
    int lottery;
    //Input values
    cout<<"Enter the ticket number for the lottery"<<endl;
    cin>>lottery;
    
    //Print user's lottery numbers
    prntAry(lotNum,size);
    //Process values -> Map inputs to Outputs
    cout<<endl<<"Using Linear Search"<<endl;
    if(check(lotNum,size,lottery))cout<<"Congratulations!! You won the lottery for "<<lottery<<" number"<<endl;
    else cout<<"Sorry! Better luck next time"<<endl;
    //Exit Program
    return 0;
}
//function name check
//input the lottery number array, size of array, winning number
//Return true if lottery won else returns false
bool check(int array[],unsigned short n, int lttry){
    for(int i=0;i<n;i++){
        if(array[i]==lttry)return true;
    }
    return false;
}

//function name print array
//input the array, input its size
//output the elements from the array
void prntAry(int array[],unsigned short size){
    cout<<"Your Lottery numbers"<<endl;
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
        if(i%5==4)cout<<endl;
    }
}

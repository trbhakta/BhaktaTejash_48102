/* 
   File:   main
   Author: Tejash Bhakta
   Created November 18' 2016
   Purpose:  Check the elements on the lottery and user ticket
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cTime>      
#include <cstdlib>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void fillAry(int[],int);
void prntAry(int[],int);
void compare(int[],int[],int);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<int>(time(0)));
    
    //Declaration of Variables
    const int SIZE=5;
    int userNum, digit;
    int lottery[SIZE], user[SIZE];
    
    //Input values
    fillAry(lottery,SIZE);
    
    //input user lottery number
    do{
        cout<<"Enter your 5 digit lottery number"<<endl;
        cin>>userNum;
    }while(userNum>99999 || userNum<9999);
    
    //Store the number in the Array
    for(int i=SIZE-1;i>=0;i--){
        user[i]=userNum%10;
        userNum=userNum/10;
    }
    
    //Display the lottery number;
    cout<<endl<<"The lottery Ticket"<<endl;
    prntAry(lottery,SIZE);
    
    //Check the lottery vs. user ticket
    compare(lottery,user,SIZE);
    
    //Exit Program
    return 0;
}

void fillAry(int array[], int n){
    for(int i=0;i<n;i++){
        array[i]=rand()%9+1;
    }
}
void prntAry(int array[], int n){
    for(int i=0;i<n;i++){
        cout<<array[i];
    }
    cout<<endl;
}
void compare(int ltr[],int usr[],int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(ltr[i]==usr[i])count++;
    }
    //Check if JACKPOT
    if(count==5)cout<<"****You won the JACKPOT****"<<endl;
    else if(count==0)cout<<"Sorry gather some luck"<<endl;
    else cout<<"There are "<<count<<" digits matching"<<endl;
}
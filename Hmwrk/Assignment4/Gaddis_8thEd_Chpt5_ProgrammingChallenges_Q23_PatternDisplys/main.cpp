/* 
 * File:   main.cpp
 * Author: Tejash Bhakta
 * Created on October 11, 2016, 12:07 PM
 * Purpose:  Display the pattern of stars with desired rows by user
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
    short rows; //Desired rows by user
    
    //Taking values from user and validations
    
    do{
        cout<<"Enter the number of rows you wish to see in the pattern"<<endl;
        cin>>rows;
    }
    while(rows<=0);
        
    //Loop iterations for pattern A 
    //*
    //**
    //***    
    cout<<"Pattern A"<<endl;
        for(int i=1; i<=rows ; i++){
           for(int j=1;j<=i;j++){
               if(j<=i) cout<<"*";
               else     cout<<" ";
            }
          cout<<endl;
        } 
    
    //Loop Iteration for pattern B
    //***
    //**
    //*
    cout<<endl<<"Pattern B"<<endl;
        for(int i=1; i<=rows ; i++){
            for(int j=rows;j>=1;j--){
                if(i<=j) cout<<"*";
                else     cout<<" ";
            }
          cout<<endl;  
        }
    
    //Loop Iteration for pattern C
    /*  *
       **
      ***
    */
    cout<<endl<<"Pattern C"<<endl;
        for(int i=rows; i>=1; i--){
            for(int j=1; j<=rows; j++){
                if(i>j) cout<<" ";
                else    cout<<"*";
            }
          cout<<endl;
        }
    
    //Loop Iteration for pattern D
    /* ***
       **
       *
    */
    cout<<endl<<"Pattern D"<<endl;
        for(int i=rows; i>=1; i--){
            for(int j=rows; j>=1; j--){
                if(i>=j) cout<<"*";
                else    cout<<" ";
            }
          cout<<endl;  
        }
    
    //Output Located Here
    

    //Exit
    return 0;
}


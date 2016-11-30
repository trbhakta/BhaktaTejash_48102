/* 
 * File:   main.cpp
 * Author: Tejash Bhakta
 * Created on November 29, 2016, 9:07 AM
 * Purpose:  String Selection Sort
 */

//System Libraries Here
#include <iostream>
#include <string>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void sort(string [],int);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
  const int NUM=20;
  string names[NUM]={"Collins, Bill","Smith, Bart","Allen, Jim",
                     "Allison, Jeff","Looney, Joe","Griffin, Jim",
                     "Stamey, Martey","Rose, Geri","Taylor, Terri",
                     "James, Jean","Wolfe, Bill","Johnson, Jill",
                     "Weaver, Jim","Pore, Bob","Rutherford, Greg",
                     "Harrison, Rose","Setzer, Cathy","Javens, Renee",
                     "Pike, Gordon","Holland, Beth"};
  
    //Output the array
  for(int i=0;i<NUM;i++){
      cout<<names[i]<<"\t";
      if(i%5==4)cout<<endl;
  }
    //Sort the names
  sort(names,NUM);
    
    //Output Located Here
  cout<<endl;
   for(int i=0;i<NUM;i++){
      cout<<names[i]<<endl;
  }

    //Exit
    return 0;
}
//Function sort
void sort(string nam[],int n){
     int minInd;
     string minVal;
    for(int i=0;i<n-1;i++){
        minInd=i;
        minVal=nam[i];
        for(int index=i+1;index<n;index++){
            if(nam[index]<minVal){
                minVal=nam[index];
                minInd=index;
            }
        }
        nam[minInd]=nam[i];
        nam[i]=minVal;
        
    }
}


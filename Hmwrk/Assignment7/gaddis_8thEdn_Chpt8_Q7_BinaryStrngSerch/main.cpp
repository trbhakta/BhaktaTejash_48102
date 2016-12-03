/* 
 * File:   main.cpp
 * Author: Tejash Bhakta
 * Created on November 30, 2016, 9:07 AM
 * Purpose:  Binary String Search
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
bool binSrch(string[],int,string);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
  const int NUM=20;
  string nameSel;
  string names[NUM]={"Collins","Smith","Allen",
                     "Allison","Looney","Griffin",
                     "Stamey","Rose","Taylor",
                     "James","Wolfe","Johnson",
                     "Weaver","Pore","Rutherford",
                     "Harrison","Setzer","Javens",
                     "Pike","Holland"};
  
    //Output the array
  for(int i=0;i<NUM;i++){
      cout<<names[i]<<"\t";
      if(i%5==4)cout<<endl;
  }
  //User selects the name;
  cout<<endl<<"Enter the full name of the person to be searched"<<endl;
  cin>>nameSel;
  
  //Sort the names
  sort(names,NUM);
  
  //Search the name

  if(binSrch(names,NUM,nameSel))cout<<endl<<"Name present in the array"<<endl;
  else cout<<"Person not found"<<endl;  
   
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
//Binary Search Function
bool binSrch(string array[], int last, string user){
     int first=0,   //First array element
         middle;    //midpoint of search

    //Check
    while(first<last){
        middle=(first+(last-1))/2;  //Calculate midpoint
        if(array[middle]==user)return true;
        else if(array[middle]>user)last=middle-1;
        else first=middle+1;
    }
    return false;
}

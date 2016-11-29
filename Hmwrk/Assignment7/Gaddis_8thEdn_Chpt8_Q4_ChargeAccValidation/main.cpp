/* 
   File:   main
   Author: Tejash Bhakta
   Created on November 26, 2016, 9:41 AM
   Purpose: Modify the program for Q1 so it performs a binary search to locate
            valid account numbers. Use selection sort algorithm to sort the array 
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void prntAry(int[],int);
void selcSrt(int[],int);
int check(int[],int,int);
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
    
    //Sort the Array
    selcSrt(number,SIZE);
    
    //Print the sorted array
    cout<<endl;
    prntAry(number,SIZE);
    cout<<endl;
    
    //Check if the number present in the array(LINEAR SEARCH)
    cout<<"Using Binary Search"<<endl;
    int pos=check(number,SIZE,user);
    cout<<"The number was found at "<<pos<<" position";
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
//function name selcSrt
//Input the array and its size
//Sorts the values in the array
void selcSrt(int array[],int n){
    int minInd, minVal;
    for(int i=0;i<n-1;i++){
        minInd=i;
        minVal=array[i];
        for(int index=i+1;index<n;index++){
            if(array[index]<minVal){
                minVal=array[index];
                minInd=index;
            }
        }
        array[minInd]=array[i];
        array[i]=minVal;
        
    }
}
//function name check
//Input the array of numbers, its size and the number from the user
//Output true if number present else false
int check(int array[],int last, int user){
    int first=0,   //First array element
        middle;    //midpoint of search
    bool won=false;
    //Check
    while(!won && first<last){
        middle=(first+(last-1))/2;  //Calculate midpoint
        if(array[middle]==user)return middle;
        else if(array[middle]>user)last=middle-1;
        else first=middle+1;
    }
    return -1;
}
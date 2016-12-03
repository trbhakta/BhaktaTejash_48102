/* 
 * File:   main.cpp
 * Author: Tejash Bhakta
 * Created on November 30th, 2016, 8:05 AM
 * Purpose:  Keep Counters of the comparison by select search and binary search
 */

//System Libraries Here
#include <iostream>  //I/O
#include <cstdlib>   //Random
#include <ctime>     //Time
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void fillAry(int [],int);
void prntAry(int [],int);
bool linSrch(int [],int, int,int &);
void markSrt(int [],int);
bool binSrch(int [],int, int,int &);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    int const SIZE=100;
    int array[SIZE],utilize;
    int cnt=0, user;
    
    //Input or initialize values Here
    do{
        cout<<"How much of the array to utilize?"<<endl;
        cout<<"Choose a number between 2 and 100"<<endl;
        cin>>utilize;
    }while(utilize<2||utilize>100);
    
    //Fill the array
    fillAry(array,utilize);
    
    //Output Located Here
    prntAry(array,utilize);
    
    //Select a number
    cout<<"Select a number"<<endl;
    cin>>user;

    //Selection search
    cout<<"Linear Search"<<endl;
    if(linSrch(array,utilize,user,cnt))cout<<"The number was found after "<<cnt+1<<" searches"<<endl;
    else cout<<"Number not found"<<endl;
    
    //Binary Search
    cnt=0;
    markSrt(array,utilize);
    cout<<endl<<"Binary Search after the sort"<<endl;
    prntAry(array,utilize);
    if(binSrch(array,utilize,user,cnt))cout<<"The number was found after "<<cnt+1<<" searches"<<endl;
    else cout<<"Number not found"<<endl;
    //Exit
    return 0;
}

void prntAry(int a[],int n){
    //Output Located Here
    cout<<"The Array"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%10==9)cout<<endl;
    }
    cout<<endl;
}

void fillAry(int a[],int n){
    //Fill the array
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;//Random 2 digit number
    }
}

bool linSrch(int array[],int n, int lttry,int &cnt){
    for(int i=0;i<n;i++){
        if(array[i]==lttry)return true;
        cnt++;
    }
    return false;
}

void markSrt(int a[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(a[i]>a[j]){
                a[i]=a[i]^a[j];
                a[j]=a[i]^a[j];
                a[i]=a[i]^a[j];
            }
        }
    }
}

bool binSrch(int array[],int last, int user,int &cnt){
    int first=0,   //First array element
        middle;    //midpoint of search
    bool won=false;
    //Check
    while(!won && first<last){
        middle=(first+(last-1))/2;  //Calculate midpoint
        if(array[middle]==user)won=true;
        else if(array[middle]>user)last=middle-1;
        else first=middle+1;
        cnt++;
    }
    return won;
}
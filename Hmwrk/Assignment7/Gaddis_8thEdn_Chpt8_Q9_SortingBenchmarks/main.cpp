/* 
 * File:   main.cpp
 * Author: Tejash Bhakta
 * Created on November 30, 2016, 12:04 PM
 * Purpose: counter to keep account of the swaps in bubble sort and selection sort
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cstdlib>    //Random number
#include <ctime>      //Time
#include <iomanip>    //Formate output
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void fillAry(int[], int[],int);
void cntrB(int[], int, int &);
void cntrS(int[], int, int &);
void PrntAry(int[], int[],int, int, int);
void PrntAry(int[], int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set random number seed:
    srand(static_cast<unsigned int> (time(0)));
    
    //Declaration of Variables
    const int SIZE = 100;        //Size of the array.
    int bubble[SIZE],            //Bubble sort test array.
        selSrt[SIZE];            //Select sort test array.
    int utilize = 20,            //Utilized portion of array.
        cntB,                    //Counter for Bubble Sort        
        cntS;                    //Counter for Selection Sort
    
    //Input values
    fillAry(bubble, selSrt, utilize);
    
    //Print unsorted array:
    PrntAry(bubble, utilize);
    
    //Bubble sort test
    cntrB(bubble, utilize, cntB);
    
    //Select sort test
    cntrS(selSrt, utilize, cntS);
    
    
    //Display the sorted arrays
    PrntAry(bubble, selSrt, utilize, cntB, cntS);
    
    //Exit Program
    return 0;
}

//Fill the three arrays with 20 random 2 digit numbers:
void fillAry(int ary1[], int ary2[], int n){
    for (int i=0; i<n; i++){
        ary1[i] = rand()%90+10;
        ary2[i] = ary1[i];
    } 
}

//Bubble sort:
void cntrB(int ary[], int n, int &counter){
    bool swap;
    int temp;
    counter=0;
    do{
        swap = false;
        for(int i=0; i<(n-1); i++){
            if (ary[i]>ary[i+1]){
                temp = ary[i];
                ary[i] = ary[i+1];
                ary[i+1] = temp;
                swap = true;
                counter++;
            }
        }
    }while(swap);
    cout<<"Bubble sort Swaps: "<<counter<<endl;
}

//Select sort:
void cntrS(int ary[], int n, int &counter){
     int minInd;
     int minVal;
     counter=0;
    for(int i=0;i<n-1;i++){
        minInd=i;
        minVal=ary[i];
        for(int index=i+1;index<n;index++){
            if(ary[index]<minVal){
                minVal=ary[index];
                minInd=index;
                counter++;
            }
        }
        ary[minInd]=ary[i];
        ary[i]=minVal;
        
    }
    cout<<"Selection sort Swaps: "<<counter<<endl;
}

//Print the unsorted arrays:
void PrntAry(int ary[], int n){
    cout << "The array the sorting algorithms must sort :" << endl;
    for (int i=0;i<n;i++){
        cout<<setw(3)<<ary[i];
        if(i%5==4)cout<<endl;
    }
    cout << endl;
}

//Print the arrays:
void PrntAry(int ary[], int ary2[], int n, int cnt1, int cnt2){
    cout << endl << "Bubble sort Swaps:"<<cnt1<< endl;
    for (int i=0;i<n;i++){
        cout<<setw(3)<<ary[i];
        if(i%5==4) cout << endl;
    }
    cout << endl;
    
    cout << "Select sort :" << cnt2 << " switches" << endl;
    for (int i=0;i<n;i++){
        cout<<setw(3)<<ary2[i];
        if(i%5==4)cout<<endl;
    }
}
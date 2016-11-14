/* 
   File:   main
   Author: Tejash Bhakta
   Created on November 14, 2016, 11:41 AM
   Purpose: 2D Array Operations
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cTime>
#include <cstdlib>
#include <iomanip>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const int COLS=5;
//Function prototypes
int getTot(int[][COLS]);
float getAvg(int[][COLS]);
int rowTot(int[][COLS],int);
int colTot(int[][COLS],int);
int highRow(int[][COLS],int);
int lowRow(int[][COLS],int);
void fillAry(int[][COLS]);
void dispAry(int[][COLS]);

//Execution Begins Here!
int main(int argc, char** argv) { 
    //Set the random seed
    srand(static_cast<int>(time(0)));
    //Variable Declaration
    const unsigned int ROWS=5;
    int valTble[ROWS][COLS];
    
    //Fill Array with random numbers
    fillAry(valTble);
    
    //Display the Array
    dispAry(valTble);
    
    //Display Output
    cout<<"The Total of all the values in the Array = "<<getTot(valTble)<<endl;
    cout<<"The Average of the numbers in the Array  = "<<getAvg(valTble)<<endl;
    cout<<endl<<"Sum of values in following rows"<<endl;
    for(int i=0;i<ROWS;i++){
        cout<<"Row "<<i+1<<" = "<<rowTot(valTble,i)<<endl;
    }
    cout<<endl<<"Sum of values in following Columns"<<endl;
    for(int i=0;i<COLS;i++){
        cout<<"Column "<<i+1<<" = "<<colTot(valTble,i)<<endl;
    }
    cout<<endl<<"Highest Value"<<endl;
    for(int i=0;i<ROWS;i++){
        cout<<"Row "<<i+1<<" = "<<highRow(valTble,i)<<endl;
    }
    cout<<endl<<"Lowest Value"<<endl;
    for(int i=0;i<ROWS;i++){
        cout<<"Row "<<i+1<<" = "<<lowRow(valTble,i)<<endl;
    }

    //Exit Program
    return 0;
}

//function getTot
//Inputs 2d array
//Output the total of the values in the array
int getTot(int table[][COLS]){
    int sum=0;
    for(int row=0;row<5;row++){
        for(int col=0;col<COLS;col++){
            sum+=table[row][col];
        }
    }
    return sum;
}

//function getAvg
//Inputs 2d array
//Output the average of the values in the array
float getAvg(int table[][COLS]){
    int sum=0;
    for(int row=0;row<5;row++){
        for(int col=0;col<COLS;col++){
            sum+=table[row][col];
        }
    }
    return 1.0f*sum/25;
}
//function rowTot
//Inputs 2d array, and the row number
//Output the total of the row
int rowTot(int table[][COLS],int nrow){
    int sum=0;
    for(int row=nrow;row<nrow+1;row++){
        for(int col=0;col<COLS;col++){
            sum+=table[row][col];
        }
    }
    return sum;
}

//function colTot
//Inputs 2d array, and the col number
//Output the total of the column
int colTot(int table[][COLS],int ncol){
    int sum=0;
    for(int col=ncol;col<ncol+1;col++){
        for(int row=0;row<5;row++){
            sum+=table[row][col];
        }
    }
    return sum;
}

//function highRow
//Inputs 2d array, and the row number
//Output the highest number in the following row
int highRow(int table[][COLS],int nrow){
    int high=table[nrow][0];
    for(int row=nrow;row<nrow+1;row++){
        for(int col=0;col<COLS;col++){
            if(table[row][col]>high)high=table[row][col];
        }
    }
    return high;
}

//function lowRow
//Inputs 2d array, and the row number
//Output the highest number in the following row
int lowRow(int table[][COLS],int nrow){
    int low=table[nrow][0];
    for(int row=nrow;row<nrow+1;row++){
        for(int col=0;col<COLS;col++){
            if(table[row][col]<low)low=table[row][col];
        }
    }
    return low;
}
//function fillAry
//Fills the array with random 1 digit numbers
void fillAry(int valTble[][COLS]){
    for(int row=0;row<5;row++){
        for(int col=0;col<COLS;col++){
            valTble[row][col]=rand()%90+10;
        }
    }
}

//function dispAry
//Displays the array 
void dispAry(int valTble[][COLS]){
    for(int row=0;row<5;row++){
        for(int col=0;col<COLS;col++){
            cout<<setw(3)<<valTble[row][col]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
}
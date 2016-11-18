/* 
   File:   main
   Author: Tejash Bhakta
   Created on August 29, 2016, 9:41 AM
   Purpose: Simulating a magic Square 
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cTime>      //Time Fumction
#include <cstdlib>    //C Standard Library
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const int COLS=3;

//Function prototypes
bool check(int[][COLS],int);
void fillAry(int[][COLS],int);
void prntAry(int[][COLS],int);
void mgcSqr(int[][COLS],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Setting the random number seed
    srand(static_cast<int>(time(0)));
    
    //Declaration of Variables
    const int ROWS=3;
    int square[ROWS][COLS];
   
    //Input values
    fillAry(square,COLS);

    //Print the Array
    prntAry(square,COLS);
    
    //Check whether magic Square
    mgcSqr(square,COLS);
    
    //Exit Program
    return 0;
}
void fillAry(int sqre[][COLS],int cols){
    int random;
    int count=0;
    bool chk;
    
    for(int row=0;row<3;row++){
        for(int col=0;col<COLS;col++){
            do{
                random=rand()%9+1;
                chk=check(sqre,random);
            }while(chk);
            sqre[row][col]=random;
        }
    }
}

bool check(int sqre[][COLS],int num){
    int count=0;
    bool chk=false;
    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            if(sqre[row][col]==num)return true;
            else continue;
        }
    }
    return chk;
}

void prntAry(int sqre[][COLS],int COLS){
    for(int row=0;row<3;row++){
        for(int col=0;col<COLS;col++){
            cout<<sqre[row][col]<<" ";
        }
        cout<<endl;
    }
}

void mgcSqr(int sqre[][COLS], int COLS){
    int total=0;
    int count=0;
    //Checking the rows
    for(int row=0; row<3;row++){
        for(int col=0; col<COLS;col++){
            total+=sqre[row][col];
        }
        cout<<"Total Row "<<row+1<<": "<<total<<endl;
        if(total==15){
            total=0;
            count++;
            continue;
        }
        else break;
    }
    //Checking the columns
    total=0;
    for(int col=0; col<COLS; col++){
        for(int row=0;row<3; row++){
            total+=sqre[row][col];
        }
        cout<<"Total Column "<<col+1<<": "<<total<<endl;
        if(total==15){
            total=0;
            count++;
            continue;
        }
        else break;
    }
    //Checking diagonally
    total=sqre[0][0]+sqre[1][1]+sqre[2][2];
    cout<<"Diagonal ltr Total: "<<total<<endl;
    if(total==15)count++;
    total=sqre[0][2]+sqre[1][1]+sqre[2][0];
    if(total==15)count++;
    cout<<"Diagonal rtl Total: "<<total<<endl<<endl;
    //check all the totals
    if(count==8)cout<<"Magic Square"<<endl;
    else cout<<"Not a Magic Square"<<endl;
}
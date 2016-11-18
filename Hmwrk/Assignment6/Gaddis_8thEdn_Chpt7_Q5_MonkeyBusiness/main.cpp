/* 
  File:   Monkey Business
  Author: Tejash Bhakta
  Created on November 18, 2016, 12:34 PM
  Purpose Maintain a 3x5 array of three monkeys and monitor their eating habits 
 */

#include <iostream>   //Input/Output objects

using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const int DAYS  = 5;

//Function prototypes
float avg(float [][DAYS], int);    //Average amount of food eaten per day by the monkeys
float min(float [][DAYS], int); //Least amount of food eaten during the week by any one monkey
float max(float [][DAYS], int); //Greatest amount of food eaten during the week by any one monkey

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    const int MONKS=3;
    float food[MONKS][DAYS];

    //Input values
    for (unsigned int row = 0; row < MONKS; row++){
        cout<<"Food eaten by Monkey "<<row+1<<endl;
        for (unsigned int col = 0; col < DAYS; col++){
            do {
                cout<<"Day "<<col+1<<": ";
                cin >> food[row][col];
            } while(food[row][col]<0);
        }
    }

    //Display Output
    cout<<endl<<"MONKEY REPORT"<<endl;
    cout << "The average amount of food/day "<<avg(food,MONKS)<<" lbs."<<endl;
    cout << "Least amount of food eaten/week "<<min(food,MONKS)<<" lbs."<<endl;
    cout << "Greatest amount of food eaten/week "<<max(food, MONKS)<<" lbs."<<endl;

    //Exit Program
    return 0;
}

float avg(float food[][DAYS], int row){
    float tot = 0;
    
    for (int row=0; row<DAYS; row++){
        for (int col=0; col<row; col++){
            tot += food[row][col];
        }
    }
    cout<<"Total food eaten "<<tot<<" lbs"<<endl;
    return tot / DAYS;
}

float min(float food[][DAYS], int row){
    float min = food[0][0];
    
    for (int rw=0; rw<row; rw++){
        for (int col=0; col<DAYS; col++){
            if (food[rw][col]<min) min=food[rw][col];
        }
    }
    return min;
}

float max(float food[][DAYS], int row){
    float max = food[0][0];
    
    for (int rw=0; rw<row; rw++){
        for (int col=0; col<DAYS; col++){
            if (food[rw][col]>max) max=food[rw][col];
        }
    }
    return max;
}
/* 
 * File:   GreaterN
 * Author: Tejash Bhakta
 * Created November 18, 2016, 04:06 PM
 * PURPOSE: Display the numbers from the array which are geater than the user number
*/  
#include <iostream>   //Input/Output objects
#include <cstdlib>    //Random number generator
#include <cmath>      //Time

using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
unsigned char SIZE = 10;

//Function prototypes
void numGrtr(int [],int,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned>(time(0)));

      //declaration of variables
      const int SIZE=5;
      int array[SIZE], number;

      //fill array
      for(int i=0;i<SIZE;i++){
          array[i]=rand()%90+10;
      }

      //display the array
      for(int i=0; i<SIZE; i++){
          cout<<array[i]<<std::endl;
      }
      //Taking a number from the user
      cout<<"Enter any number"<<endl;
      cin>>number;

    //Displaying the numbers greater than the user's number
      cout<<"The numbers greater than "<<number<<" are ";
      numGrtr(array,SIZE,number);

  //Exit Program
  return 0;
}

void numGrtr(int a[],int s,int n){
 for(int i=0; i<s; i++){
  if(a[i]>n)cout<<a[i]<<" ";
 }
}
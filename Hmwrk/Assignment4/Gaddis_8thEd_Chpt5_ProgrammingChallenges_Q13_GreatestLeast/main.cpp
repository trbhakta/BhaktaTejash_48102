/* 
   File:   main
   Author: Tejash Bhakta
   Created on October 11, 2016, 5:41 PM
   Purpose: To identify the maximum and minimum from the list of numbers input by user 
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    short num, range, max=0, min=0;   //Number, maximum number and minimum number
    char yn;
    
    //Input values and validations
    do{
        cout<<"How many numbers you want to enter?"<<endl;
        cin>>range;
       
        for(int i=1; i<=range; i++){
            cout<<"Enter number "<<i<<endl;
            cin>>num;
         
      //Comparing values for max and min
            if      (num>max) max=num;
            else if (num<max) min=num;
            else     continue;
            
        }
        
    //Display Output
        cout<<"The maximum number is "<<max<<endl;
        cout<<"The minimum number is "<<min<<endl;
        
    //Program Continuation    
        cout<<endl<<"Do you want to continue?"<<endl;
        cin>>yn;
    }while(yn='y' || yn=='Y');
    
    
    //Exit Program
    return 0;
}

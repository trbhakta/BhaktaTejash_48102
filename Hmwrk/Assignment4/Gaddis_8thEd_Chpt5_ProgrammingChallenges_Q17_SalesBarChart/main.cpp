/* 
 * File:   main.cpp
 * Author: Tejash Bhakta
 * Created on October 13, 2016, 12:07 PM
 * Purpose:  To show the sales report of different stores in bar chart
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables


//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
   int store1, store2, store3, store4, store5; //Sales of the five stores
   int numAstrk;
    
    //Input the sales for the stores
   cout<<"Enter today's sales for store 1 : ";
   cin>>store1;
   
   cout<<"Enter today's sales for store 2 : ";
   cin>>store2;
   
   cout<<"Enter today's sales for store 3 : ";
   cin>>store3;
   
   cout<<"Enter today's sales for store 4 : ";
   cin>>store4;
   
   cout<<"Enter today's sales for store 5 : ";
   cin>>store5;
    
  
   cout<<"SALES BAR CHART"<<endl;
   cout<<"(Each * = $100)"<<endl;
   for(int i=1; i<=5; i++){
       switch(i){
           case 1 :  cout<<"Store 1: ";
                     numAstrk=store1/100;
                     for(int i=1; i<=numAstrk; i++){
                         cout<<"*";
                     }
                     break;  
           case 2 :  cout<<"Store 2: ";
                     numAstrk=store2/100;
                     for(int i=1; i<=numAstrk; i++){
                         cout<<"*";
                     }
                     break;
           case 3 :  cout<<"Store 3: ";
                     numAstrk=store3/100;
                     for(int i=1; i<=numAstrk; i++){
                         cout<<"*";
                     }
                     break;
           case 4 :  cout<<"Store 4: ";
                     numAstrk=store4/100;
                     for(int i=1; i<=numAstrk; i++){
                         cout<<"*";
                     }
                     break;
           case 5 :  cout<<"Store 5: ";
                     numAstrk=store5/100;
                     for(int i=1; i<=numAstrk; i++){
                         cout<<"*";
                     }
                     break;          
       }
      cout<<endl;
   }
       
   
    
    //Output Located Here
  

    //Exit
    return 0;
}


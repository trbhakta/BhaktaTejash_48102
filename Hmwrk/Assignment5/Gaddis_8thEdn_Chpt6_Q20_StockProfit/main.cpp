/* 
   File:   main
   Author: Tejash Bhakta
   Created October 31, 2016, 9:41 AM
   Purpose: To calculate sales profit 
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>    //Formatting
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
float profit(int,float,float,float,float);
//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declaration of Variables
    float purPrc, purCom,    //Purchase Price, Commission Price
          salPrc, salCom,    //Sales Price, Sales Commission
          proLos;            //Profit or Loss
    int   numShre;           //Number of Shares
    
    //Input values
   do{
       cout<<"Enter the number of shares purchased or owned: ";
        cin>>numShre;
        cout<<"Purchase Price per Share: ";
        cin>>purPrc;
        cout<<"Total Commission paid on Purchase: ";
        cin>>purCom;
        cout<<"Sale price per share: ";
        cin>>salPrc;
        cout<<"Total Commision paid on Sale: ";
        cin>>salCom;
        cout<<"\n";
   }while(numShre<=0 || purPrc<0 || salPrc<0);
   
    //Output Profit or Loss
   proLos=profit(numShre,purPrc,purCom,salPrc,salCom);
   if(proLos<0)cout<<"A Loss of $"<<proLos<<endl;
   else cout<<"A Profit of $"<<proLos<<endl;

    //Exit Program
    return 0;
}

//Function profit
//Input number of shares, purchase price and commission and sale price and commission
//Returns Profit or Loss
float profit(int ns,float pp, float pc, float sp, float sc){
    return ((ns*sp)-sc)-((ns*pp)+pc);
}

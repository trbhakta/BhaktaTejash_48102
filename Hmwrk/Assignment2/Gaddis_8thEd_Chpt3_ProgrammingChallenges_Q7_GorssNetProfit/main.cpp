/* 
   File:   main
   Author: Tejash Bhakta
   Created on September 25, 2016, 9:41 PM
   Purpose: To calculate the gross box office profit 
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>    //Formatting
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const int PERCENT =100; //Conversion percentage
//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    unsigned short adltTkt, chldTkt;                         //adult ticket, child ticket
    string           mvieNme;                                 //Movie Name
    float          prcAdl=10.0f, prcChld=6.0f, grssPft,    //Price of adult and child tickets, Gross profit,
                   netPft, amtDist, percDist=20.0f;       //net Profit, Amount paid to Distributor, percent to distributor
   
    //Input values
    cout<<"Enter the name of the movie"<<endl;
    cin>>mvieNme;
    
    cout<<"Enter number of adult ticket sold"<<endl;
    cin>>adltTkt;
    
    cout<<"Enter number of children ticket sold"<<endl;
    cin>>chldTkt;
    
    //Process values -> Map inputs to Outputs
    grssPft =(adltTkt*prcAdl)+(chldTkt*prcChld);      //Gross Profit Amount
    netPft  = grssPft*percDist/PERCENT;               //20% kept by the theater
    amtDist = grssPft-netPft;                         //Amount given to Distributor
    
    //Display Output
    cout<<"Name of the movie           : "<<mvieNme<<endl;
    cout<<"Price of Adult Ticket       : $"<<setw(8)<<prcAdl<<endl;
    cout<<"Price of Child Ticket       : $"<<setw(8)<<prcChld<<endl;
    cout<<"Number of Adult Ticket sold :  "<<setw(8)<<adltTkt<<endl;
    cout<<"Number of Child Ticket sold :  a"<<setw(8)<<chldTkt<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"Gross Profit                : $"<<setw(8)<<grssPft<<endl;
    cout<<"Net Box Office Profit       : $"<<setw(8)<<netPft<<endl;
    cout<<"Amount paid to Distributor  : $"<<setw(8)<<amtDist<<endl;
    //Exit Program
    return 0;
}

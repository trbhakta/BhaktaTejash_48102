/* 
   File:   main
   Author: Tejash Bhakta
   Created October 31, 2016, 5:00 PM
   Purpose: Paint Job Estimator 
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>    //Formatting
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
void  paintJob(int,float);
float sqft(int);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    int   numRoom;
    float sqreFt,prcPaint;
    
    //Input values
    do{
        cout<<"Enter the rooms to be painted"<<endl;
        cin>>numRoom;
        cout<<"Enter the price of paint per gallon"<<endl;
        cin>>prcPaint;
    }while(numRoom<1 && prcPaint<10);
    
    //Process values 
    paintJob(numRoom,prcPaint);
    
    
    //Exit Program
    return 0;
}

//Function sqft
//Input number of rooms
//Output the total square feet of all the walls
float sqft(int rooms){
    float area,sqft;
    for(int i=1; i<=rooms; i++){
        cout<<"Enter the area of wall in Room "<<i<<endl;
        cin>>area;
        sqft+=area;
    }
    return sqft;
}

//Function paintJob
//Input number of rooms , price of paint per gallon
//Outputs the estimate total 
void paintJob(int rooms, float price){
    //Declare variables
    float galPnt, cstPnt,
          labChg, 
          total,  totArea;  
    int   labHrs;
    
    //Calculations
    totArea=sqft(rooms);
    galPnt=totArea/110;
    cstPnt=galPnt*price;
    labHrs=totArea/(110/8);
    labChg=labHrs*25.0f;
    total=cstPnt+labChg;
    
    //Display Output
    cout<<fixed<<setprecision(2);
    cout<<"Gallons of paint required:     "<<setw(6)<<galPnt<<" gal"<<endl;
    cout<<"The hours of labor required:   "<<setw(6)<<labHrs<<" hrs"<<endl;
    cout<<"The total cost of the paint: $ "<<setw(6)<<cstPnt<<endl;
    cout<<"Labor Charges:               $ "<<setw(6)<<labChg<<endl;
    cout<<"Total Cost of the paint job: $ "<<setw(6)<<total<<endl;
}
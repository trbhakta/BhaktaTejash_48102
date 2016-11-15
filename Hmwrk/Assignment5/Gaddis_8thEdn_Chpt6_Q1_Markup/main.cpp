/* 
 * File:   main.cpp
 * Author: Tejash Bhakta
 * Created on November 5, 2016, 5:37 PM
 * Purpose : Mark up price
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>    //Format
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const float PERCENT = 100.0f;

//Function prototypes
float prcRtl(float, float);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    float wCost, markup, price; //Whole sale cost, mark up, and retail price.
    
    //Input values
    do{
        cout<<"Enter the whole sale price of the item"<<endl;
        cin>>wCost;
    }while(wCost < 0);
    
    do{
        cout << "Input the mark up cost of the item"<<endl;
        cin >> markup;
    }while (markup < 0);
    
    //Process values -> Map inputs to Outputs
    price = prcRtl(wCost, markup);
    
    //Display Output
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"The retail price will be "<<"$"<<price<<endl;

    //Exit Program
    return 0;
}

//Retail price calculation:
float prcRtl(float cost, float Mp){
    return ((cost * Mp)/PERCENT) + cost;
}
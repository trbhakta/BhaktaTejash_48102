/* 
   File:   main
   Author: Tejash Bhakta
   Created on October 17th, 11:37 AM
   Purpose:  Menu without Functions for Assignment 4
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cstdlib>    //Random number generator
#include <ctime>      //Time
#include <iomanip>    //formatting
#include <cMath>      //Math library
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const int PERCENT=100;  //Conversion of percentage

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    int menuItm;    //Choice from menu
    
    //Loop until users exits
    do{
    
        //Prompt for problem for user input
        cout<<"1.  Type 1  for Problem Savitch 9th Ed Chap 4 Programming Challenges Ques 1"<<endl;
        cout<<"2.  Type 2  for Problem Gaddis_8thEd_Chpt5_ProgrammingChallenges_Q1_SumOfNumbers"<<endl;
        cout<<"3.  Type 3  for Problem Gaddis_8thEd_Chpt5_ProgrammingChallenges_Q4_caloriesBurned"<<endl;
        cout<<"4.  Type 4  for Problem Gaddis_8thEd_Chpt5_ProgrammingChallenges_Q5_MembershipFeesIncrease"<<endl;
        cout<<"5.  Type 5  for Problem Gaddis_8thEd_Chpt5_ProgrammingChallenges_Q6_DistanceTravelled"<<endl;
        cout<<"6.  Type 6  for Problem Gaddis_8thEd_Chpt5_ProgrammingChallenges_Q7_PenniesForDay"<<endl;
        cout<<"7.  Type 7  for Problem Gaddis_8thEd_Chpt5_ProgrammingChallenges_Q13_GreatestLeast"<<endl;
        cout<<"8.  Type 8  for Problem Gaddis_8thEd_Chpt5_ProgrammingChallenges_Q17_SalesBarChart"<<endl;
        cout<<"9.  Type 9  for Problem Gaddis_8thEd_Chpt5_ProgrammingChallenges_Q21_RandomNumberGuess"<<endl;
        cout<<"10. Type 10 for Problem Gaddis_8thEd_Chpt5_ProgrammingChallenges_Q23_PatternDisplys"<<endl;
        cin>>menuItm;

        //Go to the Problem
        switch(menuItm){
            case 1:{
                  //Declaration of Variables
                  float prcHouse, downPmt,              //Price of House, Down Payment
                        loanBal,  loanInt, anlMort,     //Initial Loan Payment, Interest, Annual mortgage
                        taxSave, annualCst;             //Tax Savings, Annual Cost
                  char yn;  
                    //Purpose of Program 
                  cout<<"This program calculates the annual cost of your house after tax cost"<<endl;


                    //All calculations
                    do{
                       //Validations 
                        do{
                      cout<<"Input the price of your house"<<endl<<"$ ";
                      cin>>prcHouse;

                      cout<<"Input your Down Payment"<<endl<<"$ ";
                      cin>>downPmt;
                    }while(prcHouse<=0);

                       //Calculations
                        loanBal=prcHouse-downPmt;         //Calculation of initial loan payment
                        loanInt=6*loanBal/100;            //Loan Interest
                        taxSave=35*loanInt/PERCENT;       //Calculation of tax savings
                        anlMort=(3*loanBal/100)+loanInt;  //Annual Mortgage
                        annualCst=anlMort-taxSave;        //Annual Cost

                        //Output the values and calculation
                       cout<<fixed<<setprecision(2);
                       cout<<"The price of house   = $"<<setw(8)<<prcHouse<<endl;
                       cout<<"Down Payment         = $"<<setw(8)<<downPmt<<endl;
                       cout<<"Initial Loan Balance = $"<<setw(8)<<loanBal<<endl;
                       cout<<"Tax Savings          = $"<<setw(8)<<taxSave<<endl;
                       cout<<"Loan Interest Amount = $"<<setw(8)<<loanInt<<endl;
                       cout<<"Annual Mortgage      = $"<<setw(8)<<anlMort<<endl;
                       cout<<"Annual Cost after tax= $"<<setw(8)<<annualCst<<endl;

                       //Continue of program

                      cout<<endl<<"Do you wish to compute the cost again?(y/n)"<<endl;
                      cin>>yn;
                    }while(yn=='y' || yn=='Y');
                break;
            }
            case 2:{
                  //Declaration of Variables
                    int numRange, sum;   //The range from 0,number to find the sum, Sum of the numbers
                    //Validations and calculations
                    do{
                       cout<<"Input the number till which to find the sum"<<endl;
                       cin>>numRange;
                    }while(numRange<0);

                    //The sum of the consecutive numbers
                    for(int i=1; i<=numRange; i++){
                           sum+=i;
                       }
                      cout<<"The sum of numbers from 0 to "<<numRange<<" is "<<sum<<endl<<endl; 
                break;
            }
            case 3:{
                cout<<"Inside Problem C"<<endl;
                 //Declaration of Variables
                    float calories, totCal;   //Calories in a minute , total calories
                    int minutes;

                    //Input calories per minute and total minutes
                    do{
                        cout<<"Enter the amount of calories burned in a minute"<<endl;
                        cin>>calories;

                        cout<<"Enter the number of minutes exercised"<<endl;
                        cin>>minutes;
                    }while(calories<0 || minutes<0);

                    //Output the calories per minute
                    cout<<"Amount of calories burned in a minute = "<<setw(6)<<calories<<" cal"<<endl;
                    //Process the calories per every 5 min
                        for(int i=5; i<=minutes; i+=5){
                            totCal=calories*i;
                            cout<<"Amount of calories burned in "<<i<<" mins ="<<setw(6)<<totCal<<" Cal"<<endl;

                        }
                break;
            }
            case 4:{
                cout<<"Inside Problem D"<<endl;
                
                    //Declaration of Variables
                    float memPrice, rateInc=4.0f, prcInc; //Membership Price, Rate of increase, Price Increased
                    short numYrs;                 //Number of years

                    //Input number and validation
                    do{
                        cout<<"Enter the price of membership : ";
                        cin>>memPrice;

                        cout<<"Number of years the price rate increase : ";
                        cin>>numYrs;

                    }
                    while(numYrs<=0 || memPrice<=0);

                    //Process values 
                        for(int i=1; i<=numYrs; i++){
                            prcInc=(memPrice*rateInc/PERCENT)+memPrice;
                            cout<<fixed<<setprecision(2);
                            cout<<"The price after "<<i<<" year(s) at the rate of "<<rateInc<<"% would be $"<<setw(8)<<prcInc<<endl;
                            memPrice=prcInc;
                        }
                break;
            }
            case 5:{
                cout<<"Inside Problem E"<<endl;
                 //Declaration of Variables
                    float speed, distance; //Speed in mph, distance to be calculated
                    int  time;             //time traveled
                    //Input values and validations
                    do{
                        cout<<"Enter your average speed in mph"<<endl;
                        cin>>speed;

                        cout<<"Enter number of hours traveled"<<endl;
                        cin>>time;
                    }while(speed<0 || time<=1);

                    //output the format
                    cout<<" Hours       |"<<"Distance Travelled"<<endl;
                    cout<<"------------------------------------"<<endl;

                    //calculation of distance
                    for(int i=1; i<=time; i++){
                        distance=speed*i;
                        cout<<"  "<<i<<"          |   "<<setw(5)<<distance<<" miles"<<endl;
                    }
                break;
            }
            case 6:{
                cout<<"Inside Problem F"<<endl;
                    int numDays;    //no. of days worked
                    int pennies=1;  //Total pennies starting with day 1
                    long totPenny=0;// Total Pennies
                    //Values and validations
                    do{
                        cout<<"Enter the number of days worked : ";
                        cin>>numDays;
                    }
                    while(numDays<=0 || numDays>31);

                    cout<<"Penny for Day 1  3 = 1"<<endl;
                    //Calculating pennies for number of days worked
                        for(int i=2; i<=numDays; i++){
                            pennies*=2;
                            cout<<"Pennies for Day "<<i<<" = "<<pennies<<endl;
                            totPenny+=pennies;
                        }
                    //Display Output
                    cout<<endl<<"Number of days worked = "<<numDays<<endl;
                    cout<<"Total pennies altogether = "<<totPenny<<" pennies"<<endl;
                    cout<<"which equals to $"<<totPenny/100<<" dollars and "<<totPenny%100<<" cents.";
                break;
            }
            case 7:{
                cout<<"Inside Problem G"<<endl;
                //Declaration of Variables
                short num, range, max=0, min=0;   //Number, maximum number and minimum number
                char yn;

                //Input values and validations
                do{
                    cout<<"How many numbers you want to enter?"<<endl;
                    cin>>range;

                    cout<<"Enter number 1"<<endl;
                    cin>>num; max=num; min=num;
                    for(int i=1; i<=range-1; i++){
                        cout<<"Enter number "<<i+1<<endl;
                        cin>>num;

                  //Comparing values for max and min
                        if      (num>max) max=num;
                        else if (num<min) min=num;
                        else     continue;

                    }

                //Display Output
                    cout<<"The maximum number is "<<max<<endl;
                    cout<<"The minimum number is "<<min<<endl;

                //Program Continuation    
                    cout<<endl<<"Do you want to continue?"<<endl;
                    cin>>yn;
                }while(yn='y' || yn=='Y');
                break;
            }
            case 8:{
                cout<<"Inside Problem H"<<endl;
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
                break;
            }
            case 9:{
                cout<<"Inside Problem I"<<endl;
                //Set the random number seed
                    srand(static_cast<unsigned int>(time(0)));

                    //Declare all Variables Here
                    int range, nGuess;
                    int number, answer;

                    //Input or initialize values Here
                    cout<<"This is the guessing game"<<endl;
                    cout<<"Choose a range for the number to guess"<<endl;
                    cin>>range;

                    //Process/Calculations Here
                    nGuess=log(range)/log(2)+1;
                    cout<<"You have "<<nGuess<<" guesses to find the random number"<<endl;
                    number=rand()%(range+1); // (0, range))

                    //Display Results of each guess
                    for(int guess =1; guess<=nGuess; guess++){
                        cout<<"Input your guess"<<endl;
                        cin>>answer;
                        if(answer>number) cout<<"Guess too high"<<endl;
                        else if(answer<number) cout<<"Guess too low"<<endl;
                        else {
                            cout<<"You guessed the number in "<<guess<<" guesses";
                            exit(0);
                        }
                    }
                    cout<<"Too many guesses";

                break;
            }
            case 10:{
                cout<<"Inside Problem J"<<endl;
                //Declare all Variables Here
                    short rows; //Desired rows by user

                    //Taking values from user and validations

                    do{
                        cout<<"Enter the number of rows you wish to see in the pattern"<<endl;
                        cin>>rows;
                    }
                    while(rows<=0);

                    //Loop iterations for pattern A 
                    //*
                    //**
                    //***    
                    cout<<"Pattern A"<<endl;
                        for(int i=1; i<=rows ; i++){
                           for(int j=1;j<=i;j++){
                               if(j<=i) cout<<"*";
                               else     cout<<" ";
                            }
                          cout<<endl;
                        } 

                    //Loop Iteration for pattern B
                    //***
                    //**
                    //*
                    cout<<endl<<"Pattern B"<<endl;
                        for(int i=1; i<=rows ; i++){
                            for(int j=rows;j>=1;j--){
                                if(i<=j) cout<<"*";
                                else     cout<<" ";
                            }
                          cout<<endl;  
                        }

                    //Loop Iteration for pattern C
                    /*  *
                       **
                      ***
                    */
                    cout<<endl<<"Pattern C"<<endl;
                        for(int i=rows; i>=1; i--){
                            for(int j=1; j<=rows; j++){
                                if(i>j) cout<<" ";
                                else    cout<<"*";
                            }
                          cout<<endl;
                        }

                    //Loop Iteration for pattern D
                    /* ***
                       **
                       *
                    */
                    cout<<endl<<"Pattern D"<<endl;
                        for(int i=rows; i>=1; i--){
                            for(int j=rows; j>=1; j--){
                                if(i>=j) cout<<"*";
                                else    cout<<" ";
                            }
                          cout<<endl;  
                        }
                break;
            }//End Case
        }//End the Switch/Case
    }while(menuItm>0&&menuItm<=10);//Ends the Do-While Loop

    //Exit Program
    return 0;
}
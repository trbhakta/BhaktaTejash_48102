/* 
 * File:   main.cpp
 * Author: Tejash Bhakta
 * Created on November 3, 2016, 12:07 AM
 * Purpose:  Average of 5 scores by dropping highest and lowest score
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables


//Function Prototypes Here
void getScore(float &, float &, float &, float &, float &);
void calScore(float,float,float,float,float);
float  findLow(float,float,float,float,float);
float  findHigh(float,float,float,float,float);
//Program Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare all Variables Here
    float s1, s2, s3, s4, s5;  //Score from 5 judges
    
    //Input the scores;
    getScore(s1,s2,s3,s4,s5);
    
    //Calculating Average minus Highest and Lowest Score
    calScore(s1,s2,s3,s4,s5);
    
    //Exit
    return 0;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Get Scores ***************************************
void getScore(float &s1, float &s2, float &s3, float &s4, float &s5){
    //Get the score
    float score;
    do{
        cout<<"Score from Judge 1 (1-10)"<<endl;
        cin>>score;
    }while(score<0 || score>10);
    s1=score;
    do{
        cout<<"Score from Judge 2 (1-10)"<<endl;
        cin>>score;
    }while(score<0 || score>10);
    s2=score;
    do{
        cout<<"Score from Judge 3 (1-10)"<<endl;
        cin>>score;
    }while(score<0 || score>10);
    s3=score;
    do{
        cout<<"Score from Judge 4 (1-10)"<<endl;
        cin>>score;
    }while(score<0 || score>10);
    s4=score;
    do{
        cout<<"Score from Judge 5 (1-10)"<<endl;
        cin>>score;
    }while(score<0 || score>10);
    s5=score;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************* Calculate Average **********************************
void calScore(float s1,float s2,float s3,float s4,float s5){
    float avg=(s1+s2+s3+s4+s5-findLow(s1,s2,s3,s4,s5)-findHigh(s1,s2,s3,s4,s5))/3;
    
    //Display the Average
    cout<<fixed<<setprecision(2);
    cout<<"The average of the scores after dropping the lowest and"<<endl;
    cout<<"higest score is "<<avg;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************* Find and return low score **************************
float findLow(float s1,float s2,float s3,float s4,float s5){
    float min=s1;
    if(min>s2)min=s2;
    if(min>s3)min=s3;
    if(min>s4)min=s4;
    if(min>s5)min=s5;
    return min;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************* Find and return high score **************************
float findHigh(float s1,float s2,float s3,float s4,float s5){
    float max=s1;
    if(max<s2)max=s2;
    if(max<s3)max=s3;
    if(max<s4)max=s4;
    if(max<s5)max=s5;
    return max;
}
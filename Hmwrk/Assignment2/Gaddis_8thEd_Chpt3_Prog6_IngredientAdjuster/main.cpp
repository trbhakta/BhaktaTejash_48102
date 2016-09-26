/* 
   File:   main
   Author: Tejash Bhakta
   Created on September 22, 2016, 11:27 AM
   Purpose: To adjust the amount of ingredients to make certain amount of cookies 
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <iomanip>    //Foramtting Library
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const int COOKIES=48;   //Number of cookies for following ingredients
const float SUGAR=1.5f; //cups of sugar required for 48 cookies
const float BUTTER=1.0f;//cups of butter required for 48 cookies
const float FLOUR=2.75f;//cups of flour required for 48 cookies

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    int numCkie;          // Number of cookies desired by the user
    float reqSgr, reqBtr, reqFlr; //Required amount of Sugar, Butter and Flour    
    
    //Input values
    
    cout<<"How many cookies do you want to make?"<<endl; 
    cin>>numCkie;
    
    //Process values -> Map inputs to Outputs
    
    reqSgr=numCkie*SUGAR/COOKIES;
    reqBtr=numCkie*BUTTER/COOKIES;
    reqFlr=numCkie*FLOUR/COOKIES;
    
    //Display Output

    cout<<"Number of cookies to be made = "<<numCkie<<endl;
    cout<<setprecision(2)<<fixed;
    cout<<"Cups of Sugar required = "<<reqSgr<<" cups"<<endl;
    cout<<"Cups of Butter required = "<<reqBtr<<" cups"<<endl;
    cout<<"Cups of Flour required = "<<reqFlr<<" cups"<<endl;
    
    //Exit Program
    return 0;
}
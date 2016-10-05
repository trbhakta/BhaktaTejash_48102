/* 
   File:   main
   Author: Tejash Bhakta
   Created on October 4, 2016, 8:41 PM
   Purpose: Calculate the area of circle, rectangle or Triangle depending on user 
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cMath>      //Math Library
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const float PI=4*atan(1.0); //value of pie
//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    char numChoice;  //Choosing from 1 to 4
    
    //Obtaining values
    cout<<"Calculate the area of the following\n\n";
    cout<<"1. Calculate the area of a Circle\n";
    cout<<"2. Calculate the area of a Rectangle\n";
    cout<<"3. Calculate the area of a Triangle\n";
    cout<<"4. Exit\n\n";
    cout<<"Enter your choice (1-4)\n";
    cin>>numChoice;
    
    //Input Validations and processing
    if(numChoice =='1' || numChoice=='2' || numChoice=='3' || numChoice=='4'){
        float area;
        switch(numChoice){
            case '1':              //area of circle
                float radius;
                cout<<"Enter the radius in cms"<<endl;
                cin>>radius;
                if(radius>0) {
                    area=PI*pow(radius,2);
                    cout<<"Area of circle with radius "<<radius<<" cms is "<<area<<" cms^2"<<endl;            
                }
                else cout<<"Enter value greater than 0";
                break;
                
            case '2':              //area of rectangle
                float length, breadth;
                cout<<"Enter the length and breadth of rectangle in cms"<<endl;
                cin>>length>>breadth;
                if(length>0 && breadth>0){
                    area=length*breadth;
                    cout<<"Area of Rectangle"<<endl;
                    cout<<"Length :"<<length<<" cms"<<endl;
                    cout<<"Breadth:"<<breadth<<" cms"<<endl;
                    cout<<"Area   :"<<area<<" cms^2"<<endl;
                }
                else cout<<"Enter value greater than 0";
                break;
            
            case '3':             //area of triangle
                float base, height;
                cout<<"Enter the base and height of the triangle in cms"<<endl;
                cin>>base>>height;
                if(base>0 && height>0){
                    area=base*height*.5;
                    cout<<"Area of Triangle"<<endl;
                    cout<<"Base :"<<base<<" cms"<<endl;
                    cout<<"Height:"<<breadth<<" cms"<<endl;
                    cout<<"Area   :"<<area<<" cms^2"<<endl;
                }
                else cout<<"Enter value greater than 0";
                break;
            case '4':          //exit program
                cout<<"Exiting Program";
                return 0;
                break;   
        }
    }
    else cout<<"Choose the numbers from 1-4"<<endl;    
    //Display Output

    //Exit Program
    return 0;
}

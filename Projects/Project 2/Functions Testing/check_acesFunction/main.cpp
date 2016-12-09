/* 
 * File:   main.cpp
 * Author: Tejash Bhakta
 * Purpose: Test the aces function
            [If ace is present in any of the cards, its present value ie 11 gets
             reduced by 10 if the total hits above 21]
 * Created on December 6, 2016, 10:06 AM
 */

/*Program uses linear search to find the value '11' from the array
 which affects the total if the total is above 21 for a certain range*/
#include <cstdlib>
#include <iostream>
using namespace std;

//functions
void show(int [],int &,int);
void isAce(int [],int ,int &,int &);
int main(int argc, char** argv) {
    const int SIZE=5;
    int array[SIZE];
    int total;
    array[0]=11;
    array[1]=4;
    array[2]=3;
    //Calling function
    show(array,total,3);
    array[3]=10;
    array[4]=11;
    //Calling function
    show(array,total,5);
    

    return 0;
}
void isAce(int ary[],int n,int &tot,int &ace){
    for(int i=0;i<n;i++){
        if(ary[i]==11)ace++;
    }
    for(int j=1;j<=ace;j++){
        if(tot>21)tot=tot-10;
    }
}
void show(int array[],int &tot,int deal){
    int aces=0;
    tot=0;
    for(int i=0;i<deal;i++){
        cout<<array[i]<<" ";
        tot=tot+array[i];
    }
    cout<<endl;
    isAce(array,deal,tot,aces);
    cout<<"The total is "<<tot<<endl;
    cout<<"Cards contain "<<aces<<" ace(s)"<<endl;
}


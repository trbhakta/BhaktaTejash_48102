/* 
 * File:   main.cpp
 * Author: Tejash Bhakta
 * Purpose: Project 1--BlackJack Game
 * Created on October 16, 2016, 10:40 PM
 */


#include <iostream>   //Input/Output objects
#include <iomanip>    //Foramatting  
#include <fstream>    //File I/O   
#include <cTime>      //Time functoin for setting the seed of random numbers
#include <cstdlib>    //C standard Library for random numbers  


using namespace std;


//Constants
const int COLS=4;


//Function Prototypes
void display();
void seprtr();
char check(int);
char check(int,int);
void draw(int[],int,string &);
void stand(int [],int,string &);
void show(int[],int&,int,string);
void isAce(int[],int,int &,int &);
string digit(int);
//Main Program starts here
int main(int argc, char** argv) {
      //Random number generator
    srand(static_cast<unsigned int>(time(0)));
     //Declaration of variable
    const int GAME=20;
    int              game=0;
    float            totAmt=100, betPlcd;  //Total Winnings, Bet Placed
    unsigned short   menu;                  //Command for next bet 
    char             deal, chk;          //Deal next game, stores the status value
    string           name;                //Name of Player
    fstream in;   
    
    //Display Introduction
//    display();
    //Start the game        
    //Opening Commands
    do{
        //seprtr();
        cout<<"Choose from the menu"<<endl;
        cout<<"1. Start BlackJack <$100 included>"<<endl;
        cin>>menu;
        
        switch(menu){
            case 1:{
                deal='d';
                cout<<"Enter Player Name"<<endl;
                cin>>name;
                while(deal=='d'){
                    do{
                       game++;
//                       seprtr(); 
                       cout<<fixed<<setprecision(2);
                       cout<<"YOUR TOTAL right now is $"<<totAmt<<endl;
                       cout<<"Bet to be placed (min-10 && max-50)"<<endl;
                       cin>>betPlcd;
                    }while(betPlcd<10 || betPlcd>50 || betPlcd>totAmt);
                    
                //Variables for the game
                    const int SIZE=5;
                    int player[SIZE], dealer[SIZE];
                    int pTotal=0, dTotal=0;
                    int deals=0;
                    string pCard,dCard;
                    int report[GAME][COLS];
                    char cmd;
                    
                //Drawing the first two cards for player and dealer
                    for(int i=0;i<2;i++){
                        ++deals;
                        draw(player,deals,pCard);
                        draw(dealer,deals,dCard);
                    }
                //Show cards
                   cout<<name<<"'s Cards"<<endl; 
                   show(player,pTotal,deals,pCard);
                   //seprtr();
                   cout<<"Dealer's Cards"<<endl;
                   show(dealer,dTotal,deals,dCard);
                   //seprtr();
                    //chk=check(pTotal);
                    
                //If BlackJack
                    if(chk=='j')break;
                    else{
                        do{
                        cout<<"Do you want to hit(h), stand(s), or double down(d)?"<<endl;
                        cin>>cmd;
                        }while(cmd!='h'&&cmd!='s'&&cmd!='h');
                    }
                 //seprtr();  
                //Following commands
                    while(cmd=='h'){
                        ++deals;
                        draw(player,deals,pCard);
                        show(player,pTotal,deals,pCard);
                        //seprtr();
                        chk=check(pTotal);
                        if(chk=='b'){
                           // stand(dealer,dTotal,deals);
                            break;
                        }
                        
                        //Continue drawing?
                        do{
                        cout<<"Do you want to hit or stand?"<<endl;
                        cin>>cmd;
                        }while(cmd!='h' && cmd!='s');
                    }
                    /*if(cmd=='s'){
                        stand(dealer,dTotal,deals);
                        chk=check(pTotal,dTotal);
                    }
                    if(cmd=='d'){
                        
                    }*/
                }
            }break;
            case 2:{
            }
        }
        
    }while(menu>0 && menu<=2);
               
    


    //Exit Program
    return 0;
}


void draw(int array[],int pos,string &face){
    int numCrds=13;
    int selCrd=rand()%13+1;
    int value;
    if(selCrd==1){
        face=face+"Ace|";
        value=11;
    }
    else if(selCrd>1 && selCrd<=10){
        face=face+digit(selCrd);
        value=selCrd;
    }
    else if(selCrd==11){
        face=face+"Jack|";
        value=10;
    }
    else if(selCrd==12){
        face=face+"Queen|";
        value=10;
    }
    else if(selCrd==13){
        face=face+"King|";
        value=10;
    }
    array[pos-1]=value;
}
void show(int array[],int &tot,int deal,string face){
    int aces=0;
    tot=0;
    for(int i=0;i<deal;i++){
        tot=tot+array[i];
    }
    isAce(array,deal,tot,aces);
    cout<<face<<endl;
    cout<<"The total is "<<tot<<endl;
    cout<<"Cards contain "<<aces<<" ace(s)"<<endl;
}

string digit(int num){
    switch(num){
        case 2: return "Two|";
        case 3: return "Three|";
        case 4: return "Four|";
        case 5: return "Five|";
        case 6: return "Six|";
        case 7: return "Seven|";
        case 8: return "Eight|";
        case 9: return "Nine|";
        case 10: return "Ten|";
    }
}

char check(int pTotal){
    if(pTotal>21)return 'b';
    
}

void isAce(int ary[],int n,int &tot,int &ace){
    for(int i=0;i<n;i++){
        if(ary[i]==11)ace++;
    }
    for(int j=1;j<=ace;j++){
        if(tot>21)tot=tot-10;
    }
}
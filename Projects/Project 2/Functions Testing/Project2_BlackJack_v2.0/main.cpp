/* 
 * File:   main.cpp
 * Author: Tejash Bhakta
 * Purpose: Project 1--BlackJack Game
 * Created on October 16, 2016, 10:40 PM
 */

#include <iostream>   //Input/Output objects
#include <iomanip>    //Foramatting  
#include <cTime>      //Time functoin for setting the seed of random numbers
#include <cstdlib>    //C standard Library for random numbers  

using namespace std;
//user libraries

//Constants
const int COLS=4;

//Function Prototypes
void display();
void seprtr();
char check(int);
char check(int,int);
void pause(int);
void result(char,float &,float);
void draw(int[],int,string &);
void stand(int [],int &,string &,int);
void show(int[],int&,int,string);
void isAce(int[],int,int &,int &);
string digit(int);

//Main Program starts here
int main(int argc, char** argv) {
      //Random number generator
    srand(static_cast<unsigned int>(time(0)));
      //Declaration of variable
    int              game=0;
    float            totAmt=100, betPlcd;  //Total Winnings, Bet Placed
    char             deal, chk;          //Deal next game, stores the status value
    string           name;                //Name of Player
    
    //Display Introduction
//    display();
    //Start the game        
    //Opening Commands
        seprtr();
        
        //Start the Game
        deal='d';
        cout<<"Enter Player Name"<<endl;
        cin>>name;
        while(deal=='d'){
            game++;
            do{
               seprtr(); 
               cout<<endl<<fixed<<setprecision(2);
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
            char cmd;

        //Drawing the first two cards for player
            for(int i=0;i<2;i++){
                ++deals;
                draw(player,deals,pCard);
            }
        //Drawing dealers first card to keep second hiding
            draw(dealer,1,dCard);

        //Show cards and its total
           /*Player's Total*/
            seprtr();
           cout<<"      "<<name<<"'s Cards"<<endl; 
           show(player,pTotal,deals,pCard);
           /*Dealer's Total*/
           cout<<"      Dealer's Cards"<<endl;
           show(dealer,dTotal,1,dCard);

        //Close the deals if player hits blackJack   
        //If BlackJack
            if(pTotal==21){
                cout<<"****BlackJack****"<<endl;
                totAmt+=betPlcd*1.5;
            }
            else{
                do{
                cout<<"Do you want to hit(h), stand(s), or double down(d)?"<<endl;
                cin>>cmd;
                }while(cmd!='h'&& cmd!='s'&& cmd!='d');
            }
            seprtr();  

        //Following commands
            while(cmd=='h'){
                ++deals;
                draw(player,deals,pCard);
                cout<<"     "<<name<<"'s Cards"<<endl;
                show(player,pTotal,deals,pCard);
                chk=check(pTotal);
                if(chk=='b' || chk=='w'){
                    stand(dealer,dTotal,dCard,2);
                    chk=check(pTotal,dTotal);
                    break;
                }
                //Continue drawing?
                do{
                cout<<"Do you want to hit or stand?"<<endl;
                cin>>cmd;
                }while(cmd!='h' && cmd!='s');
                seprtr();
            }
            
        //If player stands     
            if(cmd=='s'){
                deals=2;
                stand(dealer,dTotal,dCard,deals);
                chk=check(pTotal,dTotal);
            }
        //If player double downs    
            if(cmd=='d'){
                ++deals;
                betPlcd*=2;   
                //Draw just 1 card
                draw(player,deals,pCard);
                cout<<"     "<<name<<"'s cards"<<endl;
                show(player,pTotal,deals,pCard);
                stand(dealer,dTotal,dCard,2);
                chk=check(pTotal,dTotal);
            }

            //Show the results according to check code
            //and update total
            cout<<name<<" total: "<<setw(6)<<pTotal<<endl;
            cout<<"Dealer total: "<<setw(6)<<dTotal<<endl;
            result(chk,totAmt,betPlcd);
            seprtr();
             
            //Display Total
             cout<<"The total Amount right now is "<<totAmt<<endl;
             if(totAmt<10){
                 cout<<"Sorry.Not Enough cash to carry on"<<endl;
                 break;
             }
            //Continue if enough cash
              do{cout<<"Next Deal 'd' or any key to exit"<<endl;
                cin>>deal;
                seprtr();
              }while(deal!='d');
        }
    
    //Exit Program
    exit(0);
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
    cout<<"Hand contain "<<aces<<" ace(s)"<<endl;
    seprtr();
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
    if(pTotal==21)return 'w';
    
}
char check(int pTotal,int dTotal){
    if(dTotal<=21 && pTotal<=21){
        if(pTotal>dTotal)return 'w';
        else if(dTotal>pTotal)return 'l';
        else if(dTotal==pTotal)return 'p';
    }
    else if(dTotal>21 && pTotal<21){
        cout<<"Dealer Busted"<<endl;
        return 'w';
    }
    else if(dTotal>21 && pTotal>21){
        cout<<"Dealer as well as player Busted"<<endl;
        cout<<"NEXT DEAL";
    }
    else return 'b';
}
void seprtr(){
    cout<<"-------------------------------"<<endl;
}
void isAce(int ary[],int n,int &tot,int &ace){
    for(int i=0;i<n;i++){
        if(ary[i]==11)ace++;
    }
    for(int j=1;j<=ace;j++){
        if(tot>21)tot=tot-10;
    }
}
void result(char code,float &tot,float bPlcd){
    switch(code){
        case 'w':{ //Winner
            cout<<"You win"<<endl;
            tot+=bPlcd;        //Add the winnings
            break;
        }
        case 'b':{ //Busted ie player lost
            cout<<"You Busted"<<endl;
            tot-=bPlcd;       //Deduct the bet
            break;
        }
        case 'l':{ //House total greater than player
            cout<<"You Lose"<<endl;
            tot-=bPlcd;       //Deduct the bet
            break;
        }
        case 'p': //No deduction in the bet
            cout<<"PUSH"<<endl;
            cout<<"Next Deal"<<endl;
    }
}
void stand(int ary[],int &tot,string &card,int n){
    do{
        draw(ary,n,card);
        cout<<"     Dealer's Cards"<<endl;
        pause(1);
        show(ary,tot,n,card);
        n++;
    }while(tot<17);
}
void pause(int n){
    int beg=static_cast<unsigned int>(time(0));
    int end,elapse;
    do{
        end=static_cast<unsigned int>(time(0));
        elapse=end-beg;
    }while(elapse<n);
}
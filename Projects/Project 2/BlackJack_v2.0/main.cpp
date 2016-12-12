/* 
 * File:   main.cpp
 * Author: Tejash Bhakta
 * Purpose: Final Project BlackJack v2.0
 * Created on December 11, 2016, 5:17 PM
 */
#include <iostream>   //Input/Output objects
#include <iomanip>    //Foramatting  
#include <cTime>      //Time functoin for setting the seed of random numbers
#include <cstdlib>    //C standard Library for random numbers  
#include <string>

using namespace std;

//Global Constants
const int COLS=13;

//Function Prototypes;
void draw(bool [][COLS],string [],string [],int,int &);
void stand(bool [][COLS],string [],string [],int &,int);
void cardFace(string[],string[],int,int,int,int &);
void shuffle(bool[][COLS],int);
void show(string[],string [],int);
void isAce(string[],int &,int);
char check(int);
char check(int,int);
void seprtr();
void pause(int);
void result(char,float &,float,int &);
void winPer(int,int);
int main(int argc, char** argv) {
          //Random number generator
    srand(static_cast<unsigned int>(time(0)));
          //Declaration of variable
    float            totAmt=100, betPlcd;  //Total Winnings, Bet Placed
    char             nxt, chk;          //Deal next game, stores the status value
    string           name;                //Name of Player
    int won=0,game=0;
    
    //Display Introduction
//    display();
    //Start the game        
    //Opening Commands
        seprtr();
        
        //Start the Game
        nxt='d';
        cout<<"Enter Player Name"<<endl;
        cin>>name;
    
        while(nxt=='d'){
            do{
               game++;
               seprtr(); 
               cout<<endl<<fixed<<setprecision(2);
               cout<<"YOUR TOTAL right now is $"<<totAmt<<endl;
               cout<<"Bet to be placed (min-10 && max-50)"<<endl;
               cin>>betPlcd;
            }while(betPlcd<10 || betPlcd>50 || betPlcd>totAmt);
            
                //In game declaration of variables
                const int SIZE=5;
                const int SZE=4;
                bool deck[SZE][COLS];
                string playV[SIZE],dealerV[SIZE];
                string playS[SIZE],dealerS[SIZE];
                int deal=0;
                int playTot=0,dealerTot=0;
                char cmd,chk;
                
                //Shuffle the deck
                shuffle(deck,SZE);
                
                //Draw the first card for dealer
                draw(deck,dealerV,dealerS,deal+1,dealerTot);
                
                //Drawing the first two cards for player
                for(int i=0;i<2;i++){
                    ++deal;
                    draw(deck,playV,playS,deal,playTot);
                }

                //Show cards and its total
                //Dealer's card
                cout<<"     Dealer's Cards"<<endl;
                show(dealerV,dealerS,1);
                isAce(dealerV,dealerTot,1);
                cout<<"Total is "<<dealerTot<<endl;
                seprtr();
                //Player's card
                cout<<"     "<<name<<"'s Cards"<<endl;
                show(playV,playS,deal);
                isAce(playV,playTot,deal);
                cout<<"Total is "<<playTot<<endl;
               
                //Close the deals if player hits blackJack   
                //If BlackJack
                if(playTot==21){
                    cout<<"****BlackJack****"<<endl;
                    totAmt+=betPlcd*2.5;
                    won++;
                }
                else{
                    do{
                        seprtr();
                        cout<<"Do you want to hit(h), stand(s), or double down(d)?"<<endl;
                        cin>>cmd;
                    }while(cmd!='h'&& cmd!='s'&& cmd!='d');
                }
                seprtr();  
                
                //Following commands
                while(cmd=='h'){
                    ++deal;
                    draw(deck,playV,playS,deal,playTot);
                    cout<<"     "<<name<<"'s Cards"<<endl;
                    show(playV,playS,deal);                  //Display the Cards
                    isAce(playV,playTot,deal);
                    cout<<"Total is "<<playTot<<endl;
                    seprtr();
                    
                    //Checks if player hits blackjack or gets busted and will break respectively
                    chk=check(playTot);
                    if(chk=='b' || chk=='w'){
                    stand(deck,dealerV,dealerS,dealerTot,2);
                    chk=check(playTot,dealerTot);
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
                    deal=2;
                    stand(deck,dealerV,dealerS,dealerTot,deal);
                    chk=check(playTot,dealerTot);
                }
                
                //If player double downs    
                if(cmd=='d'){
                    ++deal;
                    betPlcd*=4;   
                    //Draw just 1 card
                    draw(deck,playV,playS,deal,playTot);
                    cout<<"     "<<name<<"'s cards"<<endl;
                    show(playV,playS,deal);
                    isAce(playV,playTot,deal);
                    cout<<"Total is "<<playTot<<endl;
                    seprtr();
                    stand(deck,dealerV,dealerS,dealerTot,2);
                    chk=check(playTot,dealerTot);
                }

            //Show the results according to check code
            //and update total
            cout<<name<<" total: "<<setw(6)<<playTot<<endl;
            cout<<"Dealer total: "<<setw(6)<<dealerTot<<endl;
            result(chk,totAmt,betPlcd,won);
            seprtr();
             
            //Display Total
             cout<<"The total Amount right now is "<<totAmt<<endl;
             if(totAmt<10){
                 cout<<"Sorry.Not Enough cash to carry on"<<endl;
                 break;
             }
             winPer(game,won);
            //Continue if enough cash
              do{
                cout<<"Next Deal 'd' or 'x' key to exit"<<endl;
                cin>>nxt;
                seprtr();
              }while(nxt!='d' && nxt!='x');
        }
        cout<<"Thanks for playing"<<endl;
    exit(0);
}
void isAce(string ary[],int &tot,int cards){
    int ace=0;
    for(int i=0;i<cards;i++){
        if(ary[i]=="Ace")ace++;
    }
    for(int i=1;i<=ace;i++){
        if(tot>21)tot-=10;
    }
}
void cardFace(string hand[],string suit[],int row,int col,int pos,int &tot){
    int value;
    switch(row){
        case 0:suit[pos]="Spade";break;
        case 1:suit[pos]="Hearts";break;
        case 2:suit[pos]="Diamonds";break;
        case 3:suit[pos]="Clubs";break;
    }
    switch(col){
        case 0: hand[pos]="Two";value=2;break;
        case 1: hand[pos]="Three";value=3;break;
        case 2: hand[pos]="Four";value=4;break;
        case 3: hand[pos]="Five";value=5;break;
        case 4: hand[pos]="Six";value=6;break;
        case 5: hand[pos]="Seven";value=7;break;
        case 6: hand[pos]="Eight";value=8;break;
        case 7: hand[pos]="Nine";value=9;break;
        case 8: hand[pos]="Ten";value=10;break;
        case 9: hand[pos]="Jack";value=10;break;
        case 10:hand[pos]="Queen";value=10;break;
        case 11:hand[pos]="King";value=10;break;
        case 12:hand[pos]="Ace";value=11;break;
    }
    tot+=value;
}
void shuffle(bool deck[][COLS],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<COLS;j++){
            deck[i][j]=false;
        }
    }
}
void draw(bool deck[][COLS],string hand[],string face[],int deal,int &tot){
    int row,col;
    do{
        row=rand()%4;
        col=rand()%13;
        if(deck[row][col]==false){
            cout<<"Selected "<<row<<" "<<col<<endl;
            cardFace(hand,face,row,col,deal-1,tot);
            deck[row][col]=true;
        }
    }while(deck[row][col]==false);
}
void show(string value[],string face[],int n){
    for(int i=0;i<n;i++){
        cout<<value[i]<<" "<<face[i]<<" | ";
    }
    cout<<endl;
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
        cout<<"NEXT DEAL"<<endl;
    }
    else return 'b';
}
void seprtr(){
    cout<<"-------------------------------"<<endl;
}
void stand(bool deck[][COLS],string val[],string suit[],int &tot,int deal){
    do{
        draw(deck,val,suit,deal,tot);
        cout<<"     Dealer's Cards"<<endl;
        pause(1);
        show(val,suit,deal);
        isAce(val,tot,deal);
        cout<<"Total is "<<tot<<endl;
        ++deal;
        seprtr();
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
void result(char code,float &tot,float bPlcd,int &won){
    switch(code){
        case 'w':{ //Winner
            cout<<"You win"<<endl;
            tot+=bPlcd*2;        //Add the winnings
            won++;
        }break;
        case 'b':{ //Busted ie player lost
            cout<<"You Busted"<<endl;
            tot-=bPlcd;       //Deduct the bet
        }break;
        case 'l':{ //House total greater than player
            cout<<"You Lose"<<endl;
            tot-=bPlcd;       //Deduct the bet
        }break;
        case 'p': //No deduction in the bet
            cout<<"PUSH"<<endl;
            cout<<"Next Deal"<<endl;
    }
}

void winPer(int totGame,int won){
    cout<<won<<" out of "<<totGame<<" won"<<endl;
    cout<<"win percentage: "<<won*100/totGame<<"%"<<endl;
}
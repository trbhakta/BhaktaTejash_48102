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

//Function Prototypes
int    cardVal(int num);
string cardName(int num);
void   display();
void   seprtr();
int    stand(int num1,string cardface);
char   status(int total);               //status 1 checks the player total,
char   status(int pTot, int cTot);      //status 2 compares the house total and player total

//Main Program starts here
int main(int argc, char** argv) {
      //Random number generator
    srand(static_cast<unsigned int>(time(0)));
     //Declaration of variable
    float            totAmt=100, betPlcd;  //Total Winnings, Bet Placed
    unsigned short   cmd;                  //Command for next bet 
    char             deal, check;          //Deal next game, stores the status value
    string           name;                //Name of Player
    fstream in;   
    
    //Display Introduction
    display();
    //Start the game        
    //Opening Commands
    do{
        seprtr();
        cout<<"Choose from the menu"<<endl;
        cout<<"1. Start BlackJack <$100 included>"<<endl;
        cout<<"2. Player Logs"<<endl;
        cin>>cmd;
        
        switch(cmd){
            case 1:{
                deal='d';
                cout<<"Enter Player Name"<<endl;
                cin>>name;
                while(deal=='d'){
                    do{
                       seprtr(); 
                       cout<<fixed<<setprecision(2);
                       cout<<"YOUR TOTAL right now is $"<<totAmt<<endl;
                       cout<<"Bet to be placed (min-10 && max-50)"<<endl;
                       cin>>betPlcd;
                    }while(betPlcd<10 || betPlcd>50 || betPlcd>totAmt);
                    
                //Declaration of variables for game insight
                char   hitstd;                  //Hit or Stand
                int    num=0, com=0,        //num->stores card values for player, com->stores card values of house 
                       pnum=0, cnum=0,      //pnum, cnum->generates random number from 1-14 for player and house
                       aceTot=0,            //aceTot->calculates number of aces
                       pTotal=0, cTotal=0;  //Card total
                string cardface, hosFace;   //Stores Card Face, House Card Face
                bool   isAce=false;         //turns true if ace appears in the any of the deal
    
    
                //Display the House First Card
                seprtr();
                cout<<"House's Card"<<endl;
                cnum=rand()%14+1;
                com=cardVal(cnum);                              //Calls function cardVal which returns the value of the card   
                hosFace=cardName(cnum);                         //Calls function cardName which returns the face of the card
                cout<<hosFace<<"???"<<endl;
                /*if(com==1 || com==11)cout<<"Total would be "<<com-10<<" or"<<endl;
                cout<<"Total would be "<<com<<endl;*/

                 //Fetching the first two cards of the player
                seprtr();
                cout<<name<<"'s Cards"<<endl;
                for(int open=1; open<=2; open++){
                    pnum=rand()%14+1;
                    num=cardVal(pnum);                          //Calls function cardVal which returns the value of the card 
                    if(num==1 || num==11){isAce=true;aceTot++;} //if ace is present, bool value appears true and add to aceTot
                    cardface+=cardName(pnum);                   //Calls function cardName which returns the face of the card
                    pTotal+=num;
                    if(aceTot==2)pTotal-=10;                    //if both first cards aces, total reduces to -10
                }

                //Display Player's First two Cards
                cout<<cardface<<endl;
                if(isAce==true && pTotal!=21)cout<<"Total would be "<<pTotal-10<<" or"<<endl; 
                cout<<"Total would be "<<pTotal<<endl;
                seprtr();

                //Condition Check if player hits BlackJack and ready for another deal
                if(pTotal==21){
                    cout<<"***BlackJack***";
                    totAmt+=betPlcd*1.5; //bet *1.5;
                }

                //Player option to hit, stand or double down if not blackJack
                else{
                    do{
                        cout<<"Hit 'h' or Stand 's' or Double down 'd'"<<endl;
                        cin>>hitstd;
                    }while(hitstd!='h' && hitstd!='s' && hitstd!='d');
                }

                //Generating next cards if the player hits
                while(hitstd=='h'){
                    seprtr();
                    cout<<name<<"'s Card"<<endl;
                    pnum=rand()%14+1;
                    num=cardVal(pnum);
                      if(num==1 || num==11){isAce=true;aceTot++;} //if ace is present, bool value appears true and add to aceTot
                    cardface+=cardName(pnum);                     //Calls function cardVal which returns the face of the card
                    pTotal+=num;
                    cout<<cardface;
                        //if any card is an ace, total reduces to -10 if total greater than 21 
                      if(isAce==true && aceTot!=0){
                         if(pTotal>21){pTotal-=10;aceTot--;isAce=false;} //boolean set to false for further deal
                         else cout<<endl<<"Total would be "<<pTotal-10<<" or";
                      } 
                    cout<<endl<<"Total would be "<<pTotal<<endl;
                    seprtr();
                        //Check the players total and returns won or lost
                        check=status(pTotal);
                        if(pTotal==21){cTotal=stand(com,hosFace);status(pTotal,cTotal);break;}
                        else if(check!=0 && pTotal!=21)break;
                        //Next deal
                        do{
                        cout<<"Hit or Stand"<<endl;
                        cin>>hitstd;
                        }while(hitstd!='h' && hitstd!='s');
                        seprtr();
                   }

                //If player stands the deal
                if(hitstd=='s'){
                    seprtr();
                    //calls the function stand with card 1 as an input and returns the cards as well as the total
                    cTotal=stand(com,hosFace);
                    //checks the house total and returns who won
                    check=status(pTotal,cTotal);
                }

                //If the player double downs
                else if(hitstd=='d'){
                    betPlcd*=2;
                    pnum=rand()%14+1;                 //Only one card is drawn
                    num=cardVal(pnum);                //Calls function cardVal which returns the value of the card
                    cardface+=cardName(pnum);         //Calls function cardFace which returns the face of the card
                    pTotal+=num;  
                    cout<<cardface;         
                    if(isAce==true && aceTot!=0){     //Determines the total if Ace +-10
                        if(pTotal>22){pTotal-=10;aceTot--;}
                    }
                    cout<<endl<<"Total would be "<<pTotal<<endl;
                    seprtr();
                    cTotal=stand(com,hosFace);        //Calls the stand function
                    check=status(pTotal,cTotal);      //Compares the total and declares the winner
                }
                         //Check the winner and updates the total of the player's stack
                switch(check){
                    case 'w':{ //Winner
                              cout<<"You win"<<endl;
                              totAmt+=betPlcd;        //Add the winnings
                              break;
                    }
                    case 'b':{ //Busted ie player lost
                              cout<<"You Busted"<<endl;
                              totAmt-=betPlcd;       //Deduct the bet
                              break;
                    }
                    case 'l':{ //House total greater than player
                              cout<<"You Lose"<<endl;
                              totAmt-=betPlcd;       //Deduct the bet
                              break;
                    }
                    case 'p': //No deduction in the bet
                              cout<<"PUSH"<<endl;cout<<"Next Deal"<<endl;
                              //No deduction next deal
                }   
                seprtr();
                cout<<fixed<<setprecision(2);
                cout<<"Your Total now $"<<totAmt<<endl;
                if(totAmt<10){cout<<"Not enough Money"<<endl;break;}
                    do{cout<<"Next Deal 'd' or exit 'x' "<<endl;
                    cin>>deal;
                    seprtr();
                    }while(deal!='d' && deal!='x');
                }
                in.open("ldrbrd.dat",ios::app);
                in<<"\n"<<name<<"       "<<totAmt;
                in.close();
                break;
            }
            case 2:{
                string  line;
                //Input values
                in.open("ldrbrd.dat");
                if(in.is_open()){
                    while(getline(in,line)){
                        cout<<line<<"\n";
                    }
                //Close file
                in.close();
                }    
                break;
            }
        }
    }while(cmd>0 && cmd<=2);
               
    

    //Exit Program
    return 0;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************** Function Card Value *******************************
// Input random card number as an integer from 1-14
// Returns values of each card: 1-10 number each; face cards=10 each;Ace=1 or 11
//******************************************************************************
int cardVal(int card){
    int value=0;
    //Returns the value on the card
    switch(card){
        case 1:
        case 11:value=11;break;    
        case 2:value=2;break;
        case 3:value=3;break;
        case 4:value=4;break;
        case 5:value=5;break;
        case 6:value=6;break;
        case 7:value=7;break;
        case 8:value=8;break;
        case 9:value=9;break;
        case 10:
        case 12:
        case 13:
        case 14:value=10;break;
    }
    return value;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************** Function Card Name *******************************
// Input random card number as an integer from 1-14
// Returns name of each card Ace-2-10-Jack-Queen-King 
//******************************************************************************
string cardName(int card){
    string cardface;
        //Outputs the Name of the card
    switch(card){
        case 1: 
        case 11:cardface="An Ace|";break;
        case 2: cardface="Two|"; break;
        case 3: cardface="Three|";break;
        case 4: cardface="Four|";break;
        case 5: cardface="Five|";break;
        case 6: cardface="Six|";break;
        case 7: cardface="Seven|";break;
        case 8: cardface="Eight|";break;
        case 9: cardface="Nine|";break;
        case 10:cardface="Ten|";break;
        case 12:cardface="Jack|";break;
        case 13:cardface="Queen|";break;
        case 14:cardface="King|";break;
        return cardface;
    }
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Function display ***********************************
//Purpose:  Displays the Introduction before every new session
//******************************************************************************
void display(){
    cout<<"Welcome to the game of BlackJack"<<endl;
    cout<<"• Each participant attempts to beat the dealer by getting a"<<endl;
    cout<<"  count as close to 21 as possible, without going over 21."<<endl;
    cout<<"Let's get Started"<<endl;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Function Separator *******************************
//Purpose:  Draws a line between consecutive deals
//******************************************************************************
void seprtr(){
    cout<<"-------------------------------"<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Function Status of the deal **********************
//Purpose:  Returns whether the player won, lost busted or deal draw
//Input the player total
//Outputs the winning or losing of the deal
//******************************************************************************
char status(int total){
    if(total>21)return'b';
    else if(total==21)return 'w';
    else return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//********************Function Status (player total, house total)***************
//Purpose:  Returns winner of the deal, The House or the Player
//Input the player total and the House Total
//Outputs the winning or losing of the deal of the House or Player
//******************************************************************************
char status(int pTot, int cTot){
    char stat;
    if(pTot>21)stat='b';
    else if(cTot>pTot){
        if(cTot>21){
            cout<<"House Busted"<<endl;
            stat='w';
        }    
        else if(cTot==21){
            cout<<"Its 21..House Wins"<<endl;
            stat='l';
        }
        else {
            cout<<"House Total Greater"<<endl;
            stat='l';
        }
    }
    else if(cTot==pTot)
        stat='p';
    else if(pTot>cTot){
        if(pTot>21)stat='b';
        else if (pTot<=21)stat='w';
        else stat='l';
    }
    return stat;  
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Function Stand ***********************************
//Purpose:  Draws the House's cards
//Input the 1st card of the house which was drawn earlier
//Outputs the cards and the total of House
//******************************************************************************
int stand(int num1, string cardFace){
    int com=0,cnum=0;
    int cTotal=num1, aceTot=0, n=0;
    char check;
    bool isAce=false;
    string cardface=cardFace;
    if(com==11)isAce=true;
    cout<<"House Cards"<<endl;
        do{ 
            cnum=rand()%14+1;
            com=cardVal(cnum);
            if(com==1 || com==11){isAce=true;aceTot++;}
            cardface=cardface+cardName(com);
            cTotal=cTotal+com;
            if(isAce==true && aceTot!=0){
                if(cTotal>=22){cTotal-=10;aceTot--;isAce=false;}
                n++;
            }
        }while(cTotal<17);
    //House on soft 17 draw one more card
    if(cTotal==17 && n!=0){
        cnum=rand()%14+1;
        com=cardVal(cnum);
        cardface=cardface+cardName(com);
        cTotal=cTotal+com;
    }    
    
    cout<<cardface;
    if(n!=0 && cTotal<17) cout<<endl<<"Total would be "<<cTotal-10<<" or";
    cout<<endl<<"Total would be "<<cTotal<<endl;
    seprtr();
    return cTotal;
}
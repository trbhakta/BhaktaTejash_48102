/* 
   File:   main
   Author: Tejash Bhakta
   Created on October 17, 2016, 1:41 PM
   Purpose: A simple game of Blackjack 
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <fstream>
#include <string>
#include <cTime>
#include <cstdlib>
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants

//Function prototypes
int  cardVal(int card,int total);
void cardName(int card);
int  deal(int series);
void seprtr();
int  stand(int com1,int pTotal);
bool check(int total);
int Ace(int ptotal);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Declaration of variables;
    char hs;                           //Hit or Stand
    int num1, num2, num3, num4, num5;  //Deal the 5 player cards
    int com1, com2, com3, com4, com5;  //Deal the 5 computer cards
    int pnum=0, cnum=0;                //Random number stored in these before transfer to the player card
    int pTotal, cTotal;                //Card total
    
    //Displaying the first two cards of the player
    cout<<"Player's Cards"<<endl;
    for(int i=1; i<=2; i++){
        pnum=rand()%14+1;
        if(i==1)num1=cardVal(pnum,pTotal);
        else    num2=cardVal(pnum,pTotal);
        pTotal=num1+num2;
        pnum=0;
    }
    cout<<endl;
    cout<<"Total would be "<<pTotal<<endl;
    seprtr();
   
     //check busted or good to go
    if(pTotal==21){
        cout<<"Congrats!!Blackjack!!"<<endl;
        return 0;
    }
    else if(check(pTotal)==true){
        cout<<"You Busted!!"<<endl;
        return 0;
    }
    //Displaying house first card
    cout<<"House's Card"<<endl;
    cnum=rand()%14+1;
    com1=cardVal(cnum,cTotal);
    cTotal=com1;
    cout<<endl;
    cout<<"Total "<<cTotal<<endl;
    seprtr();
   
    //Player's option of hitting or staying
    cout<<"Hit 'h' or stand 's'"<<endl;
    cin>>hs;
    
    //Deal Third Card in case of hit or play house on stand
        if(hs=='s') {
            cTotal=stand(com1,pTotal);
            if(cTotal>pTotal){
                if(cTotal>21){
                    cout<<"House Busted"<<endl<<"You win";
                    return 0;
                }    
                else {
                    cout<<"House wins"<<endl;
                    return 0;
                }
            }
            else if(cTotal==pTotal){
                    cout<<"Push"<<endl;
            }
            else if(pTotal>cTotal){
                cout<<"You win"<<endl;
                return 0;
            }
        }
        else if(hs=='h')num3=deal(3);

    //Total after Third Card
        seprtr();
    cout<<"Player's Cards"<<endl;
    pTotal=pTotal+num3;
    cardVal(num1,pTotal);cardVal(num2,pTotal);cardVal(num3,pTotal);cout<<endl;
    cout<<"Total would be "<<pTotal<<endl;
    seprtr();
    
    //check busted or good to go
    if(pTotal==21){
        cout<<"Congrats!!You Win"<<endl;
        return 0;
    }
    else if(check(pTotal)==true){
        cout<<"You Busted!!"<<endl;
        stand(com1,cTotal);
        return 0;
    }
    
     //Player's option of hitting or staying
    cout<<"Hit 'h' or stand 's'"<<endl;
    cin>>hs;
    
    //Deal Fourth Card
        if(hs=='s') {
            cTotal=stand(com1,pTotal);
            if(cTotal>pTotal){
                if(cTotal>21){
                    cout<<"House Busted"<<endl<<"You win";
                    return 0;
                }    
                else {
                    cout<<"House wins"<<endl;
                    return 0;
                }
            }
            else if(cTotal==pTotal){
                    cout<<"Push"<<endl;
            }
            else if(pTotal>cTotal){
                cout<<"You win"<<endl;
                return 0;
            }
        }
        else if(hs=='h')num4=deal(4);
        
        //Total after Fourth Card
          seprtr();
    cout<<"Player's Cards"<<endl;
    pTotal=pTotal+num4;
    cardVal(num1,pTotal);cardVal(num2,pTotal);cardVal(num3,pTotal);cardVal(num4,pTotal);cout<<endl;
    cout<<"Total would be "<<pTotal<<endl;
    seprtr();
    
    //check busted or good to go
    if(pTotal==21){
        cout<<"Congrats!!You Win"<<endl;
        return 0;
    }
    else if(check(pTotal)==true){
        cout<<"You Busted!!"<<endl;
        stand(com1,cTotal);
        return 0;
    }
    
    //Player's option of hitting or staying
    cout<<"Hit 'h' or stand 's'"<<endl;
    cin>>hs;
    
    //Deal Fifth Card
        if(hs=='s') {
            cTotal=stand(com1,pTotal);
            if(cTotal>pTotal){
                if(cTotal>21){
                    cout<<"House Busted"<<endl<<"You win";
                    return 0;
                }    
                else {
                    cout<<"House wins"<<endl;
                    return 0;
                }
            }
            else if(cTotal==pTotal){
                    cout<<"Push"<<endl;
            }
            else if(pTotal>cTotal){
                cout<<"You win"<<endl;
                return 0;
            }
        }
        else if(hs=='h')num4=deal(5);
        
        //Total after Fifth Card
          seprtr();
    cout<<"Player's Cards"<<endl;
    pTotal=pTotal+num5;
    cardVal(num1,cTotal);cardVal(num2,cTotal);cardVal(num3,cTotal);cardVal(num4,cTotal);cardVal(num5,cTotal);cout<<endl;
    cout<<"Total would be "<<pTotal<<endl;
    seprtr();
        
        //Final House Cards
     cTotal=stand(com1,pTotal);
            if(cTotal>pTotal){
                if(cTotal>21){
                    cout<<"House Busted"<<endl<<"You win";
                    return 0;
                }    
                else {
                    cout<<"House wins"<<endl;
                    return 0;
                }
            }
            else if(cTotal==pTotal){
                    cout<<"Push"<<endl;
            }
            else if(pTotal>cTotal){
                cout<<"You win"<<endl;
                return 0;
            }
        //Exit Program
    return 0;
}


//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************** Function Card Value *******************************
// Input random card number as an integer
// Returns values of each card 1-10 number each; face cards=10 each; Ace=1 or 11
//******************************************************************************
int cardVal(int card, int total){
    int value=0;
    //Outputs the Name of the card
    switch(card){
        case 1:
        case 11:cout<<"An Ace|";
                break;
        case 2: cout<<"Two|"; break;
        case 3: cout<<"Three|";break;
        case 4: cout<<"Four|";break;
        case 5: cout<<"Five|";break;
        case 6: cout<<"Six|";break;
        case 7: cout<<"Seven|";break;
        case 8: cout<<"Eight|";break;
        case 9: cout<<"Nine|";break;
        case 10:cout<<"Ten|";break;
        
        case 12:cout<<"Jack|";break;
        case 13:cout<<"Queen|";break;
        case 14:cout<<"King|";break;
    }
    //Returns the value on the card
    switch(card){
        case 1:
        case 11:value=Ace(total);break;
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
//*************************   Function Ace **********************************
//Purpose:  Draws a line between consecutive deals
//******************************************************************************
int Ace(int total){
    int ptotal=total;
    if(ptotal<21){
        return 11;
    }
    else return 1;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************** Function Checks ***********************************
//Purpose :Checks the total to be equal or greater than 21
// Input Card Total
// Returns boolean if true->Busted if total=21->You win
//******************************************************************************
bool check(int total){
    if(total==21){
        return 21;
    }
    else if(total>21){
        return true;
    }
    else return false;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//************************* Function Deal **************************************
//Purpose:  Deals the third, fourth and fifth hit by player
//   Input the series of hit
//   Returns the random number 1-13 
//******************************************************************************
int deal(int series){
    int value;
    //srand(static_cast<unsigned int>(time(0)));
    value=rand()%14+1;
    return value;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Function Stand ***********************************
//Purpose:  Plays the house cards and total
//   Input the first house card and player total
//   Returns House Total
//******************************************************************************
int stand(int com1,int pTotal){
    int com2, com3, com4, com5, cnum=0;
    int cTotal=com1, i;
    //Separator
      seprtr();
     //Displaying House's one card
    cout<<"House's cards"<<endl;
    cardVal(com1,cTotal);
     for(i=1; i<=4; i++){
        cnum=rand()%14+1;
      switch(i){
          case 1: com2=cardVal(cnum,cTotal);
                  cTotal+=com2;
                  break;
          case 2: com3=cardVal(cnum,cTotal);
                  cTotal+=com3;  
                  break;
          case 3: com4=cardVal(cnum,cTotal);
                  cTotal+=com4;  
                  break;
          case 4: com5=cardVal(cnum,cTotal);
                  cTotal+=com5;
                  break;  
      }
      if(cTotal>=17)break;
    }
    cout<<endl;
    cout<<"House Total-"<<cTotal<<endl;
    seprtr();
    return cTotal;    
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Function Seprtr **********************************
//Purpose:  Draws a line between consecutive deals
//******************************************************************************
void seprtr(){
    cout<<"-------------------------------"<<endl;
}
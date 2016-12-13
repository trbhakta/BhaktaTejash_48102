// Lesson 23: Blackjack program
// Author: Michael Hall
//
// This program is available for download through our website Xoax.net with no guarantees.
// Disclaimer: While we have made every effort to ensure the quality of our content, all risks associated
// with downloading or using this solution, project and code are assumed by the user of this material.
//
// Copyright 2008 Xoax - For personal use only, not for distribution

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int COLS=13;
void draw(bool deck[][COLS]);
void shuffle(bool deck[][COLS]);
int main() {
    bool deck[4][13];
    shuffle(deck);
      for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            cout<<deck[i][j];
        }
        cout<<endl;
    }
    for(int i=0;i<52;i++){
        cout<<"m "<<i+1<<endl;
        draw(deck);
    }
        for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            cout<<deck[i][j];
        }
        cout<<endl;
    }
exit(0);
}
void draw(bool deck[][COLS]){
    int row=0,col=0,n=1;
    do{
        row=rand()%4;
        col=rand()%13;
        if(deck[row][col]==0)
        {
            cout<<row<<" "<<col<<endl;
            cout<<n<<endl;
            deck[row][col]=1;
            n++;
            break;
        }
    }while(deck[row][col]==true);
}
void shuffle(bool deck[][COLS]){
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            deck[i][j]=false;
        }
    }
}
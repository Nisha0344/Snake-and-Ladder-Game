#include<bits/stdc++.h>
using namespace std;
class SnakeLadder{
    public:
    int playerPosition;
    map<int,int>ladders;
    map<int,int>snakes;
    SnakeLadder(){
        playerPosition=1;
        ladders[1]=38;
        ladders[4]=14;
        ladders[9]=31;
        ladders[21]=42;
        ladders[28]=84;
        ladders[51]=67;
        ladders[72]=91;
        ladders[80]=99;

        
        snakes[17]=7;
        snakes[54]=34;
        snakes[62]=18;
        snakes[64]=60;
        snakes[87]=36;
        snakes[93]=73;
        snakes[95]=75;
        snakes[98]=79;
       

    }
    void rollDice(){
        int dice = (rand()%6)+1;
        cout<<"You rolled is "<<dice<<endl;
        if(playerPosition +dice <=100){
            playerPosition+=dice;
            checkPosition();
        }else{
            cout<<"Roll exceeded board limit . Try again!"<<endl;
        }
    }
    void checkPosition(){
        if(ladders.find(playerPosition)!=ladders.end()){
            cout<<"Landed on a ladder climbing up from "<<playerPosition;
            playerPosition=ladders[playerPosition];
            cout<<"to"<<playerPosition<<endl;

        }
        else if(snakes.find(playerPosition)!= snakes.end()){
            cout<<"oh no Bitten by snake. Sliding down from "<<playerPosition;
            playerPosition=snakes[playerPosition];
            cout<<"to"<<playerPosition<<endl;
        }
        else {
            cout<<"Moved to position "<<playerPosition<<endl;
        }
    }
    bool hasWon(){
        return playerPosition==100;
    }
    void printBoard(){
        cout<<"player's position is marked as p:"<<endl;
    for(int i =1; i<=100;i++){
        if(i==playerPosition)
        cout<<"P";
    
    else
        cout<<"_";
    }
    cout<<endl;
    }
};
int main(){
    srand(time(0));
    SnakeLadder game;
    cout<<"Welcome to the Snake and Ladder Game "<<endl;
    while(!game.hasWon()){
        game.printBoard();
        cout<<" Enter to roll the dice..";
        cin.get();
        game.rollDice();
        cout<<"Current Position:"<<game.playerPosition<<endl;
    }
    cout<<"Congratulation ! You've won the match"<<endl;
    return 0;
}

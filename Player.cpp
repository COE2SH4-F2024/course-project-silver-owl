#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.pos->x=mainGameMechsRef->getBoardSizeX()/2;
    playerPos.pos->y=mainGameMechsRef->getBoardSizeY()/2;
    playerPos.symbol= '@';

}


Player::~Player()
{
    // delete any heap members here
    //no keyword "new" in the constructor, hence no heap member for now
    //destructor can be empty for now
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
}

void Player::updatePlayerDir()
{
    char input= mainGameMechsRef->getInput();//takes function frm required point in game mechs
        // PPA3 input processing logic 
    //switch case:
    switch(input)
    {
        case'w':
            if(myDir!=UP&&myDir!=DOWN)
                myDir=UP;
            break;
        case'a':
            if(myDir!=LEFT&&myDir!=RIGHT)
                myDir=LEFT;
            break;
        case 's':
            if(myDir!=UP&&myDir!=DOWN)
                myDir=DOWN;
            break;
        case 'd':
            if(myDir!=LEFT&&myDir!=RIGHT)
            myDir=RIGHT;
            break;
        default:
            break;
    }         
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
}

// More methods to be added
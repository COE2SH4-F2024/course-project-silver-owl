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
//
void Player::updatePlayerDir()
{
    char input= mainGameMechsRef->getInput();//takes function frm required point in game mechs
        // PPA3 input processing logic 
    //switch case:
    switch(input)
    {
        case 'w':
        case 'W':
            if(myDir != UP && myDir != DOWN)
                myDir=UP;
            break;
        case 'a':
        case 'A':
            if(myDir != RIGHT && myDir != LEFT)
                myDir=LEFT;
            break;
        case 's':
        case 'S':
            if(myDir != UP && myDir != DOWN)
                myDir=DOWN;
            break;
        case 'd':
        case 'D':
            if(myDir != RIGHT && myDir != LEFT)
                myDir=RIGHT;
            break;
        default:
            break;
    }
    input=0;         
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
     switch(myDir) {
        case LEFT:
            playerPos.pos->x--;
            if(playerPos.pos->x < 1) {
                playerPos.pos->x = mainGameMechsRef->getBoardSizeX() - 2;  // Wrap around
            }
            break;
        case RIGHT:
            playerPos.pos->x++;
            if(playerPos.pos->x>= mainGameMechsRef->getBoardSizeX() - 1) {
                playerPos.pos->x = 1;  // Wrap around
            }
            break;
        case UP:
            playerPos.pos->y--;
            if(playerPos.pos->y < 1) {
                playerPos.pos->y = mainGameMechsRef->getBoardSizeY() - 2;  // Wrap around
            }
            break;
        case DOWN:
            playerPos.pos->y++;
            if(playerPos.pos->y >= mainGameMechsRef->getBoardSizeY() - 1) {
                playerPos.pos->y = 1;  // Wrap around
            }
            break;
        
    }
}

// More methods to be added
#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    playerPosList = new objPosArrayList();

    objPos headPos(mainGameMechsRef->getBoardSizeX()/2,
                    mainGameMechsRef->getBoardSizeY()/2,
                    '@');

    //iter3: intialize playerPosList with the starting position
    playerPosList->insertHead(headPos);

    // more actions to be included
    //playerPos.pos->x=mainGameMechsRef->getBoardSizeX()/2;
    //playerPos.pos->y=mainGameMechsRef->getBoardSizeY()/2;
    //playerPos.symbol= '@';

}


Player::~Player()
{
    // delete any heap members here
    //no keyword "new" in the constructor, hence no heap member for now
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPosList;
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
    //PPA3 finite state machine logic
    updatePlayerDir(); //get the current position

    //create a temporary objPos to calculate the new head position
    //probably should get the head element of the playerPosList
    // as a good starting point
    objPos currentHead = playerPosList->getHeadElement();
    objPos newHead = currentHead;

    // PPA3 Finite State Machine logic
    //inter 3: calculate the new position of the head
    //          using the temp objPos
     switch(myDir) {
        case LEFT:
            newHead.pos->x--;
            if(newHead.pos->x < 1) {
                newHead.pos->x = mainGameMechsRef->getBoardSizeX() - 2;  // Wrap around
            }
            break;
        case RIGHT:
            newHead.pos->x++;
            if(newHead.pos->x>= mainGameMechsRef->getBoardSizeX() - 1) {
                newHead.pos->x = 1;  // Wrap around
            }
            break;
        case UP:
            newHead.pos->y--;
            if(newHead.pos->y < 1) {
                newHead.pos->y = mainGameMechsRef->getBoardSizeY() - 2;  // Wrap around
            }
            break;
        case DOWN:
            newHead.pos->y++;
            if(newHead.pos->y >= mainGameMechsRef->getBoardSizeY() - 1) {
                newHead.pos->y = 1;  // Wrap around
            }
            break;
        default:
            break;

        
    }

    //inter3: insert temp objPos to the head of the list
    playerPosList->insertHead(newHead);

    //iter3 (later in feature 2):
    //      check if the new temp objPos overlaps
    //      the food pos (get it from GameMechs Class)
    objPos foodPos = mainGameMechsRef->getFoodPos();

    //      use isPosEqual()method from objPos class
    //      if overlapped, food consumer, DO NOT REMOVE SNAKE TAIL
    //      and take the respective actions to increase the score
    if(newHead.isPosEqual(&foodPos))
    {
        mainGameMechsRef->incrementScore();
        mainGameMechsRef->generateFood(newHead);

    }
    //iter3 if no overlap, remove tail, complete movement.
    else
    {
        playerPosList->removeTail();
    }
}

// More methods to be added


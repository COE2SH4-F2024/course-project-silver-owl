#include "GameMechs.h"
#include "MacUILib.h"
#include "Player.h" 


GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = 20;
    boardSizeY = 10;
    playerRef = 0;

}
GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = boardX;
    boardSizeY = boardY;
    playerRef = 0;

}

// do you need a destructor?
GameMechs::~GameMechs()
{
    // at this moment, NO, becasue we dont have a heap member
    
}
bool GameMechs::getExitFlagStatus() const
{
 return exitFlag;
}
bool GameMechs::getLoseFlagStatus() const
{
 return loseFlag;
}
    
char GameMechs::getInput()
{
    if(MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }
    return input;
}
int GameMechs::getScore() const
{
    if(playerRef != 0)
    {
        // The score is list size - 1
        return playerRef->getPlayerPos()->getSize()-1;
    }
    return score;
}
void GameMechs::incrementScore()
{
    score++;
}
int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}
int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}
void GameMechs::setExitTrue()
{
    exitFlag = true;
}
void GameMechs::setLoseFlag()
{
    loseFlag = true;
}
void GameMechs::setInput(char this_input)
{
    input = this_input;
}
void GameMechs::clearInput()
{
    input = 0;
}

//More methods should be added here
void GameMechs::generateFood(objPosArrayList* blockOffList)
{
    bool validPos = false;

    
    while(!validPos)
    {
        int randomx = rand() % (boardSizeX-2)+1;
        int randomy = rand() % (boardSizeY-2)+1;
        
        //iterate through every single objPos element in the playerPosLis
        //so that the position of the new food item does not overlap with
        //any of the elements
        bool overlap = false;
        for(int i = 0; i < blockOffList->getSize(); i++)
        {
            objPos playerSeg = blockOffList->getElement(i);
            if(randomx == playerSeg.pos->x && randomy == playerSeg.pos->y)
            {
                overlap = true;
                break;
            }
        }

        if(!overlap)
        {
            foodPos.setObjPos(randomx, randomy, 'o');
            validPos=true;
        }

    }
}
objPos GameMechs::getFoodPos() const
{
    return foodPos;
}

void GameMechs::setLoseFlag(const char* loseMessage)
{
    loseFlag = true;
    exitFlag = true;
    if (loseMessage)
    {
        MacUILib_clearScreen();
        MacUILib_printf("%s\n", loseMessage);

        MacUILib_Delay(5000000);
    }
}

void GameMechs::setPlayerRef(Player* player)
{
    playerRef = player;
}
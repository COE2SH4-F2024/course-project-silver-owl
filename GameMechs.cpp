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
    food.setObjPos(-10, -10, 'o');

    // int the food object to be outside the gameboard
    // so that before it is ranndomly placed on the gameboard, it will
    // nont accidentlaly appear on the top left corner of the gameboard (0,0)
}
GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = boardX;
    boardSizeY = boardY;

    food.setObjPos(-10, -10, 'o');
    //generateFood(objPos playerPos);
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
void GameMechs::generateFood(objPos blockOff)
{
    bool validPos = false;

    //only need to block off the player position for now
    while(!validPos)
    {
        int x = rand() % boardSizeX;
        int y = rand() % boardSizeX;

        if(blockOff.pos != nullptr && x == blockOff.pos->x && y == blockOff.pos->y);
        {
            continue;
        }

        food.setObjPos(x, y, 'o');
        validPos = true;
    }
}
objPos GameMechs::getFoodPos() const
{
    return food;
}

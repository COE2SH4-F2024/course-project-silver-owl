#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
using namespace std;

#define DELAY_CONST 100000

Player *myPlayer;
GameMechs *myGM;
bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    myGM=new GameMechs();
    myPlayer=new Player(myGM);//allows game mechanics instance to communjicate with each other

    myGM = new GameMechs();
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    
    objPos foodPos = myGM->getFoodPos();
    int boardX = myGM->getBoardSizeX();
    int boardY = myGM->getBoardSizeY();
    for(int y = 0; y < boardY; y++)
    {
        for(int x = 0; x < boardX; x++)
        {
            if(y == 0 || y == boardY - 1 || x == 0 || x == boardX - 1 )
            {
                MacUILib_printf("%c", '#');
            }
            else if(x == playerPos.pos->x && y == playerPos.pos->y)
            {
                MacUILib_printf("%c", playerPos.symbol);
            }
            else if(x == foodPos.pos->x && y == foodPos.pos->y);
            {
                MacUILib_printf("%c", foodPos.symbol)
            }
            else
            {
                MacUILib_printf("%c", ' ');
            }
        }
        MacUILib_printf("\n");



    //implement copy assignment operator
    //to make this line work
    MacUILib_clearScreen();
    objPos playerPos= myPlayer ->getPlayerPos();
    MacUILib_printf("Player[x,y]=,[%d,%d],%c",playerPos.pos->x,playerPos.pos->y, playerPos.symbol);
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    delete myPlayer;
    delete myGM;
    MacUILib_uninit();
}



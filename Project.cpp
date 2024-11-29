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
// objPos::~objPos(){
//     delete pos;//this here is required
// }
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
    myGM = new GameMechs();
    myPlayer = new Player(myGM); // Allows game mechanics instance to communicate with each other
}

void GetInput(void)
{
    
    myPlayer->updatePlayerDir();
}

void RunLogic(void)
{
    // Implementation for game logic if needed

    
    myPlayer->movePlayer();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    
    objPos foodPos = myGM->getFoodPos();
    objPos playerPos = myPlayer->getPlayerPos();
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
            else if(x == foodPos.pos->x && y == foodPos.pos->y) // Removed semicolon here
            {
                MacUILib_printf("%c", foodPos.symbol);
            }
            else
            {
                MacUILib_printf("%c", ' ');
            }
        }
        MacUILib_printf("\n");
    }

    // Debug: Output player position
    MacUILib_printf("Player [x, y] = [%d, %d], %c\n",
                    playerPos.pos->x, playerPos.pos->y, playerPos.symbol);
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

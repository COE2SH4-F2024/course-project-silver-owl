#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include <cstdlib>
#include <time.h>
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
    srand(time(NULL));
    MacUILib_init();
    MacUILib_clearScreen();
    myGM = new GameMechs();
    myPlayer = new Player(myGM); // Allows game mechanics instance to communicate with each other
    myGM->generateFood(myPlayer->getPlayerPos());
    myGM->setPlayerRef(myPlayer); //set player reference to GameMechs

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

    objPosArrayList* playerPos = myPlayer->getPlayerPos();
    int playerSize = playerPos->getSize();

    int boardX = myGM->getBoardSizeX();
    int boardY = myGM->getBoardSizeY();

    for(int y = 0; y < boardY; y++)
    {
        for(int x = 0; x < boardX; x++)
        { 
        //iter 3: we now need to iterate through the playerPos array list 
        // to print all the segments out.
            bool matched = false;
            for(int k = 0; k < playerSize; k++)
            {
                objPos thisSeg = playerPos->getElement(k);

                //iter 3: check if the current segment x, y pos matches
                // the (x,y)coordinate; if yes, print the symbol
                if (x == thisSeg.pos->x && y == thisSeg.pos->y)
                {
                    MacUILib_printf("%c", thisSeg.symbol);
                    matched = true;

                    //at the end of the for loop, do something to 
                    //determine whether to continue with the if-else
                    //or move on to the next iteration of x-y

                    break;  // No need to check further as a match has been found
                }

            }

        //Watch OUT!!
        //we need to skip the if-else block below
        // if we have printed something in the for loop
            if(!matched)
            {
                if(y == 0 || y == boardY - 1 || x == 0 || x == boardX - 1 )
                {
                    MacUILib_printf("%c", '#');
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
            
        }
        MacUILib_printf("\n");
    }
    // Display the score below the game board
    MacUILib_printf("Score: %d\n", myGM->getScore());

    //Debug: Output player position
   //MacUILib_printf("Player [x, y] = [%d, %d], %c\n",thisSeg.pos->x, thisSeg.pos->y, thisSeg.symbol);
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

#include <stab.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

//Global variables
char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';


int main() 
{
    char winner = ' ';

    resetBoard();

    printBoard();

    return 0;
}

void resetBoard()
{
    for(int rows = 0; rows < 3; rows++)
    {
        for(int columns = 0; columns < 3; columns++)
        {
            board[rows][columns] = ' ';

        }

    }

}

void printBoard()
{
    printf("%c | %c | %c", board[0][0], board[0][1], board[0][2]);
    printf("%c | %c | %c", board[1][0], board[1][1], board[1][2]);
    printf("%c | %c | %c", board[2][0], board[2][1], board[2][2]);

}

int checkFreeSpaces()
{

}

void playerMove()
{

}

void computerMove()
{

}

char checkWinner()
{

}

void printWinner(char winner)
{

}
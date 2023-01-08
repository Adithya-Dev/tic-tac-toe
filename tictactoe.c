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
void assignCharacters();

//Global variables
char board[3][3];
char PLAYER;
char COMPUTER;




int main() 
{
    char winner = ' ';

    assignCharacters();

    resetBoard();

    while(winner = ' ' && checkFreeSpaces() != 0)
    {
        printBoard();

        playerMove();

        winner = checkWinner();

        if (winner != ' ' || checkFreeSpaces() == 0)
        {
            break;
        }

        computerMove();

        winner = checkWinner();

        if (winner != ' ' || checkFreeSpaces() == 0)
        {
            break;
        }
    }

    printBoard();

    printWinner(winner);

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
    printf(" %c | %c | %c", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c", board[2][0], board[2][1], board[2][2]);
    printf("\n");

}

int checkFreeSpaces()
{
    int free_spaces = 9;

    for(int rows = 0; rows < 3; rows++)
    {
        for(int columns = 0; columns < 3; columns++)
        {
            if (board[rows][columns] != ' ')
            {
                free_spaces--;

            }

        }
    }


}

void playerMove()
{
    int rows;
    int columns;

    do
    {
        printf("Enter row #(1-3): ");
        scanf("%d", &rows);
        rows--;

        printf("Enter column #(1-3): ");
        scanf("%d", &columns);
        columns--;

        if (board[rows][columns] != ' ')
        {
            printf("Invalid move!\n");
        }
        else
        {
            board[rows][columns] = PLAYER;
            break;
        }
    } while (board[rows][columns] != ' ');
    





    if (board[rows][columns] != ' ')
    {
        printf("Invalid move!\n");
    }
    else
    {
        board[rows][columns] = PLAYER;
    }

}

void computerMove()
{
    //seed creation based on time

    srand(time(0));
    int rows;
    int columns;

    if (checkFreeSpaces > 0)
    {
        do
        {
            rows = rand() %3 ;
            columns = rand() % 3;
        } while (board[rows][columns] != ' ');

        board[rows][columns] = COMPUTER;
    }
    else
    {
        printWinner(' ');
    }

}

char checkWinner()
{
    //check rows
    for (int rows = 0; rows < 3; rows++)
    {
        if (board[rows][0] == board[rows][1] && board[rows][0] == board[rows][2])
        {
            return board[rows][0];
        }
    }

    //check columns
    for (int columns = 0; columns < 3; columns++)
    {
        if (board[0][columns] == board[1][columns] && board[0][columns] == board[2][columns])
        {
            return board[0][columns];
        }
    }

    //check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }

    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }

    return ' ';

}

void printWinner(char winner)
{
    if (winner == PLAYER)
    {
        printf("Player wins!");
    }
    else if (winner == COMPUTER)
    {
        printf("Computer wins!");
    }
    else
    {
        printf("Its a draw");
    }


}

void assignCharacters()
{
    printf("CAUTION. Always the charcter letters in Capitals. \n");
    printf("What character do you want to asssign the player (X or O): ");
    scanf("%s", &PLAYER);

    if (PLAYER == 'X')
    {
        COMPUTER = 'O';
    }
    else
    {
        COMPUTER = 'X';

    }
}
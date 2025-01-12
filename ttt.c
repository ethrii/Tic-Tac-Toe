#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <cs50.c>
#include <unistd.h>

char board[3][3];
const char PLAYER = 'X';
const char PLAYER2 = 'O';

void resetboard();
void printboard();
int checkfreespaces();
void player1move();
void player2move();
char checkwinner();
void printwinner(char);

int main()
{
    char winner = ' ';
    char response;

    do
    {
        winner = ' ';
        response = ' ';

        resetboard();

        while (winner == ' ' && checkfreespaces() != 0)
        {
            printboard();

            player1move();
            winner = checkwinner();

            if (winner != ' ' || checkfreespaces() == 0)
            {
                break;
            }

            printboard();

            player2move();
            winner = checkwinner();

            if (winner != ' ' || checkfreespaces() == 0)
            {
                break;
            }
        }

        printboard();

        printwinner(winner);

        response = get_char("Would you like to play again? (Y/N) ");
    }
    while (response == 'y' || response == 'Y');

    printf("\nThank you for playing!\n");

    sleep(3); //3 seconds

    return 0;
}

void resetboard()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void printboard()
{
    printf("\n   1   2   3  \n");
    printf("1  %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("  ---|---|---\n");
    printf("2  %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("  ---|---|---\n");
    printf("3  %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}
int checkfreespaces()
{
    int freespaces = 9;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != ' ')
            {
                freespaces--;
            }
        }
    }
    return freespaces;
}
void player1move()
{
    int x;
    int y;
    
    do
    {
        do
        {
            x = get_int("Player 1: Enter row #1 to 3: ");
        }
        while (x < 1 || x > 3);

        x--;

        do
        {
            y = get_int("Player 1: Enter column #1 to 3: ");
        } 
        while (y < 1 || y > 3);

        y--;

        if(board[x][y] != ' ')
        {
            printf("\nYou cannot mark here.\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    }
    while (board[x][y] != ' ');
}
void player2move()
{
    int x;
    int y;
    
    do
    {
        do
        {
            x = get_int("Player 2: Enter row #1 to 3: ");
        } 
        while (x < 1 || x > 3);

        x--;

        do
        {
            y = get_int("Player 2: Enter column #1 to 3: ");
        } 
        while (y < 1 || y > 3);
        
        y--;

        if (board[x][y] != ' ')
        {
            printf("\nYou cannot mark here.\n");
        }
        else
        {
            board[x][y] = PLAYER2;
            break;
        }
    } 
    while (board[x][y] != ' ');
}
char checkwinner()
{
    //check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }

    //check cols
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
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
void printwinner(char winner)
{
    if (winner == PLAYER)
    {
        printf("PLAYER 1 WINS!\n");
        printf("\n");
    }
    else if (winner == PLAYER2)
    {
        printf("PLAYER 2 WINS!\n");
        printf("\n");
    }
    else
    {
        printf("DRAW!\n");
        printf("\n");
    }
}
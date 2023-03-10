/*
 * C programming: A Modern Approach. Chapter 08, Project 09
 * Date: February 2023
 * Author: ffstlln
 * Description: Random walk generator
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define RIGHT 0
#define UP    1
#define LEFT  2
#define DOWN  3

int main(void)
{
    char grid[SIZE][SIZE] = { 0 },
         ch = 'A';              // current character
    bool move[4];               // valid movements { right, up, left, down }
    int i = 0,                  // position tracking
        j = 0;

    srand((unsigned) time(NULL));

    for(int i = 0; i < SIZE; i++)   // fill the grid with dots
    {
        for(int j = 0; j < SIZE; j++)
        {
            grid[i][j] = '.';
        }
    }

    grid[i][j] = ch;
    while(ch <'Z') 
    {
        move[RIGHT] = (j + 1 < SIZE && grid[i][j + 1] == '.') ? true : false;
        move[UP]    = (i - 1 >= 0   && grid[i - 1][j] == '.') ? true : false;
        move[LEFT]  = (j - 1 >= 0   && grid[i][j - 1] == '.') ? true : false;
        move[DOWN]  = (i + 1 < SIZE && grid[i + 1][j] == '.') ? true : false;

        if (!move[RIGHT] && !move[UP] && !move[LEFT] && !move[DOWN])
        {
            break;
        }

        switch(rand() % 4)
        {
            case RIGHT:
                if(move[RIGHT])
                {
                    ch++, j++;
                    grid[i][j] = ch;
                    break;
                }
                /* marker comments suppress fall-through warnings in GCC */
                /* fall through */
            case UP:
                if(move[UP])
                {
                    ch++, i--;
                    grid[i][j] = ch;
                    break;
                }
                /* fall through */
            case LEFT:
                if(move[LEFT])
                {
                    ch++, j--;
                    grid[i][j] = ch;
                    break;
                }
                /* fall through */
            case DOWN:
                if(move[DOWN])
                {
                    ch++, i++;
                    grid[i][j] = ch;
                    break;
                }
                /* fall through */
            default:
                break;
        }
    }

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            printf(" %c ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}

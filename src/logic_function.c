#include <stdio.h>
#include <stdint.h>

#define ROCK 1
#define PAPER 2 
#define SCISSOR 3

void Finaldecision(uint8_t u_choice, uint8_t c_choice)
{
    if (u_choice == c_choice)
    {
        printf("\033[1;31mGame Fowl\033[0m\n");
    }
    else if ((u_choice == ROCK && c_choice == SCISSOR) ||
             (u_choice == PAPER && c_choice == ROCK) ||
             (u_choice == SCISSOR && c_choice == PAPER))
    {
        printf("\033[1;32mYou Won the game. \033[0m\n");
    }
    else
    {
        printf("\033[1;32mComputer Won the game. \033[0m\n");
    }
}
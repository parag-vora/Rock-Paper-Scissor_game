#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define MAX_VALUE 2

enum choice
{
    ROCK = 1,
    PAPER = 2,
    SCISSOR = 3
};

typedef enum select
{
    NO,
    YES
} SELECT;

int main()
{

    uint8_t u_choice, c_choice;
    char *u_choice_ptr, *c_choice_ptr;
    SELECT p_choice = YES;

    printf("____ROCK-PAPER-SCISSOR GAME____\n");
    printf("\nStarted\n");

    do
    {
        // user choice
        printf("Enter your choice\n 1. ROCK\n 2. PAPER\n 3. SCISSOR : ");
        scanf("%u", &u_choice);

        switch (u_choice)
        {
        case ROCK:
            u_choice_ptr = "ROCK";
            break;
        case PAPER:
            u_choice_ptr = "PAPER";
            break;
        case SCISSOR:
            u_choice_ptr = "SCISSOR";
            break;
        default:
            break;
        }

        printf("Your choice is: %s \n", u_choice_ptr);

        // Computer choice
        srand(time(0));
        c_choice = rand() % (MAX_VALUE + 1);

        switch (c_choice)
        {
        case ROCK:
            c_choice_ptr = "ROCK";
            break;
        case PAPER:
            c_choice_ptr = "PAPER";
            break;
        case SCISSOR:
            c_choice_ptr = "SCISSOR";
            break;
        default:
            break;
        }

        printf("computer choice is: %s \n", c_choice_ptr);

        // Decision part
        if(u_choice == ROCK && c_choice == PAPER){ 
            printf("Computer Won the game. \n");
        } else if(u_choice == PAPER && c_choice == ROCK){
            printf("You Won the game. \n");   
        } else if(u_choice == ROCK && c_choice == SCISSOR){
            printf("You Won the game. \n"); 
        } else if(u_choice == SCISSOR && c_choice == ROCK){
            printf("Computer Won the game. \n"); 
        } else if(u_choice == PAPER && c_choice == SCISSOR){
            printf("Computer Won the game. \n"); 
        } else if(u_choice == SCISSOR && c_choice == PAPER){
            printf("You Won the game. \n"); 
        } else {
            printf("Game Fowl\n");
        }
  
        // Repeat part
        printf("Do you want to play again\n 1. NO\n 2. YES: ");
        scanf("%d", &p_choice);

    } while (p_choice - 1);

    return 0;
}

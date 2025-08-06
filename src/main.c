#include<stdio.h>
#include<stdlib.h>

#define MAX_VALUE 3

typedef enum{
    ROCK,
    PAPER,
    SCISSOE
} CHOICE;

int main(){

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", rand() % (MAX_VALUE + 1));
    }
    
    
    return 0;
}

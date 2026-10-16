#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "life.h"

void dump_field(char field[ROWS][COLS]) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++)
            putchar(field[r][c]);
        putchar('\n');
    }
}

int main(void) {
    char field[ROWS][COLS];
    char newfield[ROWS][COLS];

    /* initialise to dead */
    for (int r = 0; r < ROWS; r++)
        for (int c = 0; c < COLS; c++)
            field[r][c] = DEAD;

    /* glider in the top-left */
    field[0][1] = ALIVE;
    field[1][2] = ALIVE;
    field[2][0] = ALIVE;
    field[2][1] = ALIVE;
    field[2][2] = ALIVE;

    for (int gen = 0; gen < 100; gen++) {
        printf("\033[2J\033[H"); /* clear terminal */
        printf("Generation %d\n", gen);
        dump_field(field);
        evolve(field, newfield);
        memcpy(field, newfield, sizeof(field));
        usleep(100000); /* 100ms per generation */
    }

    return 0;
}

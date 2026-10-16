#ifndef LIFE_H
#define LIFE_H

#define ROWS 24
#define COLS 80
#define ALIVE 'O'
#define DEAD  '.'

int count_alive(char field[ROWS][COLS], int row, int col);
void evolve(char field[ROWS][COLS], char newfield[ROWS][COLS]);

#endif

#include "life.h"

int count_alive(char field[ROWS][COLS], int row, int col) {
    int count = 0;
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dr == 0 && dc == 0) continue;
            int r = row + dr;
            int c = col + dc;
            if (r >= 0 && r < ROWS && c >= 0 && c < COLS)
                if (field[r][c] == ALIVE)
                    count++;
        }
    }
    return count;
}

void evolve(char field[ROWS][COLS], char newfield[ROWS][COLS]) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            int n = count_alive(field, r, c);
            if (field[r][c] == ALIVE)
                newfield[r][c] = (n == 2 || n == 3) ? ALIVE : DEAD;
            else
                newfield[r][c] = (n == 3) ? ALIVE : DEAD;
        }
    }
}

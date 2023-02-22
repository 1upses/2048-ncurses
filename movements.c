#include "include/my.h"

void movement_up(int **grid)
{
    int i, j, k;

    for (j = 0; j < 4; j++) {
        for (i = 1; i < 4; i++) {
            if (grid[i][j] != 0) {
                k = i;
                while (k > 0 && grid[k-1][j] == 0) {
                    grid[k-1][j] = grid[k][j];
                    grid[k][j] = 0;
                    k--;
                }
            }
        }

        for (i = 1; i < 4; i++) {
            if (grid[i][j] == grid[i-1][j]) {
                grid[i-1][j] *= 2;
                grid[i][j] = 0;

                k = i;
                while (k < 3 && grid[k+1][j] != 0) {
                    grid[k][j] = grid[k+1][j];
                    grid[k+1][j] = 0;
                    k++;
                }
            }
        }
    }
}

void movement_left(int **grid)
{
    int i, j, k;

    for (i = 0; i < 4; i++) {
        for (j = 1; j < 4; j++) {
            if (grid[i][j] != 0) {
                k = j;
                while (k > 0 && grid[i][k-1] == 0) {
                    grid[i][k-1] = grid[i][k];
                    grid[i][k] = 0;
                    k--;
                }
            }
        }

        for (j = 1; j < 4; j++) {
            if (grid[i][j] == grid[i][j-1]) {
                grid[i][j-1] *= 2;
                grid[i][j] = 0;

                k = j;
                while (k < 3 && grid[i][k+1] != 0) {
                    grid[i][k] = grid[i][k+1];
                    grid[i][k+1] = 0;
                    k++;
                }
            }
        }
    }
}

void movement_right(int **grid)
{
    int i, j, k;

    for (i = 0; i < 4; i++) {
        for (j = 2; j >= 0; j--) {
            if (grid[i][j] != 0) {
                k = j;
                while (k < 3 && grid[i][k+1] == 0) {
                    grid[i][k+1] = grid[i][k];
                    grid[i][k] = 0;
                    k++;
                }
            }
        }

        for (j = 2; j >= 0; j--) {
            if (grid[i][j] == grid[i][j+1]) {
                grid[i][j+1] *= 2;
                grid[i][j] = 0;

                k = j;
                while (k > 0 && grid[i][k-1] != 0) {
                    grid[i][k] = grid[i][k-1];
                    grid[i][k-1] = 0;
                    k--;
                }
            }
        }
    }
}

void movement_down(int **grid)
{
    int i, j, k;

    for (j = 0; j < 4; j++) {
        for (i = 2; i >= 0; i--) {
            if (grid[i][j] != 0) {
                k = i;
                while (k < 3 && grid[k+1][j] == 0) {
                    grid[k+1][j] = grid[k][j];
                    grid[k][j] = 0;
                    k++;
                }
            }
        }

        for (i = 2; i >= 0; i--) {
            if (grid[i][j] == grid[i+1][j]) {
                grid[i+1][j] *= 2;
                grid[i][j] = 0;

                k = i;
                while (k > 0 && grid[k-1][j] != 0) {
                    grid[k][j] = grid[k-1][j];
                    grid[k-1][j] = 0;
                    k--;
                }
            }
        }
    }
}

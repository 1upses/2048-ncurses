#include "include/my.h"

bool user_lost(int **grid) {
    int i, j;

    if (!is_full(grid)) return false;


    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[i][j] == grid[i][j+1]) {
                return false;
            }
        }
    }

    for (j = 0; j < 4; j++) {
        for (i = 0; i < 3; i++) {
            if (grid[i][j] == grid[i+1][j]) {
                return false;
            }
        }
    }

    return true;
}


int main(void)
{
    srand(time(NULL));
    int **grid = malloc(sizeof(int *) * 4);
    grid[0] = malloc(sizeof(int) * 4);
    grid[1] = malloc(sizeof(int) * 4);
    grid[2] = malloc(sizeof(int) * 4);
    grid[3] = malloc(sizeof(int) * 4);
    int k = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            grid[i][j] = 0;
        }
    }
    generate_new_block(grid);
    generate_new_block(grid);
    initscr();
    keypad(stdscr, TRUE);
    int key;
    while (true) {
        clear();
        if (user_lost(grid)) {
            endwin();
            return 0;
        }
        if (key == 32) break;
        switch(key) {
            case KEY_UP:
                movement_up(grid);
                generate_new_block(grid);
                break;
            case KEY_DOWN:
                movement_down(grid);
                generate_new_block(grid);
                break;
            case KEY_LEFT:
                movement_left(grid);
                generate_new_block(grid);
                break;
            case KEY_RIGHT:
                movement_right(grid);
                generate_new_block(grid);
        }
        display(grid);
        refresh();
        key = getch();
    }
    endwin();
    return 0;
}

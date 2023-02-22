#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#ifndef header
    #define header

char *center_string(char *src, char *str);
char *int_to_str(int n);
int int_size(int n);
void display(int **grid);
bool generate_new_block(int **grid);
bool is_full(int **grid);
void movement_up(int **grid);
void movement_left(int **grid);
void movement_right(int **grid);
void movement_down(int **grid);

#endif /* !header */

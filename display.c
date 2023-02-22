#include "include/my.h"

char *extract_cell(char *line, int size, int pos)
{
    // +- --*-- -+ \0  ->  size + 4 + 1 = size + 5
    char *cell = malloc(sizeof(char) * size + 5);
    int start_pos = (3 + size) * pos;
    int cell_size = 4 + size;
    int i = 0;

    while (i < cell_size) {
        cell[i] = line[start_pos + i];
        i++;
    }
    cell[i] = '\0';
    return cell;
}

void insert_cell(char *line, char *cell, int size, int pos)
{
    int start_pos = (3 + size) * pos;
    int cell_size = 4 + size;
    int i = 0;

    while (i < cell_size) {
        line[start_pos + i] = cell[i];
        i++;
    }
}

void insert_numbers(char *line, int *numbers, int size)
{
    char *number;
    char *cell;

    for (int i = 0; i < 4; i++) {
        number = int_to_str(numbers[i]);
        cell = extract_cell(line, size, i);
        cell = center_string(cell, number);
        insert_cell(line, cell, size, i);
    }
}

int get_size(int **grid)
{
    int new_size, size = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            new_size = int_size(grid[i][j]);
            if (new_size > size) size = new_size;
        }
    }
    return size;
}

void display(int **grid)
{
    int j;
    int size = get_size(grid);
    char line[(3 + size) * 4 + 1];
    char separator[(3 + size) * 4 + 1];

    j = 0;
    while (j < (3 + size) * 4 + 1) {
        if (j % (3 + size) == 0) separator[j] = '+';
        else separator[j] = '-';
        j++;
    }
    separator[j] = '\0';

    for (int i = 0; i < 9; i++) {
        if (i % 2 == 0) {
            printw("%s\n", separator);
        } else {
            j = 0;
            while (j < (3 + size) * 4 + 1) {
                line[j] = ' ';
                j++;
            }
            line[j] = '\0';
            for (int k = 0; k < 5; k++) {
                line[k * (3 + size)] = '|';
            }
            insert_numbers(line, grid[i / 2], size);
            printw("%s\n", line);
        }
    }
}

// int main(void)
// {
//     // struct game *grid = malloc(sizeof(struct game));
//     // int size = 2;
//     int **truc = malloc(sizeof(int *) * 4);
//     truc[0] = malloc(sizeof(int) * 4);
//     truc[1] = malloc(sizeof(int) * 4);
//     truc[2] = malloc(sizeof(int) * 4);
//     truc[3] = malloc(sizeof(int) * 4);
//     int numbers[] = {0, 0, 2, 4, 0, 0, 0, 2, 0, 2, 32, 8, 0, 32, 8, 2};
//     int k = 0;
//     for (int i = 0; i < 4; i++) {
//         for (int j = 0; j < 4; j++) {
//             truc[i][j] = numbers[k];
//             k++;
//         }
//     }
//     // grid->grid = truc;
//     // grid->size = size;
//     display(truc);

//     return 0;
// }
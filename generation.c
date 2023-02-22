#include "include/my.h"

// 90% de chance de générer un 2
// 10% de chance de générer un 4
int get_random_block()
{
    int value = rand() % 10;
    if (value <= 8) return 2;
    return 4;
}

bool is_full(int **grid)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] == 0)
                return false;
        }
    }
    return true;
}

bool generate_new_block(int **grid)
{
    if (is_full(grid)) return false;
    int position = rand() % 16;
    while (grid[position / 4][position % 4] != 0) {
        position = rand() % 16;
    }
    grid[position / 4][position % 4] = get_random_block();
    return true;
}

// int main(void)
// {
//     srand(time(NULL));
    
//     int **truc = malloc(sizeof(int *) * 4);
//     truc[0] = malloc(sizeof(int) * 4);
//     truc[1] = malloc(sizeof(int) * 4);
//     truc[2] = malloc(sizeof(int) * 4);
//     truc[3] = malloc(sizeof(int) * 4);
//     int numbers[] = {0, 0, 2, 2, 0, 0, 0, 2, 0, 2, 32, 8, 0, 32, 8, 2};
//     int k = 0;
//     for (int i = 0; i < 4; i++) {
//         for (int j = 0; j < 4; j++) {
//             truc[i][j] = numbers[k];
//             k++;
//         }
//     }
//     display(truc);
//     movement_up(truc);
//     display(truc);
//     return 0;
// }
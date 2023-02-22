#include "../include/my.h"

char *int_to_str(int n)
{
    int size = int_size(n), i = 0;
    char *array = malloc(sizeof(char) * size);
    while (i < size) {
        array[size - i - 1] = (n % 10) + '0';
        n /= 10;
        i++;
    }
    array[i] = '\0';
    return array;
}

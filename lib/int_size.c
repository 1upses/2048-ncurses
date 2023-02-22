#include "../include/my.h"

int int_size(int n)
{
    int i = 0;
    while (n != 0) {
        n /= 10;
        i++;
    }
    return i;
}

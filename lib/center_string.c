#include "../include/my.h"

char *center_string(char *src, char *str)
{
    int src_len = strlen(src);
    int str_len = strlen(str);
    int start_pos = (src_len - str_len) / 2;
    
    if (start_pos < 0) {
        start_pos = 0;
    }
    
    int end_pos = start_pos + str_len;
    
    for (int i = start_pos; i < end_pos; i++) {
        src[i] = str[i - start_pos];
    }
    return src;
}

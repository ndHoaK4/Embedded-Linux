#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "strutils.h"

void str_reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void str_trim(char *str) {
    char *start = str;
    char *end;

    // Bỏ khoảng trắng đầu
    while (isspace((unsigned char)*start)) start++;

    // Bỏ khoảng trắng cuối
    end = start + strlen(start) - 1;
    while (end > start && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';

    // Dời chuỗi về đầu
    memmove(str, start, end - start + 2);
}

int str_to_int(const char *str, int *out_num) {
    char *endptr;
    long val = strtol(str, &endptr, 10);
    if (*endptr != '\0') return 0; // không phải số hợp lệ
    *out_num = (int)val;
    return 1;
}

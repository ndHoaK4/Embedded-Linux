#include <stdio.h>
#include "strutils.h"

int main() {
    char str1[] = "  Hello World  ";
    char str2[] = "12345";
    char str3[] = " OpenAI ";

    int num;

    printf("Before trim: '%s'\n", str1);
    str_trim(str1);
    printf("After trim: '%s'\n", str1);

    printf("Before reverse: '%s'\n", str3);
    str_reverse(str3);
    printf("After reverse: '%s'\n", str3);

    if (str_to_int(str2, &num)) {
        printf("Converted '%s' to integer: %d\n", str2, num);
    } else {
        printf("Failed to convert '%s'\n", str2);
    }

    return 0;
}

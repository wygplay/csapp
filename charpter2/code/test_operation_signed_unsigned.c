#include <stdio.h>

int main() {
    short a = -1;
    unsigned short b = 1;
    printf("%d\n", -1 < 0U);
    // short and unsigned short is converted to int by C default
    printf("%d\n", a + b);
    int c = -16;
    unsigned int d = 1;
    // printf %d convert result to (signed) int
    printf("%d\n", c + d);
}

#define _GNU_SOURCE 1
#include <stdio.h>
#include <math.h>

int main() {
    float f = 0;
    printf("%d\n", f == -(-f));
    int result = INFINITY * INFINITY >= 0.0;
    printf("%d\n", result);
}

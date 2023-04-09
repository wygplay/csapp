#include <stdio.h>

int main() {
    int a[4] = {1, 2, 3, 4};
    int* addr_first = &a[0];
    addr_first++;
    long index = addr_first - a;
    printf("++&a[i] - a is i + 1: %ld\n", index);
}

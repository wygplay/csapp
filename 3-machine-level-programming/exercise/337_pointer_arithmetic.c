#include <stdio.h>

int main() {
    int a[3] = {1, 2, 3};
    long i = &a[2] - a;
    printf("&a[i] - a is i,  &a[2] - a ==> %ld\n", i);
    return 0;
}

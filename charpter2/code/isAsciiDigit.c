#include <stdio.h>

int isAsciiDigit(int x) {
    return !(x >>6 | (x & 0x30) ^ 0x30) & (!(x & 0x08) | !(x & 0x06));
}

int main() {
    int num;
    scanf("%d", &num);
    printf("%d\n", isAsciiDigit(num));
    return 0;
}

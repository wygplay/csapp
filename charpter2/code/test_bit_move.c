#include <stdio.h>

int main() {
    char a = 1;
    char b = a << 4;
    char c = a << 8;
    char d = a << 9;
    printf("char类型数字1左移4位：%d\n", b);
    printf("char类型数字1左移8位：%d\n", c);
    printf("char类型数字1左移9位：%d\n", d);
}

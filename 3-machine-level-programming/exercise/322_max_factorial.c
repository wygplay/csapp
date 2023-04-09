#include <stdio.h>

int max_factorial_number_in_32() {
    int sum = 1;
    int sign = 0;
    int n = 1;
    int factor = 1;
    while(sum / factor == n) {
        n = n + 1;
        factor = sum;
        sum = n * factor;
    }
    return n - 1;
}

 long max_factorial_number_in_64() {
    long sum = 1;
    long sign = 0;
    long n = 1;
    long factor = 1;
    while(sum / factor == n) {
        n = n + 1;
        factor = sum;
        sum = n * factor;
    }
    return n - 1;
}

int main() {
    printf("32阶乘最大非溢出整数为：%d\n", max_factorial_number_in_32());
    printf("64阶乘最大非溢出整数为：%ld\n", max_factorial_number_in_64());
    return 0;
}

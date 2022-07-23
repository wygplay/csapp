#include <stdio.h>

int main() {
    // 测试小端法数组取指针值
    int num = 1;
    int *p = &num;
    printf("%d\n", p[0]);
}

#include <stdio.h>

int equals(int x, int y) {
    if (x ^ y) {
        return 0;
    } 
    return 1;
}

int main() {
    printf("比较输入的两个数字，输入时以空格区分：");
    int x,y;
    scanf("%d %d", &x, &y);
    if (equals(x, y)) {
        printf("相等\n");
    } else {
        printf("不相等\n");
    }
}

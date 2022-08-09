#include <stdio.h>
#include <limits.h>

int tadd_ok(int x, int y) {
    int sum = x + y;
    int neg_over = x < 0 && y < 0 && sum >= 0;
    int pos_over = x > 0 && y > 0 && sum < 0;
    return !neg_over && !pos_over;
}

int tsub_ok(int x, int y) {
    int tmp = -y;
    int sum = x + tmp;
    // 当y等于INT_MIN时，y=-y, tadd_ok判断的方式不正确
    if (y == INT_MIN && x < 0)
        return 1;
    else if (y == INT_MIN && x >= 0) 
        return 0;
    else if ((x > 0 && tmp > 0 && sum <= 0) || (x <= 0 && tmp <= 0 && sum > 0))
        return 0;
    else
        return 1;

}

int main() {
    int x,y;
    printf("请输入两个数字，数字间用空格隔开: ");
    scanf("%d %d", &x, &y);
    int result = tsub_ok(x, -y);
    if (result)
        printf("未溢出：%d\n", x + y);
    else
        printf("溢出：%d\n", x + y);

}

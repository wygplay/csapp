#include <stdio.h>

int tsub_ok(int x, int y) {
    int tmp = -y;
    int sum = x + tmp;
    if ((x > 0 && tmp > 0 && sum < 0) || (x < 0 && tmp < 0 && sum > 0))
        return 0;
    else
        return 1;

}

int main() {
    int x,y;
    printf("请输入两个数字，数字间用空格隔开: ");
    scanf("%d %d", &x, &y);
    int result = tsub_ok(x, y);
    if (result)
        printf("未溢出：%d\n", x + y);
    else
        printf("溢出：%d\n", x + y);

}

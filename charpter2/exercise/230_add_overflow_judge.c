#include <stdio.h>

int tadd_ok(int x, int y) {
    int sum = x + y;
    if ((x > 0 && y > 0 && sum <= 0) || (x <= 0 && y <= 0 && sum > 0))
        return 0;
    else
        return 1;
}

int main() {
    int x,y;
    printf("请输入两个数字，数字间用空格隔开: ");
    scanf("%d %d", &x, &y);
    int result = tadd_ok(x, y);
    if (result)
        printf("和未溢出：%d\n", x + y);
    else
        printf("溢出：%d\n", x + y);

}

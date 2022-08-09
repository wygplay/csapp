#include <stdio.h>
#include <stdint.h>

int tmult_ok(int x, int y) {
    int p = x * y;
    return !x || p / x == y;
}
/**
 * 判断溢出不能只判断高32位的值是否为有效数字：全为0或全为1
 * 并不是所有溢出都是位溢出
 * 以下是错误案例
 */
int tmult_ok_without_divide_with_bug(int x, int y) {
    int64_t p = (int64_t) x * y;
    int high32 = (p >> 32) & 0xFFFFFFFF;
    printf("high32: %d\n", high32);
    return high32 == -1 || high32 == 0; 
}

int tmult_ok_without_divide(int x, int y) {
    int64_t p = (int64_t) x * y;
    int q = x * y;
    return p == q;
}

int main() {
    int x,y;
    printf("请输入两个数字，并以空格分隔开：");
    scanf("%d %d", &x, &y);
    printf("tmult_ok: %d\n", tmult_ok(x, y));
    printf("tmult_ok_without_divide: %d\n", tmult_ok_without_divide(x, y));
    printf("结果是否一致：%d\n", tmult_ok(x, y) == tmult_ok_without_divide(x, y));
}

#include <stdio.h>

int main() {
    int tmp;
    printf("请输入char类型数字：");
    scanf("%d", &tmp); 
    char inputN = (char) tmp;
    char num = inputN + 1;
    printf("输入数字为：%d\n", inputN);
    printf("加1后结果为：%d\n", num);
}

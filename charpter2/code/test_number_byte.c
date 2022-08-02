#include <stdio.h>

extern void show_int(int num);
extern void show_long(long num);
extern void show_pointer(void *p);
extern void show_float(float num);
int main() {
    int num;
    printf("请输入int类型数字：");
    scanf("%d", &num);  
    float fNum = (float) num;
    int *pval = &num;
    long lNum = (long) num;
    show_int(num);
    show_long(lNum);
    show_float(fNum);
    show_pointer(pval);
}

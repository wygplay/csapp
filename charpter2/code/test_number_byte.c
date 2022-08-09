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
    printf("int字节序列：\n");
    show_int(num);
    printf("long字节序列：\n");
    show_long(lNum);
    printf("float字节序列：\n");
    show_float(fNum);
    printf("地址字节序列：\n");
    show_pointer(pval);
}

#include <stdio.h>

void inplace_swap(int *x, int *y) {
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void reverse_arr_with_bug(int a[], int cnt) {
    int first, last;
    for (first = 0, last = cnt; first <= last; first++, last--) {
        inplace_swap(&a[first], &a[last]);
    }
}

void reverse_arr(int a[], int cnt) {
    int first, last;
    for (first = 0, last = cnt; first < last; first++, last--) {
            inplace_swap(&a[first], &a[last]);
    }
}

int main() {
    int len = 5;
    int a[len];
    int b[len];
    printf("请输入%d个数字，按回车输入下一个\n", len);
    for (int i = 0; i < len; i ++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    reverse_arr_with_bug(a, len - 1);
    reverse_arr(b, len - 1);
    printf("reverse_arr_with_bug处理后的结果：");
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    
    printf("\n");
    printf("reverse_arr处理后的结果：");
    for (int i = 0; i < len; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}

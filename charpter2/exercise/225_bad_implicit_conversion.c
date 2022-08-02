#include <stdio.h>

float sum_elements(float a[], unsigned length){
    int i;
    float result = 0;
    // length = 0时，-1隐式转换为unsigned，数组会越界溢出
    for (i = 0; i <= length - 1; i++) {
        result += a[i];
    }
    return result;
}

int main() {
    float a[] = {1.0};
    //printf("%u", 0u - 1);
    sum_elements(a, 0u);
}

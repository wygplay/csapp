#include <stdio.h>

int gtZero(int num) {
    if (num > 0)
        return 1;
    else
        return 0;
}

int compareNum(int x, int y) {
    int result;
    if (x > y) {
        result = 1;
    } else if (x == y){
        result = 0;
    } else {
        result = -1;
    }
    return result;
}


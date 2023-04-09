#include <stdio.h>

void switch_translate(long n) {
    switch (n) {
        case 2:
            printf("one");
            break;
        case 4:
            printf("four");
            break;
        default:
            printf("others");
    }
}

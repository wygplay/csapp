#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_byte(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++) {
        printf(" %.2x", start[i]); 
    }
    printf("\n");
}

void show_int(int x) {
    show_byte((byte_pointer) &x, sizeof(int));
}

void show_float(float x ) {
    show_byte((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_byte((byte_pointer) &x, sizeof(void *));
}

void show_long(long x) {
    show_byte((byte_pointer) &x, sizeof(long));
}


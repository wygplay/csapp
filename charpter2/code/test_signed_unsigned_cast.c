#include <stdio.h>

typedef unsigned char *byte_pointer;
extern void show_byte(byte_pointer p, ssize_t len);
int main() {
    short v = -12345;
    unsigned short uv = (unsigned short) v;
    printf("v = %d, uv = %u\n", v, uv);
    show_byte((byte_pointer) &v, sizeof(short));
    show_byte((byte_pointer) &uv, sizeof(short));
}

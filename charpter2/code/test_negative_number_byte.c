#include <stdio.h>

typedef unsigned char *byte_pointer;

extern void show_byte(byte_pointer p, ssize_t len);

int main() {
   short n = 12345;
   short mn = -n;
   show_byte((byte_pointer)&n, sizeof(short));
   show_byte((byte_pointer)&mn, sizeof(short));
}


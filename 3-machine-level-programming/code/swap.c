#include <stdio.h>

void swap(long *xp, long *xy) {
    long t0 = *xp;
    long t1 = *xy;
    *xp = t1;
    *xy = t0;
}

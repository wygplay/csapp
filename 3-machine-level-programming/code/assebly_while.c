#include <stdio.h>

long fact_while(int n) {
   long result = 1;
   while (n > 1) {
       result *= n;
       --n;
   }
   return result;
}

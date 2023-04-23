#include <stdio.h>
#include <unistd.h>

int snooze(unsigned int secs) {
  unsigned int remains = sleep(secs);
  printf("slept for %d of %d seconds\n", secs - remains, secs);
  return remains;
}

int main() {
  snooze(20);
  return 0;
}

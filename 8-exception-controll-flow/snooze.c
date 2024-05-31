#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "csapp.h"

void sigint_handler(int sig) {
  printf("CRTL+C\n");
}
int snooze(unsigned int secs) {
  if (signal(SIGINT, sigint_handler) == SIG_ERR) {
    unix_error("signal error");
  }
  unsigned int remains = sleep(secs);
  printf("slept for %d of %d seconds\n", secs - remains, secs);
  return remains;
}

int main(int args, char *argv[]) {
  if (args == 1) {
    printf("缺少时间参数");
    exit(1);
  }
  int seconds = atoi(argv[1]);
  snooze(seconds);
  return 0;
}

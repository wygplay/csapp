#include "csapp.h"
#include <signal.h>

volatile sig_atomic_t pid;

void sigchld_handler(int sig) {
  int olderrno = errno;
  pid = Waitpid(-1, NULL, 0);
  errno = olderrno;
}

void sigint_handler(int s) {}

int main(int argc, char **argv) {
  sigset_t mask, prev;
  Signal(SIGINT, sigint_handler);
  Signal(SIGCHLD, sigchld_handler);
  Sigemptyset(&mask);
  Sigaddset(&mask, SIGCHLD);

  while (1) {
    Sigprocmask(SIG_BLOCK, &mask, &prev);
    if (Fork() == 0) {
      exit(0);
    }
    pid = 0;
    Sigprocmask(SIG_SETMASK, &prev, NULL);
    while (!pid)
      ;
    printf(".");
  }
  exit(0);
}

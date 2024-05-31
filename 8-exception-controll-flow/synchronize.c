#include "csapp.h"

void initjobs() {}

void deletejob(int pid) {}

void addjob(int pid) {}

void handler(int sig) {
  int olderrno = errno;
  sigset_t mask_all, prev_all;
  pid_t pid;
  Sigfillset(&mask_all);
  while ((pid = wait(NULL)) > 0) {
    Sigprocmask(SIG_BLOCK, &mask_all, &prev_all);
    deletejob(pid);
    Sigprocmask(SIG_UNBLOCK, &prev_all, NULL);
  }
  errno = olderrno;
}

int main_with_error(int argc, char **argv) {
  int pid;
  sigset_t mask_all, prev_all;

  Sigfillset(&mask_all);
  Signal(SIGCHLD, handler);
  initjobs();

  while (1) {
    if ((pid = Fork()) == 0) {
      // would terminate before addjob executing in parent process
      // so deletejob in handler maybe be executed ahead of addjob in main
      // process
      Execve("/bin/date", argv, NULL);
    }
    Sigprocmask(SIG_BLOCK, &mask_all, &prev_all);
    addjob(pid);
    Sigprocmask(SIG_SETMASK, &prev_all, NULL);
  }
  exit(0);
}

int main(int argc, char **argv) {
  int pid;
  sigset_t mask_all, mask_one, prev_one;

  Sigfillset(&mask_all);
  Sigemptyset(&mask_one);
  Sigaddset(&mask_one, SIGCHLD);
  Signal(SIGCHLD, handler);
  initjobs();

  while (1) {
    Sigprocmask(SIG_BLOCK, &mask_one, &prev_one);
    if ((pid = Fork()) == 0) {
      // 子进程继承父进程阻塞集合，因此需要先解除阻塞
      Sigprocmask(SIG_UNBLOCK, &prev_one, NULL);
      Execve("/bin/date", argv, NULL);
    }
    Sigprocmask(SIG_BLOCK, &mask_all, NULL);
    addjob(pid);
    // 解除所有阻塞信号
    Sigprocmask(SIG_UNBLOCK, &prev_one, NULL);
  }
}

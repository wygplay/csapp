// gcc fork.c csapp.c -o fork.out -pthread
#include "csapp.h"
#include <asm-generic/errno-base.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void fork1() {
  pid_t pid;
  int x = 1;
  pid = Fork();
  if (pid == 0) {
    printf("child : x=%d\n", ++x);
    exit(0);
  }
  printf("parent: x=%d\n", --x);
  exit(0);
}

void fork2() {
  printf("L0\n");
  fork();
  printf("L1\n");
  fork();
  printf("Bye\n");
}

void fork4() {
  printf("L0\n");
  if (fork() != 0) {
    printf("L1\n");
    if (fork() != 0) {
      printf("L2\n");
    }
  }
  printf("Bye\n");
}

/**
 * zombie example
 */
void fork7() {
  if (fork() == 0) {
    // child
    printf("Terminating child , PID = %d\n", getpid());
    exit(0);
  } else {
    printf("Running Parent, PID = %d\n", getpid());
    while (1)
      ;
  }
}

/**
 * zombie non terminating child
 */
void fork8() {
  if (fork() == 0) {
    // child
    printf("Running child , PID = %d\n", getpid());
    while (1)
      ;
  } else {
    printf("Terminating Parent, PID = %d\n", getpid());
    exit(0);
  }
}

/**
 * wait synchronizing with children
 */
void fork9() {
  int child_status;
  if (fork() == 0) {
    printf("HC: hello from child\n");
    exit(0);
  } else {
    printf("HC: hello from parent\n");
    wait(&child_status);
    printf("CT: child has terminated\n");
  }
  printf("Bye\n");
}

/**
 * multiple children
 */
void fork10() {
  int N = 3;
  pid_t pid[N];
  int i, child_status;

  for (i = 0; i < N; i++) {
    if ((pid[i] = fork()) == 0) {
      exit(i + 100);
    }
  }

  for (i = 0; i < N; i++) {
    pid_t wpid = wait(&child_status);
    if (WIFEXITED(child_status)) {
      printf("Child %d terminated with exit status %d\n", wpid,
             WEXITSTATUS(child_status));
    } else {
      printf("Child %d terminated abnormally\n", wpid);
    }
  }
}

/**
 * waitpid waiting for a specific process
 */
void fork11() {
  pid_t pid[3];
  int i;
  int child_status;

  for (i = 0; i < 3; i++) {
    if ((pid[i] = fork()) == 0) {
      exit(i + 100);
    }
  }

  for (i = 2; i >= 0; i--) {
    pid_t wpid = waitpid(pid[i], &child_status, 0);
    if (WIFEXITED(child_status)) {
      printf("Child %d terminated with exit status %d\n", wpid,
             WEXITSTATUS(child_status));
    } else {
      printf("Child %d terminated abnormally\n", wpid);
    }
  }
}
int ccount = 0;
/**
 * this function with bug
 * don't wait all child processes terminated and some pending signals will be
 * discarded finally ccount will not be zero in fork14, and main program will
 * never exit
 */
void child_handler(int sig) {
  int olderrno = errno;
  pid_t pid;
  if ((pid = wait(NULL)) < 0) {
    Sio_error("wait error");
  }
  ccount--;
  Sio_puts("Handler repead child ");
  Sio_putl((long)pid);
  Sio_puts(" \n");
  sleep(1);
  errno = olderrno;
}
void child_handler2(int sig) {
  int olderrno = errno;
  pid_t pid;
  while ((pid = wait(NULL)) > 0) {
    ccount--;
    Sio_puts("Handler repead child ");
    Sio_putl((long)pid);
    Sio_puts(" \n");
  }
  if (errno != ECHILD)
    Sio_error("Wait error");
  errno = olderrno;
}
void fork14() {
  int N = 4;
  pid_t pid[N];
  int i;
  ccount = N;
  Signal(SIGCHLD, child_handler2);
  for (i = 0; i < N; i++) {
    if ((pid[i] = Fork()) == 0) {
      Sleep(1);
      exit(0);
    }
  }
  while (ccount > 0)
    ;
}
int main() {
  // fork1();
  // fork2();
  // fork4();
  // fork7();
  // fork8();
  // fork10();
  fork14();
  return 0;
}

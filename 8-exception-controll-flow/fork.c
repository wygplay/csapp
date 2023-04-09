// gcc fork.c csapp.c -o fork.out -pthread
#include "csapp.h"
#include <stdio.h>
#include <stdlib.h>
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

int main() {
  // fork1();
  // fork2();
  fork4();
  return 0;
}

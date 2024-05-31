#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[]) {
  pid_t pid;
  char *myargv[3];
  myargv[0] = "/usr/bin/ls";
  myargv[1] = "-lt";
  myargv[2] = "/home/wyg/projects/";
  char *myenvp[4];
  myenvp[0] = "USER=wyg";
  myenvp[1] = "PWD=/home/wyg/";
  myenvp[2] = "SHELL=/bin/bash";
  myenvp[3] = "PATH=/usr/bin";
  if ((pid = fork()) == 0) {
    if (execve(myargv[0], myargv, myenvp) < 0) {
      printf("%s: Command not found.\n", myargv[0]);
      exit(1);
    }
  }
}

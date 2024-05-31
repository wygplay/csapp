#include "csapp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXARGS 100

void eval(char *cmdLine) {
  char *argv[MAXARGS];
  char buf[MAXLINE];
  int bg;
  pid_t pid;

  strcpy(buf, cmdLine);
  bg = parseline(buf, argv);
  if (argv[0] == NULL) {
    return;
  }

  if (!builtin_command(argv)) {
    if ((pid = Fork()) == 0) {
      if (execve(argv[0], argv, environ) < 0) {
        printf("%s: Command not found\n", argv[0]);
        exit(0);
      }
    }

    if (!bg) {
      int status;
      if (waitpid(pid, &status, 0) < 0) {
        unix_error("waitfg: waitpid error");
      } else {
        printf("%d %s", pid, cmdLine);
      }
    }
  }
  return;
}
int main() {
  char cmdLine[MAXLINE];

  while (1) {
    printf("> ");
    Fgets(cmdLine, 100, stdin);
    if (feof(stdin)) {
      exit(0);
    }
    eval(cmdLine);
  }
}

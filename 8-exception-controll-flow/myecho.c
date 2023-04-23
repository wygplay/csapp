#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
  printf("Command-line arguments:\n");
  int i;
  for (i = 0; i < argc; i++) {
    printf("arg[%d]: %s\n", i, argv[i]);
  }
  printf("Enviroment variables:\n");
  int length = sizeof *envp;
  for (i = 0; i < length; i++) {
    printf("arg[%d]: %s\n", i, envp[i]);
  }
  return 0;
}

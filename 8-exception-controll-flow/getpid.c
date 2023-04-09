#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int pid = getpid();
    printf("current pid is: %d\n", pid);
    sleep(10);
}

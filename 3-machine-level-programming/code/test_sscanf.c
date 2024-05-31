#include <stdio.h>

int main() {
    char *str = "12 34";
    int firstNumber;
    int secondNumber;
    sscanf(str, "%d %d", &firstNumber, &secondNumber);
    printf("str is: %s, firstNumber: %d, secondNumber: %d\n", str, firstNumber, secondNumber);
}

#include <stdio.h>

int fib(int a);

int main(void) {
    int a;
    char check;
    if (scanf("%d%c", &a, &check) != 2 || check != '\n' || a < 0 || a > 45)
        printf("n/a");
    else
        printf("%d", fib(a));
    return 0;
}

int fib(int a) {
    int result;

    if (a == 0) result = 0;
    else if (a == 1) result = 1;
    else result = fib(a - 1) + fib(a - 2);

    return result;
}

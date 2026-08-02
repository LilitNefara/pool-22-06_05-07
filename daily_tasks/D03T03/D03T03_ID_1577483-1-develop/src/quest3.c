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
    if (a == 0) return 0;
    if (a == 1) return 1;
    return fib(a - 1) + fib(a - 2);
}

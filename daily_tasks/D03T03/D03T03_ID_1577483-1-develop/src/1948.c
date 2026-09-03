#include <stdio.h>

int func(int a);

int main(void) {
    int a;
    char check;
    if (scanf("%d%c", &a, &check) == 2 && check == '\n') {
        printf("%d", func(a));
    } else
        printf("n/a");
    return 0;
}

int func(int a) {
    if (a < 0) {
        a = -a;
    }
    int result;
    for (int i = 1; i < a; i++) {
        int b = a;
        while (b > 0) {
            b -= i;
        }
        if (b == 0) {
            int count = 0;
            for (int c = 1; c <= i; c++) {
                int test = i;
                while (test > 0)
                    test -= c;
                if (test == 0) 
                    count++;
                }
            if (count == 2)
                result = i;
        }
    }
    return result;
}

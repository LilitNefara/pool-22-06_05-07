#include <stdio.h>

int main(int a, char* argv[]) {
        if (a < 1) return printf("%d", a);
        switch (*argv[1]) {
        case '0': {
            char x1, x2, x3, x4, x5;
            scanf("%c %c %c %c %c", &x1, &x2, &x3, &x4, &x5);
            printf("%x %x %x %x %x", x1, x2, x3, x4, x5);
            break;
        }
        case '1': {
            int w, b, c, d, e;
            scanf("%x %x %x %x %x", &w, &b, &c, &d, &e);
            printf("%c %c %c %c %c", (char)w, (char)b, (char)c, (char)d, (char)e);
            break;
        }
    }
    return 0;
    }

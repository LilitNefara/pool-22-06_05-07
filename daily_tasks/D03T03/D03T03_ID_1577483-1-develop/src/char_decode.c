#include <stdio.h>

void code();
void decode();

int main(int argc, char **argv) {
    int error = 0;

    if (argc != 2) {
        printf("n/a");
        error = 1;
    }
    argv++;

    char mode = **argv;
    char next_char = *(*argv + 1);

    if ((mode != '0' && mode != '1') || next_char != '\0') error = 1;

    if (error == 0) {
        if (mode == '0') {
            code();
        }
        
        // if (argv[1][0] == '0' && argv[1][1] == '\0') {
            
        // }
    //      else if (argv[1][0] == '1' && argv[1][1] == '\0') {
    //     int w, b, c, d, e;
    //     if (scanf(" %x %x %x %x %x", &w, &b, &c, &d, &e) == 5) printf("%c %c %c %c %c", (char)w, (char)b, (char)c, (char)d, (char)e);
    //     else error = 1;
    // } else error = 1;
    }
    if (error == 1) printf("n/a");
    return 0;
    }

// void code() {                                                                                    mandarin_version
//     char x, space_check;
//     while (scanf(" %c%c", &x, &space_check) >= 1) {
//         if (space_check == '\n') {
//             printf("%X", x);
//             break;
//         }
//         if (space_check == ' ') printf("%X ", x);
//     }
// }

void code() {
    char x, space_check = ' ', go = 's';
    while (go == 's') {
        if (scanf(" %c%c", &x, &space_check) == 2 && space_check == ' ') printf("%X ", x);
        if (space_check == '\n') {
            go = 'b';
            printf("%X", x);
        }
    }
}

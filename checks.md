gcc -Wall -Wextra -Werror -std=c11 main.c -o main
cppcheck --enable=all --suppress=missingIncludeSystem main.c

clang-format -i main.c
clang-format -n main.c

leaks -atExit -- ./main | grep LEAK:
# EXAM_03_04. Inside the interval
The russian version of the task can be found in the repository.

## Task
| Exam_03_04 ||
| ------ | ------- |
| Level: | 3. |
| Topics: | Data types, variables, expressions, logical actions and math functions. |
| Directory for the solution: | src/ |
| Solution files: | main.c |
| Input data: | Standard input stream (stdin) |
| Output data: | Standart output stream (stdout) |

Три целых числа (A, B и C) поступают через стандартный поток ввода — stdin. Необходимо вывести единицу в стандартный поток вывода — stdout, если C строго между A и B, в противном случае вывести ноль. В конце ответа не должно быть перевода строки. Проверьте корректность введенных данных. В случае ошибки выведите «n/a».

> **Note:** Условный оператор if можно использовать только для обработки ошибок.

## Examples

| Input | Output |
| ------ | ------ |
| 0 9 4 | 1 |
| 0 1 4 | 0 |
| 0 0 0 | 0 |

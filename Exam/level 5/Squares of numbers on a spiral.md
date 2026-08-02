# EXAM_06_05. Squares of numbers on a spiral
The russian version of the task can be found in the repository.

## Task
| Exam_06_05 ||
| ------ | ------- |
| Level: | 5. |
| Topics: | Matrices. |
| Directory for the solution: | src/ |
| Solution files: | main.c |
| Input data: | Standard input stream (stdin) |
| Output data: | Standart output stream (stdout) |

Напишите программу, которая заполняет квадратную матрицу «N x N» по спирали против часовой стрелки, начиная с левого верхнего угла, квадратами с числами от 0 до N^2 - 1. Порядок матрицы N указан в стандартном потоке ввода — stdin — в виде положительного ненулевого числа. Выведите полученную матрицу в стандартный поток вывода — stdout — в виде таблицы (после каждой выведенной строки матрицы должен быть перенос строки), элементы должны быть разделены пробелами, а перед переносами строк не должно быть пробелов. В конце ответа перенос строки не нужен. Проверьте корректность введенных данных. В случае ошибки выведите «n/a».

## Examples

| Input | Output |
| ------ | ------ |
| 2 | 0 9<br> 1 4|
| 3 | 0 49 36<br> 1 64 25<br> 4 9 16 |


> **Attention:** We kindly remind you that the procedure for testing your program includes an analysis of the code style. Please look in the "materials /" folder. Also, be sure to check your program for memory leaks.
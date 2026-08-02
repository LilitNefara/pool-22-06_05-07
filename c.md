float = 4.5f <!-- вывод%.2 это числа после точки = 3,14
const short A = 0; <!-- нельзя переопределить (верх регистр)
scanf("%d", &x) <!-- принятие числа от пользователя
int arr[3] = {1, 2, 3} <!-- создание массива
int arr[1][2] = { {1}, {2} } <!-- создание двумерного массива

# Строки
char str[] = "Hello!"
char str[] = {'S', 'o', 'm', 'e', '\0'} <!-- \0 обязателен(что-то связанное с байтом в конце строки)

printf("%s\n", str) <!-- вывод строки
for(int i = 0; str[i]; i++) printf("%c", str[i]); <!-- вывод строки по символам

# Условные операторы
if(x == 3) printf("Yes");
else if(x > 5) printf("elif");
else printf("else");
    <!-- выполнение после условия пишется в {} когда условие больше одной строки. or = || ; and = &&

continue <!-- пропуск итерации (не завершает цикл а пропускает)
break <!-- выход из цикла



switch(x) { 
    case 10: printf("10"); break;
    case 15: printf("15"); break;}
    default: printf("Error"); 
    <!-- выполняет только точные условия(без > < )
    дефолт - выплдняется если все кейсы не сработали
    брейк на последнем условии не нужен и нужен для того, чтобы не выводить предыдущие(not True) кейсы

# Циклы
for(int i = 0; i < 10; i++) {printf("%d", i)}



while(isHasCar) {
    printf("%d", i); 
    isHasCar == false;
}



do {printf("Yes\n")}; <!-- выполняется, а потом проверяет условие
while(isHasCar);

# Функции
void info(void); <!-- функции под мейном, но указывает до
int main() {
    return 0;
}
void info() {printf("Hello")}

func.h <!-- загаловочный файл(вынос функции)
#include "func.h" <!-- в мейн файле

# Структуры (Классы)
struct Car {
    int speed;
    char name[50];
    float weight;
};
struct Car bmw; <!-- название структуры
strcpy(bmw.name, "BMW 760");

# Pointers (Указатели)
int num = 0;
int * pNum = &num; <!-- создание указателя = присваивание адреса переменной
printf("%d", *pNum); <!-- вывод через указателя

# File
FILE *file = fopen("test.txt"m)
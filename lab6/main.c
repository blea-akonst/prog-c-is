#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");

    printf("«адание 1: \n");
    char arr[] = {'a', 'b', 'c', 'd'};
    char *p = arr; // создаем указатель на массив
    printf("%c %c\n%c %c\n", *p, *(p+1), *(p+2), *(p+3));

    printf("«адание 2: \n");

    char *arr2 = (char*)malloc(4*sizeof(char)); // выдел€ем 4 байта пам€ти под массив
    char *p2 = arr2;
    *(p2) = 'a';
    *(p2+1) = 'b';
    *(p2+2) = 'c';
    *(p2+3) = 'd';
    for (int i = 0; i < 4; i++)
    {
        printf ("%c\n", *(p2+i));
    }

    free (arr2); // возвращает пам€ть, на которую указывает arr2, назад
    return 0;
}
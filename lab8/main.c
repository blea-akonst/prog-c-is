#include <stdio.h>
#include <string.h>
#include <locale.h>

// sum, compare, copy, length, search last

int main() {
    setlocale(LC_ALL, "Rus");

    // 1 //

    printf("Задание 1: \n");

    char str1[100]; // создаем массивы символов для записи строк
    char str2[100];

    printf("Введите первую строку: ");
    gets_s(str1, 100);
    char istr1[100];
    memcpy(istr1, str1, 100);

    printf("Введите вторую строку: ");
    gets_s(str2, 100);
    printf("\n");

    printf("Результат сложения введенных вами строк:\n");
    strcat((strcat(str1, " ")), str2);
    printf("%s\n \n", str1);

    memcpy(str1, istr1, 100);

    // 3 //

    printf("Задание 3:\n");
    printf("Результат сравнения введенных вами строк: ");
    if (strcmp(istr1, str2) == 0)
    {
        printf("строки идентичны");
    } else {
        printf("строки различны");
    }
    printf("\n \n");

    // 5 //

    printf("Задание 5:\n");

    strcpy(str2, str1);

    printf("Результат копирования первой строки во вторую: ");
    printf("%s \n \n", str2);

    // 7 //

    printf("Задание 7:\n");
    printf("Длина строки \"%s\": %d \n \n", str2, strlen(str2));

    // 9 //

    printf("Задание 9:\n");

    char *ach = strrchr(str2, 'a'); // указатель на искомую переменную

    if (ach == NULL) {
        printf("Искомый символ не найден");
    } else {
        printf("Искомый символ находится на позиции # %d", ach - str2 + 1);
    }
    return 0;
}
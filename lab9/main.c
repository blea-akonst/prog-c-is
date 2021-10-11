#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include <math.h>

int main() {
    setlocale(LC_ALL, "Ru");

    // Task 1 //

    printf("Задание 1: \n \n");

    int count_lc = 0; // счетчик строчных букв
    int count_uc = 0; // счетчик прописных букв
    int count_num = 0; // счетчик цифр

    char str[100];

    printf("Введите строку:");
    gets_s(str, 100);
    printf("\n");

    for (int i = 0; i < strlen(str); i++) {
        if (isdigit(str[i])) count_num++;
        else if (isupper(str[i])) count_uc++;
        else if (islower(str[i])) count_lc++;
    }

    printf("Количество цифр в строке: %d\n", count_num);
    printf("Количество прописных букв: %d\n", count_uc);
    printf("Количество строчных букв: %d \n \n", count_lc);

    // Task 2 //

    printf("Задание 2: \n \n");
    int minute, payment, over; // количество потр. минут, цена мес. пакета, цена мин. сверх пакета

    printf("Введите стоимость месячного пакета (499 минут разговора): ");
    scanf("%d", &payment);
    printf("\n");

    printf("Введите количество потраченных минут: ");
    scanf("%d", &minute);
    printf("\n");

    printf("Введите стоимость минуты сверх количества, включенного в пакет: ");
    scanf("%d", &over);
    printf("\n \n");

    int payment_over = payment + (minute - 499) * over;

    if (minute <= 499) printf("Стоимость пакета: %d руб.", payment);
    else if (minute < 0) printf ("Введите допустимое значение!");
    else if (minute > 499) printf("Стоимость пакета: %d руб.", payment_over);
    return 0;
}

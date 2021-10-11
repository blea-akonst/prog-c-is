#include <stdio.h>
#include <locale.h>

enum Days
{
    Monday, Tuesday, Wednesday,
    Thursday, Friday, Saturday,
    Sunday
};

struct rectangle {
    int width, length;
};

union Player
{
    int value;
    struct
    {
        unsigned char Play : 1;
        unsigned char Stop : 1;
        unsigned char Record : 1;
    };
};

int main() {
    setlocale(LC_ALL, "Ru");

    printf("Задание 1:\n");
    enum Days s = Monday;
    printf("%d\n", s);
    printf("\n");


    printf("Задание 2:\n");

    struct rectangle rect;

    printf("Введите длину прямоугольника: ");
    scanf("%d", &rect.length);
    printf("Введите ширину прямоугольника: ");
    scanf("%d", &rect.width);
    int square = rect.length * rect.width;
    printf("Площадь прямоугольника: ");
    printf("%d\n", square);

    printf("Задание 3:\n");
    union Player pl;
    printf("Введите число в шестнадцатеричной системе счисления: ");
    scanf("%x", &pl.value);
    printf("Воспроизведение: %s\ || Пауза: %s\ || Запись: %s \n",
           pl.Play ? "ВКЛ" : "ВЫКЛ",
           pl.Stop ? "ВКЛ" : "ВЫКЛ",
           pl.Record ? "ВКЛ" : "ВЫКЛ");
    return 0;
}
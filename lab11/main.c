// ???? main.c, ???????? ??????? main, ? ??????? ????????????? ? ??????? ??????????
// ? ?? ????? ??????? ? ???????? ??????????????

#include <stdio.h>
#include <locale.h>
#include "rectangle.h"

int main() {
    setlocale(LC_ALL, "Rus");

    struct Rectangle rect;
    printf("??????? ?????????? ?????? ????? ????? ??????: ");
    scanf("%lf %lf", &rect.x1, &rect.y1);

    printf("??????? ?????????? ?????? ????? ????? ??????: ");
    scanf("%lf %lf", &rect.x2, &rect.y2);

    printf("??????? ?????????? ??????? ????? ????? ??????: ");
    scanf("%lf %lf", &rect.x3, &rect.y3);

    printf("???????? = %.2lf \n", Perimeter(rect));
    printf("??????? = %.2lf \n", Area(rect));

    return 0;
}

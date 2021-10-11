// файл main.c, содержит функцию main, в которой запрашиваютс€ с консоли координаты
// и на экран площадь и периметр пр€моугольника

#include <stdio.h>
#include <locale.h>
#include "rectangle.h"

int main() {
    setlocale(LC_ALL, "Rus");

    struct Rectangle rect;
    printf("¬ведите координаты первой точки через пробел: ");
    scanf("%lf %lf", &rect.x1, &rect.y1);

    printf("¬ведите координаты второй точки через пробел: ");
    scanf("%lf %lf", &rect.x2, &rect.y2);

    printf("¬ведите координаты третьей точки через пробел: ");
    scanf("%lf %lf", &rect.x3, &rect.y3);

    printf("ѕериметр = %.2lf \n", Perimeter(rect));
    printf("ѕлощадь = %.2lf \n", Area(rect));

    return 0;
}

// файл "func.c", содержит функции для расчета периметра и площади

#include <math.h>
#include "rectangle.h"

double Perimeter(struct Rectangle rect){
    return 2 * (sqrt(pow(rect.x2 - rect.x1, 2) + pow(rect.y2 - rect.y1, 2)) + sqrt(pow(rect.x3 -
    rect.x1, 2) + pow(rect.y3 - rect.y1, 2)));
}

double Area(struct Rectangle rect){
    return sqrt(pow(rect.x2 - rect.x1, 2) + pow(rect.y2 - rect.y1, 2)) * sqrt(pow(rect.x3 - rect.x1, 2)
    + pow(rect.y3 - rect.y1, 2));
}

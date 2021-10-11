// заголовочный файл "rectangle.h", содержит структуру координат прямоугольника
// и прототипы функций

#ifndef LAB11_RECTANGLE_H
#define LAB11_RECTANGLE_H

struct Rectangle{
    double x1, y1;
    double x2, y2;
    double x3, y3;
};

double Perimeter(struct Rectangle);
double Area(struct Rectangle);

#endif //LAB11_RECTANGLE_H

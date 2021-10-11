#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(void) {
    double alpha, z1, z2;

    printf("Enter the degree measure of an angle: ");
    scanf_s("%lf", &alpha);
    alpha = alpha * M_PI/180;
    z1 = 2 * (pow(sin(3 * M_PI - 2 * alpha),2)) * (pow(cos(3 * M_PI + 2 * alpha),2));
    z2 = 1./4 - 1./4 * (sin((5./2) * M_PI - 8 * alpha));
    printf("Your answers: ");
    printf("z1 = %.3f; ", z1);
    printf("z2 = %.3f", z2);
    return 0;
}
#include <stdio.h>
#include <locale.h>

// lab 5, opt. 1

int main() {
    setlocale(LC_ALL, "Rus");
    int m = 7;
    int arr[7] = {10, 20, 30, 40, 50, 60, 70};
    printf("Ваш массив: \n");
    for (int i = 0; i < m; i++) printf("%d ", arr[i]);
    printf("\n\n");

    int mat1[2][2] = { { 1, 2 },
                       { 3, 4 } };
    int mat2[2][2] = { { 1, 0 },
                       { 0, 1 } };
    int res[2][2];

    for(int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    printf("Результат умножения матриц: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}

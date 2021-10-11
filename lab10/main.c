#include <stdio.h>
#include <math.h>
#include <locale.h>

// Çàäàíèå 1

int GCD (int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b) a = a % b;
        else b = b % a;
    }

    int result = a + b;
    return result;
}

int LCM (int a, int b) {
    int result = a / GCD(a, b) * b;
    return result;
}

void distances(int n, float arr[][n-1], float *crdx, float *crdy){
    int i, j, c = 0;

    for (i = 0; i < n; i ++){
        for (j = 0; j < n ; j ++){
            if (i == 0 && j == 0){
                arr[i][j] = sqrt(pow(crdx[i]-crdx[j + 1],2) + pow(crdy[i]-crdy[j + 1],2));
                j++;
                c++;
            }
            else{
                if (i == j){
                    c++;
                }
                else{
                    if (c == 0){
                        arr[i][j] = sqrt(pow(crdx[i]-crdx[j],2) + pow(crdy[i]-crdy[j],2));
                    }
                    else{
                        arr[i][j - 1] = sqrt(pow(crdx[i]-crdx[j],2) + pow(crdy[i]-crdy[j],2));
                    }
                }
            }
        }
        c = 0;
    }
}

int main() {
    setlocale (LC_ALL, "Ru");
    printf("Çàäàíèå 1: \n \n");

    int a, b;

    printf("Ââåäèòå ïåðâîå ÷èñëî: ");
    scanf("%d", &a);
    printf("\n");

    printf("Ââåäèòå âòîðîå ÷èñëî: ");
    scanf("%d", &b);
    printf("\n");

    int gcd = GCD(a, b);
    printf("ÍÎÄ ââåäåííûõ ÷èñåë: ");
    printf("%d \n", gcd);

    int lcm = LCM(a, b);
    printf("ÍÎÊ ââåäåííûõ ÷èñåë: ");
    printf("%d \n \n", lcm);

    // Çàäàíèå 2

    printf("Çàäàíèå 2: ");
    float x, y;
    int n, i, j;
    printf("\nÂâåäèòå êîëè÷åñòâî òî÷åê:");
    scanf("%d", &n);
    float crdx[n], crdy[n];
    float d[n][n - 1];
    for (i = 0; i < n; i ++){
        printf("Ââåäèòå x%d and y%d: ", i, i);
        scanf("%f %f", &x, &y);
        crdx[i] = x;
        crdy[i] = y;
    }
    distances(n, d, crdx, crdy);
    printf("\n");

    printf("Âàø ìàññèâ: \n");
    for (i = 0; i < n; i ++){
        for (j = 0; j < n - 1; j ++){
            printf("%f ", d[i][j]);
        }
        printf("\n");
    }

    return 0;
}
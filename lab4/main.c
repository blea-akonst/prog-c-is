#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Ru");

    int a;
    int first = 1;
    int last = 10; // задаем переменные, €вл€ющиес€ границами промежутка
    printf("¬ведите число: ");
    scanf("%d", &a);
    printf("Ћогический результат проверки вашего числа на попадание в интервал [1;10] (ложь/истина): ");
    printf("%d\n", a>= first && a <= last);

    int b;
    printf("¬ведите число:");
    scanf("%d", &b);
    printf("–езультат проверки: ");
    printf("%d", b % 2);
    return 0;
} // вариант 1, л. р. 4

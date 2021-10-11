#include <stdio.h>

int main(void) {
    int a;
    char str[100] = "";
    printf("Enter the string: ");
    fgets(str, 100, stdin);
    printf("Enter the number: ");
    scanf_s("%d", &a);
    printf("You entered:");
    puts(str);
    printf("%d", a);
    return 0;
}
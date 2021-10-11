#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include <math.h>

int main() {
    setlocale(LC_ALL, "Ru");

    // Task 1 //

    printf("������� 1: \n \n");

    int count_lc = 0; // ������� �������� ����
    int count_uc = 0; // ������� ��������� ����
    int count_num = 0; // ������� ����

    char str[100];

    printf("������� ������:");
    gets_s(str, 100);
    printf("\n");

    for (int i = 0; i < strlen(str); i++) {
        if (isdigit(str[i])) count_num++;
        else if (isupper(str[i])) count_uc++;
        else if (islower(str[i])) count_lc++;
    }

    printf("���������� ���� � ������: %d\n", count_num);
    printf("���������� ��������� ����: %d\n", count_uc);
    printf("���������� �������� ����: %d \n \n", count_lc);

    // Task 2 //

    printf("������� 2: \n \n");
    int minute, payment, over; // ���������� ����. �����, ���� ���. ������, ���� ���. ����� ������

    printf("������� ��������� ��������� ������ (499 ����� ���������): ");
    scanf("%d", &payment);
    printf("\n");

    printf("������� ���������� ����������� �����: ");
    scanf("%d", &minute);
    printf("\n");

    printf("������� ��������� ������ ����� ����������, ����������� � �����: ");
    scanf("%d", &over);
    printf("\n \n");

    int payment_over = payment + (minute - 499) * over;

    if (minute <= 499) printf("��������� ������: %d ���.", payment);
    else if (minute < 0) printf ("������� ���������� ��������!");
    else if (minute > 499) printf("��������� ������: %d ���.", payment_over);
    return 0;
}

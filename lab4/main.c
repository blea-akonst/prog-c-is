#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Ru");

    int a;
    int first = 1;
    int last = 10; // ������ ����������, ���������� ��������� ����������
    printf("������� �����: ");
    scanf("%d", &a);
    printf("���������� ��������� �������� ������ ����� �� ��������� � �������� [1;10] (����/������): ");
    printf("%d\n", a>= first && a <= last);

    int b;
    printf("������� �����:");
    scanf("%d", &b);
    printf("��������� ��������: ");
    printf("%d", b % 2);
    return 0;
} // ������� 1, �. �. 4
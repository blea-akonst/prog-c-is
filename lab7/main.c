#include <stdio.h>
#include <locale.h>

enum Days
{
    Monday, Tuesday, Wednesday,
    Thursday, Friday, Saturday,
    Sunday
};

struct rectangle {
    int width, length;
};

union Player
{
    int value;
    struct
    {
        unsigned char Play : 1;
        unsigned char Stop : 1;
        unsigned char Record : 1;
    };
};

int main() {
    setlocale(LC_ALL, "Ru");

    printf("������� 1:\n");
    enum Days s = Monday;
    printf("%d\n", s);
    printf("\n");


    printf("������� 2:\n");

    struct rectangle rect;

    printf("������� ����� ��������������: ");
    scanf("%d", &rect.length);
    printf("������� ������ ��������������: ");
    scanf("%d", &rect.width);
    int square = rect.length * rect.width;
    printf("������� ��������������: ");
    printf("%d\n", square);

    printf("������� 3:\n");
    union Player pl;
    printf("������� ����� � ����������������� ������� ���������: ");
    scanf("%x", &pl.value);
    printf("���������������: %s\ || �����: %s\ || ������: %s \n",
           pl.Play ? "���" : "����",
           pl.Stop ? "���" : "����",
           pl.Record ? "���" : "����");
    return 0;
}
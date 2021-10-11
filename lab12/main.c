#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* settime(struct tm* u)
{
    char s[40];
    char* tmp;
    for (int i = 0; i < 40; i++)
    {
        s[i] = 0;
    }
    strftime(s, 40, "%d.%m.%Y %H:%M:%S, %A", u);
    tmp = (char*)malloc(sizeof(s));
    strcpy(tmp, s);
    return(tmp);
}
int main(int argc, char *argv[]) {
    struct tm* u;
    char* f;
    const time_t timer = time(NULL); // таймер сегодняшней даты (прошедшие секунды с 1 января 1970 года)

    char* dates[10]; // массив дат

    u = localtime(&timer); // преобразует календарное время в структуру tm
    f = settime(u); // возвращает дату в виде строки
    dates[0] = f;

    for (int i = 1; i < 10; i++)
    {
        u->tm_mday += 1;
        time_t next = mktime(u);

        u = localtime(&next);
        f = settime(u);
        dates[i] = f;
    }

    FILE* out = fopen(_argv[1], "w+"); // Открытие файла на запись и обновление

    for (int i = 0; i < 10; i++)
    {
        fprintf(out, dates[i]);
        fprintf(out, "\n");
    }

    fclose(out);

    return 0;
}
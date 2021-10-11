#include <stdio.h>
#include <locale.h>

#include "arch.h"

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Rus");

    char *arch_name = argv[2];

    switch (argv[3][2]) {
        case 'c':
            create(arch_name, argc, argv);
            break;
        case 'e':
            extract(arch_name);
            remove(arch_name);
            break;
        case 'l':
            printf("Файлы, хранящиеся в архиве %s:\n", arch_name);
            list(arch_name);
            break;
        default:
            puts("Была получена некорректная команда!");
            break;
    }


    return 0;
}
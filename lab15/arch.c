#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "arch.h"

void copy_file(FILE *from, FILE *to) {
    int c;
    while ((c = getc(from)) != EOF) {
        putc(c, to);
    }
}

unsigned int get_file_size(char *file_name) {
    FILE *file = fopen(file_name, "rb");
    fseek(file, 0, SEEK_END);
    unsigned int file_size = ftell(file);
    fclose(file);
    return file_size;
}

void create(char *arch_name, int argc, char *argv[]) {
    FILE *arch_file = fopen(arch_name, "wb");

    union archive_header arc_header;
    arc_header.arch_data.archive_type[0] = 'F';
    arc_header.arch_data.archive_type[1] = 'A';
    arc_header.arch_data.archive_type[2] = 'R';
    arc_header.arch_data.archive_type[3] = 'C';
    arc_header.arch_data.archive_size = 8;
    for (int i = 4; i < argc; i++) {
        arc_header.arch_data.archive_size += get_file_size(argv[i]) + 8 + strlen(argv[i]);
    }
    fwrite(arc_header.buffer, sizeof(char), 8, arch_file);

    for (int i = 4; i < argc; i++) {
        union file_header file_header;

        file_header.file_data.file_size = get_file_size(argv[i]);
        file_header.file_data.header_size = 8 + strlen(argv[i]);
        fwrite(file_header.buffer, sizeof(char), 8, arch_file);
        fwrite(argv[i], sizeof(char), strlen(argv[i]), arch_file);

        FILE *file;
        file = fopen(argv[i], "rb");

        copy_file(file, arch_file);

        fclose(file);
    }
    fclose(arch_file);
}

void list(char *arch_name) {
    FILE *arch_file = fopen(arch_name, "rb");

    union archive_header arc_header;
    fread(arc_header.buffer, sizeof(char), 8, arch_file);

    while (ftell(arch_file) < arc_header.arch_data.archive_size) {
        union file_header file_header;
        fread(file_header.buffer, sizeof(char), 8, arch_file);

        char *file_name = malloc((file_header.file_data.header_size - 8) * sizeof(char));
        fread(file_name, sizeof(char), file_header.file_data.header_size - 8, arch_file);

        printf("%s\n", file_name);
        fseek(arch_file, file_header.file_data.file_size, SEEK_CUR);
        free(file_name);
    }

    fclose(arch_file);
}

void extract(char *arch_name) {
    FILE *arch_file = fopen(arch_name, "rb");

    union archive_header arc_header;
    fread(arc_header.buffer, sizeof(char), 8, arch_file);

    while (ftell(arch_file) < arc_header.arch_data.archive_size) {
        union file_header file_header;
        fread(file_header.buffer, sizeof(char), 8, arch_file);

        char *file_name = malloc((file_header.file_data.header_size - 8) * sizeof(char));
        fread(file_name, sizeof(char), file_header.file_data.header_size - 8, arch_file);

        FILE *output_file = fopen(file_name, "wb");

        for (unsigned int i = 0; i < file_header.file_data.file_size; i++) {
            int c = getc(arch_file);
            putc(c, output_file);
        }

        fclose(output_file);
        free(file_name);
    }
    fclose(arch_file);
}
#ifndef LAB15_ARCH_H
#define LAB15_ARCH_H

union archive_header {
    char buffer[8];

    struct {
        char archive_type[4];
        unsigned int archive_size;
    } arch_data;
};

union file_header {
    char buffer[8];

    struct {
        unsigned int header_size;
        unsigned int file_size;
    } file_data;
};

void copy_file(FILE*, FILE*);

unsigned int get_file_size(char*);

void create(char*, int, char *[]);

void list(char*);

void extract(char*);

#endif //LAB15_ARCH_H

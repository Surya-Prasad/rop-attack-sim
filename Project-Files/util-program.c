// util-program.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util-program.h"

void initialize_buffer(char* buf, int size) {
    memset(buf, 0, size);
}

void read_from_file(const char* filename, char** str) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    *str = (char*)malloc(size + 1);
    fread(*str, 1, size, fp);
    (*str)[size] = '\0';

    fclose(fp);
}

void write_to_file(const char* filename, char* buf, int len, int mode) {
    FILE *fp;
    if (mode == FILE_CLEAR) {
        fp = fopen(filename, "wb");
    } else {
        fp = fopen(filename, "ab");
    }

    if (!fp) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    fwrite(buf, 1, len, fp);
    fclose(fp);
}
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

ssize_t ma_getline(char **lineptr, size_t *n, FILE *stream);

char **ma_strngtokenizer(const char *strng, char d);

#endif

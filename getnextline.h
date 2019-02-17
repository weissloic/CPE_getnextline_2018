/*
** EPITECH PROJECT, 2018
** 103cypher
** File description:
** description
*/


#include <time.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <math.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef READ_SIZE
#define READ_SIZE 80
#define LINE return (line = copy_line(line, m->line_change, buffer, &begin))
#define DEF_LINE line = copy_line(line, m->line_change + 1, buffer, &begin)
#define COPY_TWO my_strncpy(m->newlen, "", m->i)
#define COPY_ONE my_strncpy(m->newlen, line, m->i)

typedef struct func_char_t {
    char *newlen;
    int i;
    char *line;
    char *test;
    int line_change;
} func_char_t;

void my_putstr(char *str);
int my_strlen(char *str);
char *my_strncpy(char *dest, const char *src, int size);
static char *copy_line(char *line, int treat, char *buff, int *count);
char *get_next_line(int fd);

#endif /*READ_SIZE*/
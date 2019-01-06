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
#define READ_SIZE (9)

typedef struct func_char_t {
    char *new_str;
    int i;
    char *line;
    char my_char;
    int j;
    char my_next;
    int k;
} func_char_t;

char *get_next_line(int fd);
char fill_my_buf(int fd);
char *my_realloc(char *str);
char *my_norm(int i, func_char_t *struct_next);
int my_strlen(char *str);


#endif /*READ_SIZE*/
/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** GNL
*/

#include "getnextline.h"

static char *copy_line(char *line, int treat, char *buff, int *count)
{
    func_char_t *m = malloc(sizeof(func_char_t));
    m->newlen = malloc(sizeof(char) * 10000);
    m->i = (line != NULL) ? my_strlen(line) : 0;
    m->test = (line != 0) ? COPY_ONE : COPY_TWO;
    m->newlen[m->i + treat] = 0;
    my_strncpy(m->newlen + m->i, buff + *count, treat);
    *count = *count + (treat + 1);
    return (m->newlen);
}

char *get_next_line(int fd)
{
    func_char_t *m = malloc(sizeof(func_char_t));
    static char buffer[READ_SIZE];
    static int buflen = 0;
    m->line_change = 0;
    char *line = NULL;
    static int begin = 0;
    while (1) {
        if (buflen <= begin) {
            begin = 0;
            switch (buflen){
                case (-1):
                    return (NULL);
            }
            if ((buflen = read(fd, buffer, READ_SIZE)) == NULL) return (line);
            m->line_change = 0;
        }
        if (buffer[begin + m->line_change] == '\n') LINE;
        if (begin + m->line_change == buflen - 1) DEF_LINE;
        m->line_change = m->line_change + 1;
    }
}

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(1, &str, my_strlen(str));
        i++;
    }
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

char *my_strncpy(char *dest, const char *src, int size) {

    int idx = 0;
    for (; idx < size && src[idx] != '\0'; idx++)
        dest[idx] = src[idx];

    for (; idx < size; idx++)
        dest[idx] = '\0';

    return (dest);
}
/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** [file description here]
*/

#include "getnextline.h"

char *my_norm(int i, func_char_t *struct_next)
{
    struct_next->line[i] = '\0';
    if (struct_next->line[0] == '\0') {
        return (0);
    } else
        return (struct_next->line);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i = i + 1;
    return (i);
}

char *my_realloc(char *str)
{
    int i = 0;
    char *new_str;

    if (!(new_str = malloc(sizeof(*new_str) * (my_strlen(str) + READ_SIZE))))
        return (0);
    while (str[i] != '\0') {
        new_str[i] = str[i];
        i = i + 1;
    }
    return (new_str);
}

char fill_my_buf(int fd)
{
    func_char_t *struct_next = malloc(sizeof(struct_next));

    static int  counter = 0;
    static char buf[READ_SIZE];
    static int  size_read = 0;

    if (size_read == 0) {
        if (!(size_read = read(fd, buf, READ_SIZE)))
            return ('\0');
        counter = 0;
    }
    struct_next->my_next = buf[counter];
    size_read--;
    counter++;
    return (struct_next->my_next);
}

char *get_next_line(int fd)
{
    func_char_t *struct_next = malloc(sizeof(struct_next));
    int i = 0;

    if (fd == -1)
        return (84);
    if (!(struct_next->line = malloc(sizeof(struct_next->line) *
        (READ_SIZE + 1))))
        return (0);
    struct_next->my_char = fill_my_buf(fd);
    for (;struct_next->my_char != '\0';) {
        struct_next->line[i] = struct_next->my_char;
        struct_next->my_char = fill_my_buf(fd);
        i++;
        if (!(struct_next->line = my_realloc(struct_next->line)))
            return (0);
    }
    my_norm(i, struct_next);
}
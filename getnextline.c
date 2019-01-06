/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "getnextline.h"


/*char    get_next_char(const int fd)
{
    func_char_t *struct_next;
    struct_next = malloc(sizeof(struct_next));

    static int  i = 0;
    static char buffer[READ_SIZE];
    static int  size = 0;


    if (size == 0) {
        if ((size = read(fd, buffer, READ_SIZE)) == 0)
            return ('\0');
        i = 0;
    }
    struct_next->my_next = buffer[i];
    size--;
    i++;
    return (struct_next->my_next);
}*/

char *my_norm(int i, func_char_t *struct_next)
{
    struct_next->line[i] = '\0';
    if (struct_next->line[0] == '\0')
        free(struct_next->line);
    else
        return(struct_next->line);
}

int my_strlen(char *str)
{
    int   i;

    i = 0;
    while (str[i] != '\0')
    i = i + 1;
    return (i);
}


char    *my_realloc(char *save)
{
  int   i;
  char  *new;

  i = 0;
  if (!(new = malloc(sizeof(*new) * (my_strlen(save) + READ_SIZE))))
    return (NULL);
  while (save[i] != '\0')
    {
      new[i] = save[i];
      i = i + 1;
    }
  return (new);
}

/*char  *get_next_line(int fd)
{
  func_char_t *struct_next;
  struct_next = malloc(sizeof(struct_next));
  int k;

  if ((struct_next->line = malloc(sizeof(struct_next->line) * (READ_SIZE + 1))) == NULL)
    return (84);
  struct_next->line[0] = '\0';
  struct_next->my_char = get_next_char(fd);
  k = 0;
  while (struct_next->my_char != '\0' ) {
      struct_next->line[k] = struct_next->my_char;
      struct_next->my_char = get_next_char(fd);
      k++;
      if (k % (READ_SIZE) == 0) {
        struct_next->line[k] = '\0';
        if ((struct_next->line = my_realloc(struct_next->line)) == 0)
          return (0);
      }
  }
  my_norm(k, struct_next);
}
*/

int main(void)
{
    char *str = NULL;
    int fd = open("map1.txt", O_RDONLY);
    //func_char_t *struct_next;

   while  (str = get_next_line(fd))

    printf("%s\n", str);
 // printf("%d\n", struct_next->size);
}
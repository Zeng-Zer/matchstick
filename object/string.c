/*
** string.c for OOC in /home/zeng_d/test/ooc
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Feb  3 21:39:31 2016 David Zeng
** Last update Wed Feb  3 23:08:30 2016 David Zeng
*/

#include "string.h"

static void	destroy(t_string *this)
{
  free(this->str);
  free(this);
}

static int	my_len(const t_string *this)
{
  return (my_strlen(this->str));
}

static void	my_cat(t_string *this, void *str)
{
  char		*tmp;

  tmp = my_realloc(this->str, my_strlen(str) + 1);
  this->str = tmp;
  my_strcat(this->str, str);
}

static void	my_put(const t_string *this)
{
  my_putstr(this->str);
}

t_string	*new_string(char *str)
{
  t_string	*ptr;

  if ((ptr = malloc(sizeof(t_string))) == NULL)
    return (NULL);
  if ((ptr->str = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  ptr->str = my_strcpy(ptr->str, str);
  ptr->len = &my_len;
  ptr->cat = &my_cat;
  ptr->put = &my_put;
  ptr->destroy = &destroy;
  return (ptr);
}

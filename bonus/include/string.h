/*
** string.h for OOC in /home/zeng_d/test/ooc
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Feb  3 21:40:01 2016 David Zeng
** Last update Wed Feb  3 23:09:43 2016 David Zeng
*/

#include <stdlib.h>
#include "my.h"

#ifndef STRING_H
# define STRING_H

typedef struct s_string t_string;

struct		s_string
{
  char		*str;
  int		(*len)(const t_string *this);
  void		(*cat)(t_string *this, void *str);
  void		(*put)(const t_string *this);
  void		(*destroy)(t_string *this);
};

t_string	*new_string(char *str);

#endif	/* !STRING_H */

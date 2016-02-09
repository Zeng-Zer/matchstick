/*
** allum.h for allum1 in /home/zeng_d/rendu/Info/gfx_tekgui
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Feb  8 14:48:08 2016 David Zeng
** Last update Mon Feb  8 23:20:14 2016 David Zeng
*/

#ifndef ALLUM_H
# define ALLUM_H

typedef struct s_allum	t_allum;

struct			s_allum
{
  unsigned int		row;
  unsigned int		col;
  unsigned int		*nb_allum;
  void			(*show_allum)(t_allum *this);
  void			(*take_allum)(t_allum *this, int allum, int row);
  void			(*dest_allum)(t_allum *this);
};

t_allum			*new_allum(unsigned int nb_row);

#endif	/* !ALLUM_H */

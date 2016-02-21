/*
** allum.c for allum1 in /home/zeng_d/rendu/Info/gfx_tekgui
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Feb  8 15:53:29 2016 David Zeng
** Last update Sun Feb 21 19:25:52 2016 David Zeng
*/

#include "my_fonction.h"

static void	my_center(t_allum *this, int pos, unsigned int nb_allum)
{
  int		space;
  int		taille_col;

  space = this->col / 2 - pos;
  taille_col = this->col - space - nb_allum - 1;
  my_putchar('*');
  while (space > 1)
    {
      my_putchar(' ');
      space = space - 1;
    }
  while (nb_allum > 0)
    {
      my_putchar('|');
      nb_allum -= 1;
    }
  while (taille_col > 0)
    {
      my_putchar(' ');
      taille_col -= 1;
    }
  my_putstr("*\n");
}

static void	my_show_allum(t_allum *this)
{
  unsigned int	i;
  unsigned int	j;

  i = 0;
  j = -1;
  while (++j < this->col)
    my_putchar('*');
  my_putchar('\n');
  while (i < this->row)
    {
      my_center(this, i, this->nb_allum[i]);
      i = i + 1;
    }
  j = -1;
  while (++j < this->col)
    my_putchar('*');
  my_putstr("\n");
}

static void	my_take_allum(t_allum *this, int allum, int row)
{
  this->nb_allum[row - 1] -= allum;
}

static void	my_dest_allum(t_allum *this)
{
  free(this->nb_allum);
  free(this);
}

t_allum		*new_allum(unsigned int nb_row)
{
  t_allum	*new;
  unsigned int	i;
  int		len;

  i = 0;
  len = 1;
  if ((new = malloc(sizeof(t_allum))) == NULL)
    return (NULL);
  if ((new->nb_allum = malloc(sizeof(int) * nb_row)) == NULL)
    return (NULL);
  new->row = nb_row;
  while (i < nb_row)
    {
      new->nb_allum[i] = len;
      len = len + 2;
      i = i + 1;
    }
  new->col = len;
  new->end = 0;
  new->show_allum = &my_show_allum;
  new->take_allum = &my_take_allum;
  new->dest_allum = &my_dest_allum;
  return (new);
}

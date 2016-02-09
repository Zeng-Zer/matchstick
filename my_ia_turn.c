/*
** my_ia_turn.c for allum in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Feb  9 03:30:44 2016 David Zeng
** Last update Tue Feb  9 04:43:12 2016 David Zeng
*/

#include "my_fonction.h"

void		ai_turn(t_allum *allumette)
{
  int		tab[allumette->row][2];
  int		i;
  int		j;
  int		tmp;
  int		allum;

  j = 0;
  i = 0;
  while (i < (int)allumette->row)
    {
      if (allumette->nb_allum[i] > 0)
	{
	  tab[j][0] = i;
	  tab[j][1] = allumette->nb_allum[i];
	  j = j + 1;
	}
      i = i + 1;
    }
  tmp = rand() % j;
  if (tab[tmp][1] - 1 == 0)
    allum = 1;
  else
    allum = 1 + rand() % (tab[tmp][1] - 1);
  allumette->take_allum(allumette, allum, tab[tmp][0] + 1);
  my_printf("AI removed %d match(es) from line %d\n", allum, tab[tmp][0] + 1);
}

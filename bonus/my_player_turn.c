/*
** my_player_turn.c for allum1 in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Feb  9 01:34:39 2016 David Zeng
** Last update Tue Feb  9 04:44:33 2016 David Zeng
*/

#include "my_fonction.h"

int		my_check_allum(t_allum *allumette, int row)
{
  char		*tmp;
  int		allum;

  my_printf("Matches: ");
  if ((tmp = get_next_line(0)) == NULL)
    return (-1);
  if ((allum = my_getnbr_err(tmp)) < 0)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      free(tmp);
      player_turn(allumette);
      return (-1);
    }
  else if (allum == 0 || allum > (int)allumette->nb_allum[row - 1])
    {
      if (allum == 0)
	my_printf("Error: you have to remove at least one match\n");
      else if (allum > (int)allumette->nb_allum[row - 1])
	my_printf("Error: not enough matches on this line\n");
      free(tmp);
      player_turn(allumette);
      return (-1);
    }
  free(tmp);
  return (allum);
}

int		my_check_row(t_allum *allumette)
{
  char		*tmp;
  int		row;

  my_printf("Line: ");
  if ((tmp = get_next_line(0)) == NULL)
    return (-1);
  if ((row = my_getnbr_err(tmp)) < 0)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      free(tmp);
      player_turn(allumette);
      return (-1);
    }
  else if (row == 0 || row > (int)allumette->row)
    {
      my_printf("Error: this line is out of range\n");
      free(tmp);
      player_turn(allumette);
      return (-1);
    }
  free(tmp);
  return (row);
}

void		player_turn(t_allum *allumette)
{
  int		allum;
  int		row;

  if ((row = my_check_row(allumette)) == -1)
    return;
  if ((allum = my_check_allum(allumette, row)) == -1)
    return;
  allumette->take_allum(allumette, allum, row);
  my_printf("Player removed %d match(es) from line %d\n", allum, row);
}

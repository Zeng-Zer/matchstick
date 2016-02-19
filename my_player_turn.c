/*
** my_player_turn.c for allum1 in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Feb  9 01:34:39 2016 David Zeng
** Last update Sat Feb 20 00:10:14 2016 David Zeng
*/

#include "my_fonction.h"

void		my_do_error(t_allum *allumette, char *tmp)
{
  free(tmp);
  player_turn(allumette);
}

int		my_match_error(t_allum *allumette, char *tmp)
{
  my_printf("\nError: invalid input (positive number expected)\n");
  my_do_error(allumette, tmp);
  return (-1);
}

int		my_check_allum(t_allum *allumette, int row)
{
  char		*tmp;
  int		allum;

  my_printf("Matches: ");
  if ((tmp = get_next_line(0)) == NULL)
    return (my_match_error(allumette, tmp));
  if (my_strcmp(tmp, "") == 0 || (allum = my_getnbr_err(tmp)) < 0)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      my_do_error(allumette, tmp);
      return (-1);
    }
  else if (allum == 0 || allum > (int)allumette->nb_allum[row - 1])
    {
      if (allum == 0)
	my_printf("Error: you have to remove at least one match\n");
      else if (allum > (int)allumette->nb_allum[row - 1])
	my_printf("Error: not enough matches on this line\n");
      my_do_error(allumette, tmp);
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
    {
      my_printf("\nError: invalid input (positive number expected)\n");
      my_do_error(allumette, tmp);
      return (-1);
    }
  if (my_strcmp(tmp, "") == 0 || (row = my_getnbr_err(tmp)) < 0)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      my_do_error(allumette, tmp);
      return (-1);
    }
  else if (row == 0 || row > (int)allumette->row)
    {
      my_printf("Error: this line is out of range\n");
      my_do_error(allumette, tmp);
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
  if (allumette->nb_allum[row - 1] == 0)
    {
      my_printf("Error: this line is empty\n");
      player_turn(allumette);
      return;
    }
  if ((allum = my_check_allum(allumette, row)) == -1)
    return;
  allumette->take_allum(allumette, allum, row);
  my_printf("Player removed %d match(es) from line %d\n", allum, row);
}

/*
** main.c for main in /home/zeng_d/usefull
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Dec 14 14:07:51 2015 David Zeng
** Last update Fri Mar 18 14:14:48 2016 David Zeng
*/

#include <time.h>
#include "my_fonction.h"

int		main(int argc, char **argv)
{
  t_allum	*allumette;
  int		nb_row;

  if (argc != 2)
    {
      my_printf("USAGE: %s [ROW]\n", argv[0]);
      return (1);
    }
  if ((nb_row = my_getnbr_err(argv[1])) == -1)
    {
      my_printf("Row has to be a positive number\n");
      return (1);
    }
  if ((allumette = new_allum(nb_row)) == NULL)
    return (1);
  srand(time(NULL));
  allumette->show_allum(allumette);
  my_putchar('\n');
  my_loop(allumette);
  allumette->dest_allum(allumette);
  return (0);
}

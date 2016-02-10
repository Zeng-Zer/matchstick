/*
** main.c for main in /home/zeng_d/usefull
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Dec 14 14:07:51 2015 David Zeng
** Last update Wed Feb 10 15:33:01 2016 David Zeng
*/

#include "my_fonction.h"
#include <time.h>

int		main(int argc, char **argv)
{
  t_allum	*allumette;

  if (argc != 2)
    {
      my_printf("USAGE: %s [ROW]\n", argv[0]);
      return (1);
    }
  if ((allumette = new_allum(my_getnbr_err(argv[1]))) == NULL)
    return (1);
  srand(time(NULL));
  allumette->show_allum(allumette);
  my_putchar('\n');
  my_loop(allumette);
  allumette->dest_allum(allumette);
  return (0);
}

/*
** main.c for main in /home/zeng_d/usefull
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Dec 14 14:07:51 2015 David Zeng
** Last update Fri Mar 18 14:03:40 2016 David Zeng
*/

#include <time.h>
#include "my_fonction.h"

int		main()
{
  t_allum	*allumette;

  if ((allumette = new_allum(4)) == NULL)
    return (1);
  srand(time(NULL));
  allumette->show_allum(allumette);
  my_putchar('\n');
  my_loop(allumette);
  allumette->dest_allum(allumette);
  return (0);
}

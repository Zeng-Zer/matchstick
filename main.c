/*
** main.c for main in /home/zeng_d/usefull
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Dec 14 14:07:51 2015 David Zeng
** Last update Tue Feb  9 02:26:52 2016 David Zeng
*/

#include "my_fonction.h"

int		main()
{
  t_allum	*allumette;

  if ((allumette = new_allum(4)) == NULL)
    return (1);
  allumette->show_allum(allumette);
  my_putchar('\n');
  my_loop(allumette);
  allumette->dest_allum(allumette);
  return (0);
}

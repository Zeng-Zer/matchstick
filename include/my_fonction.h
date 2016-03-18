/*
** my_fonction.h for my_fonction in /home/zeng_d/rendu/Unix/PSU_2015_my_popup
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Nov 30 15:49:28 2015 David Zeng
** Last update Fri Mar 18 14:09:52 2016 David Zeng
*/

#ifndef MY_FONCTION_H_
# define MY_FONCTION_H_

# include <stdlib.h>
# include "my.h"
# include "allum.h"

# define YOU 0
# define IA 1

void		my_loop(t_allum *allumette);
int		player_turn(t_allum *allumette);
void		ai_turn(t_allum *allumette);

#endif /* !MY_FONCTION_H_ */

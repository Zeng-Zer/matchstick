/*
** my_fonction.h for my_fonction in /home/zeng_d/rendu/Unix/PSU_2015_my_popup
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Nov 30 15:49:28 2015 David Zeng
** Last update Tue Feb  9 03:31:44 2016 David Zeng
*/

#include "my.h"
#include "object.h"

#ifndef MY_FONCTION_H_
# define MY_FONCTION_H_

# define YOU 0
# define IA 1

void		my_loop(t_allum *allumette);
void		player_turn(t_allum *allumette);
void		ai_turn(t_allum *allumette);

#endif /* !MY_FONCTION_H_ */

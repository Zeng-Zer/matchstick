/*
** disp_stdarg.c for disp in /home/zeng_d/rendu/Unix/PSU_2015_my_printf
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Nov  5 11:58:05 2015 David Zeng
** Last update Sun Dec 27 17:02:41 2015 David Zeng
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

char	*my_do_str()
{
  char	*str;

  str = malloc(sizeof(char) * 14);
  str[0] = 'c';
  str[1] = 's';
  str[2] = 'i';
  str[3] = 'd';
  str[4] = 'u';
  str[5] = 'o';
  str[6] = 'x';
  str[7] = 'X';
  str[8] = '%';
  str[9] = 'b';
  str[10] = 'S';
  str[11] = 'p';
  str[12] = 'C';
  str[13] = '\0';
  return (str);
}

void	do_per(char c, va_list list, int *n, int i)
{
  t_cas	cas[13];
  char	*str;

  str = my_do_str();
  cas[0] = &my_printc;
  cas[1] = &my_prints;
  cas[2] = &my_printi;
  cas[3] = &my_printi;
  cas[4] = &my_printu;
  cas[5] = &my_printo;
  cas[6] = &my_printx;
  cas[7] = &my_printX;
  cas[8] = &my_printper;
  cas[9] = &my_printb;
  cas[10] = &my_printS;
  cas[11] = &my_printp;
  cas[12] = &my_printc;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	cas[i](list, n);
      i = i + 1;
    }
  free(str);
}

int	disp_stdarg(const char *str, int *i,  va_list list, int *n)
{
  int	j;
  char	*string;

  j = 0;
  string = my_do_str();
  while (string[j] != str[*i] && string[j] != '\0')
    j = j + 1;
  if (str[*i] == '\0' || string[j] == '\0')
    {
      free(string);
      my_putchar('%');
      *n = *n + 1;
      return (0);
    }
  free(string);
  do_per((char)str[*i], list, n, 0);
  *i = *i + 1;
  return (0);
}

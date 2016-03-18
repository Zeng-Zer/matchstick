/*
** my_bistro.h for bistromatic
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Oct  8 14:34:15 2015 David Zeng
** Last update Fri Mar 18 14:05:00 2016 David Zeng
*/

#ifndef MY_H_
# define MY_H_

#include <stdarg.h>

/* MY_H */

#ifndef READ_SIZE
# define READ_SIZE (1024)
#endif /* !READ_SIZE */

void	my_putchar(char c);
int	my_put_nbr(int nb);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
int	my_getnbr_err(char *str);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	my_putnbr_base(int nbr, char *base);
char	*my_strdup(char *src);
void	my_show_tab(char **tab);
void	my_free_tab(char **tab);
void	my_put_err(char *str);
char	*my_strndup(char *str, int nb);
int	my_tablen(char **tab);
char	*get_next_line(const int fd);
char	*my_realloc(char *pointer, unsigned int size);

/* MY_PRINTF */

typedef int	(*t_cas)(va_list, int*);

int	my_printf(const char *format, ...);
int	my_printi(va_list list, int *n);
int	my_prints(va_list list, int *n);
int	my_printc(va_list list, int *n);
int	my_printx(va_list list, int *n);
int	my_printX(va_list list, int *n);
int	my_printo(va_list list, int *n);
void	my_put_nbr_base(unsigned int nb, char *base);
int	my_printper(va_list list, int *n);
int	my_printu(va_list list, int *n);
int	my_printb(va_list list, int *n);
void	my_putunsigned(unsigned int nb);
int	my_get_oct(unsigned char nb);
void	my_put_S(unsigned char c, int *n);
int	my_printS(va_list list, int *n);
int	my_printp(va_list list, int *n);
void	my_put_16(unsigned long int nb, char *base);
int	disp_stdarg(const char *format, int *i, va_list list, int *n);

#endif /* !MY_H_ */

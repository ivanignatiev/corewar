/*
** strings.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/lib
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Thu Dec  6 18:11:23 2012 arthur sfez
** Last update Thu Dec  6 20:08:38 2012 arthur sfez
*/

#include <unistd.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_strlen(char *s)
{
  int		i;

  i = 0;
  if (!s)
    return (0);
  while (s[i])
    i++;
  return (i);
}

void		my_putstr(char *s)
{
  write(1, s, my_strlen(s));
}

void		my_puterr(char *s)
{
  write(2, s, my_strlen(s));
}

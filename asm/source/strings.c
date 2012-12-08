/*
** strings.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Sat Dec  8 18:46:52 2012 arthur sfez
** Last update Sat Dec  8 18:52:00 2012 arthur sfez
*/

#include	<unistd.h>
#include	<stdlib.h>

char		*my_malloc_separators()
{
  char		*s;

  s = malloc(sizeof(*s) * (4));
  if (s == NULL)
    return (NULL);
  s[0] = ',';
  s[1] = ' ';
  s[2] = '\t';
  s[3] = 0;
  return (s);
}

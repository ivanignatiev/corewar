/*
** my_strdups.c for strdups in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/lib
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Fri Dec 14 09:45:40 2012 arthur sfez
** Last update Fri Dec 14 09:58:49 2012 arthur sfez
*/

#include	<stdlib.h>
#include	"cwlib.h"

char		*my_strndup(char *s, int n)
{
  char		*r;
  int		size;
  int		i;

  i = 0;
  if (n > my_strlen(s))
    size = my_strlen(s);
  else
    size = n;
  r = malloc(sizeof(*r) * (size + 1));
  if (r == NULL)
    return (NULL);
  while (i < size)
    {
      r[i] = s[i];
      i++;
    }
  r[size] = '\0';
  return (r);
}

char		*my_strdup(char *s)
{
  char		*r;
  int		size;
  int		i;

  i = 0;
  size = my_strlen(s);
  r = malloc(sizeof(*r) * (size + 1));
  if (r == NULL)
    return (NULL);
  while (i < size)
    {
      r[i] = s[i];
      i++;
    }
  r[size] = '\0';
  return (r);
}

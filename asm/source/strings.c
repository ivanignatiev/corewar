/*
** strings.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Sat Dec  8 18:46:52 2012 arthur sfez
** Last update Wed Dec 12 15:42:49 2012 arthur sfez
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"asm.h"
#include	"op.h"

char		*my_malloc_separators()
{
  char		*s;

  s = malloc(sizeof(*s) * (4));
  if (s == NULL)
    return (NULL);
  s[0] = SEPARATOR_CHAR;
  s[1] = ' ';
  s[2] = '\t';
  s[3] = 0;
  return (s);
}

char		*my_remove_separators(char *s, char *tmp, char *separators)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (tmp[i])
    {
      if (!is_it_separator_asm(tmp[i], separators))
	{
	  s[j] = tmp[i];
	  j++;
	}
      i++;
    }
  free(tmp);
  separators[1] = 0;
  return (s);
}

char		*my_clean_string(char *s, char *separators)
{
  int		i;
  int		sp;
  char		*tmp;

  i = 0;
  sp = 0;
  separators[1] = ' ';
  while (s[i])
    {
      if (is_it_separator_asm(s[i], separators))
	sp++;
      i++;
    }
  if (sp > 0)
    {
      tmp = s;
      s = malloc(sizeof(*s) * (my_strlen(tmp) - sp + 1));
      if (s == NULL)
	s = tmp;
      s[my_strlen(tmp) - sp] = 0;
      return (my_remove_separators(s, tmp, separators));

    }
  separators[1] = 0;
  return (s);
}

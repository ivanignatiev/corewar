/*
** err_fcts.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Fri Dec 14 17:57:25 2012 arthur sfez
** Last update Sun Dec 16 15:26:36 2012 arthur sfez
*/

#include	<unistd.h>
#include	"asm.h"

int		my_get_line_pos(char *s, int i)
{
  int		j;
  int		cpt;
  int		in_word;
  int		res;

  cpt = -1;
  j = 0;
  in_word = 0;
  res = 0;
  while (s[j])
    {
      if (is_it_separator_asm(s[j], "\t"))
	res += 4;
      if (!is_it_separator_asm(s[j], " ,\t") && in_word == 0)
	{
	  in_word = 1;
	  cpt++;
	  if (cpt == i)
	    return (j + res);
	}
      else if (in_word == 1 && is_it_separator_asm(s[j], " ,\t"))
	in_word = 0;
      j++;
    }
  return (1);
}

void		special_puterr(char *s)
{
  while (*s)
    {
      if (*s == '\t')
	write(2, "     ", 5);
      else
	write(2, s, 1);
      s++;
    }
}

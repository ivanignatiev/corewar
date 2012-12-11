/*
** is_label_def.c for corewar in /home/lu_a//test/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by angela lu
** Login   <lu_a@epitech.net>
** 
** Started on  Mon Dec 10 17:17:55 2012 angela lu
** Last update Tue Dec 11 16:33:54 2012 arthur sfez
*/

#include	<stdlib.h>
#include	"op.h"
#include	"asm.h"
#include	"cwlib.h"

static int	check_lab_chars(char c)
{
  int		sig;
  int		n;

  sig = 0;
  n = 0;
  while (LABEL_CHARS[n] && sig == 0)
    {
      if (c != LABEL_CHARS[n])
	n = n + 1;
      else
	sig = 1;
    }
  return (n);
}

int		is_label_def(char *str, char *s, int i)
{
  int		j;
  int		n;
  int		sig;
  int		size;

  j = 0;
  sig = 0;
  size = my_strlen(str);
  while (j < size - 1)
    {
      if ((n = check_lab_chars(str[j])) >= my_strlen(LABEL_CHARS))
	sig = 1;
      j = j + 1;
    }
  if (str[size - 1] == ':' && size == 1)
    my_err_msg(s, MISSING_LABEL_NAME, my_get_line_pos(s, i));
  if (str[size - 1] == ':' && size != 1)
    {
      if (sig == 0)
	return (1);
      my_err_msg(s, INVALID_CHAR, my_get_line_pos(s, i));
    }
  return (0);
}

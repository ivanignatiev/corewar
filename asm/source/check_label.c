/*
** is_label_def.c for corewar in /home/lu_a//test/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by angela lu
** Login   <lu_a@epitech.net>
** 
** Started on  Mon Dec 10 17:17:55 2012 angela lu
** Last update Thu Dec 13 11:30:41 2012 arthur sfez
*/

#include	<stdlib.h>
#include	"op.h"
#include	"asm.h"
#include	"cwlib.h"

static int	is_label_char(char c)
{
  int		i;

  i = 0;
  while (LABEL_CHARS[i] != '\0')
    {
      if (LABEL_CHARS[i] == c)
	return (1);
      i++;
    }
  return (0);
}

int		is_label_call(char *s)
{
  if (*s == LABEL_CHAR)
    {
      s++;
      while (*s != '\0')
	{
	  if (!is_label_char(*s))
	    return (-1);
	  s++;
	}
      return (1);
    }
  return (0);
}

int		is_label_def(line_t one_line, int i, int *lb_def)
{
  int		j;

  j = 0;
  if (one_line.arr[i][my_strlen(one_line.arr[i]) - 1] != LABEL_CHAR)
    return (0);
  else if (one_line.arr[i][0] == LABEL_CHAR && my_strlen(one_line.arr[i]) == 1)
    return (my_err_msg(one_line.s, MISSING_LABEL_NAME, i));
  while (one_line.arr[i][j + 1] != '\0')
    {
      if (!is_label_char(one_line.arr[i][j]))
	return (my_err_msg(one_line.s, INVALID_CHAR, i));
      j++;
    }
  *lb_def = 1;
  return (1);
}

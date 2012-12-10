/*
** is_label_def.c for corewar in /home/lu_a//test/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by angela lu
** Login   <lu_a@epitech.net>
** 
** Started on  Mon Dec 10 17:17:55 2012 angela lu
** Last update Mon Dec 10 22:04:46 2012 angela lu
*/

#include <stdlib.h>
#include "op.h"
#include "asm.h"
#include "cwlib.h"

int	check_lab_chars(char c)
{
  int	sig;
  int	n;

  sig = 0;
  n = 0;
  while(LABEL_CHARS[n] && sig == 0)
    {
      if (c != LABEL_CHARS[n])
	n = n + 1;
      else
	sig = 1;
    }
  return (n);
}

int	is_label_def(char *str, int i)
{
  int	j;
  int	n;
  int	sig;

  j = 0;
  sig = 0;
  while (j < my_strlen(str) - 1)
    {
      n = check_lab_chars(str[j]);
      if (n >= my_strlen(LABEL_CHARS))
	sig = 1;
      j = j + 1;
    }
  if(str[my_strlen(str) - 1] == ':' && my_strlen(str) == 1)
    exit(EXIT_FAILURE);
  if (str[my_strlen(str) - 1] == ':' && my_strlen(str) != 1)
      if (i == 0 && sig == 0)
	return (1);
      else
	exit(EXIT_FAILURE);
  return (0);
}

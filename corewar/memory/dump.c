/*
** dump.c for corewar in ./dasm/memory
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 11:51:59 2012 ivan ignatiev
** Last update Sat Dec 15 13:35:20 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"



int		cw_dump_memory(unsigned char *memory, unsigned int size)
{
  unsigned int	i;
  unsigned int	l;
  unsigned int	h;
  char		*myhex;

  if (memory == NULL)
    return(0);
  if ((myhex = my_strdup("0123456789ABCDEF")) != NULL)
    {
      i = 0;
      printf("%05X : ", 0);
      while (i < size)
	{
	  h = ((unsigned int)memory[i] / 16) % 16;
	  l = (unsigned int)memory[i] % 16;
	  printf("%c%c ", myhex[h], myhex[l]);
	  if (((i + 1) % 16) == 0 && (i > 0))
	    {
	      printf("\n%05X : ", i);
	    }
	  i = i + 1;
	}
      free(myhex);
      printf("\n");
    }
  return (1);
}

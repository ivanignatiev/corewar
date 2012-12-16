/*
** dump.c for corewar in ./dasm/memory
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 11:51:59 2012 ivan ignatiev
** Last update Sat Dec 15 16:06:14 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

static void	cw_print_hex(int nbr, int n, char *hex)
{
  if (n > 1)
    cw_print_hex(nbr / 16, n - 1, hex);
  my_fputchar(OSTD, hex[(nbr % 16)]);
}

int		cw_dump_memory(unsigned char *memory, unsigned int size)
{
  unsigned int	i;
  char		*myhex;

  if (memory == NULL)
    return(0);
  if ((myhex = my_strdup("0123456789ABCDEF")) == NULL)
    return (0);
  i = 0;
  cw_print_hex(0, 5, myhex);
  my_fputchar(OSTD, ':');
  while (i < size)
    {
      cw_print_hex(memory[i], 2, myhex);
      my_fputchar(OSTD, ' ');
      if (((i + 1) % 16) == 0 && (i > 0))
	{
	  my_fputchar(OSTD, '\n');
	  cw_print_hex(i, 5, myhex);
	  my_fputchar(OSTD, ':');
	}
      i = i + 1;
    }
  free(myhex);
  my_fputchar(OSTD, '\n');
  return (1);
}

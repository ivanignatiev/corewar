/*
** dump.c for corewar in ./dasm/memory
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 11:51:59 2012 ivan ignatiev
** Last update Mon Dec 10 11:52:49 2012 ivan ignatiev
*/

#include	"cwlib.h"
#include	"op.h"
#include	"dasm.h"

int		cw_dump_memory(unsigned char *memory, int size)
{
  int		i;
  char		myhex[] = "0123456789ABCDEF";

  i = 0;
  while (i < size)
    {
      printf("%c%c ", myhex[(memory[i] / 16) % 16], myhex[memory[i]  % 16]);
      if ((i + 1) % 16 == 0 && i > 0)
	printf("\n");
      i = i + 1;
    }
  printf("\n");
}

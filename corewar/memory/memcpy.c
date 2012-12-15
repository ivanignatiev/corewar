/*
** my_memcpy.c for corewar in ./corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Fri Dec 14 17:16:41 2012 ivan ignatiev
** Last update Sat Dec 15 02:56:14 2012 ivan ignatiev
*/

#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

void		*cw_tomemcpy(void *src, int n, int dest_n,
			     t_long_type start_addr)
{
  t_long_type	i;
  int		j;

  i = dest_n - 1 + start_addr;
  j = n - 1;
  while (i >= start_addr )
    {
      if (j >= 0)
	g_memory[cw_m(i)] = ((unsigned char*)src)[j];
      i = i - 1;
      j = j - 1;
    }
  return (g_memory);
}

void		*cw_frommemcpy(void *dest, int n, int dest_n,
			       t_long_type start_addr)
{
  int		i;
  t_long_type	j;

  i = dest_n - 1;
  j = n - 1 + start_addr;
  while (i >= 0 )
    {
      if (j >= start_addr)
	((unsigned char*)dest)[i] = g_memory[cw_m(j)];
      i = i - 1;
      j = j - 1;
    }
  return (dest);
}


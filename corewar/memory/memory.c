/*
** memory.h for corewar in ./dasm/memory/
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 11:46:25 2012 ivan ignatiev
** Last update Sat Dec 15 16:04:24 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

t_long_type	cw_m(t_long_type addr)
{
  if (addr < 0)
    addr = MEM_SIZE - ((-addr) % MEM_SIZE);
  else
    addr = addr % MEM_SIZE;
  return (addr);
}

int		cw_init_memory()
{
  int		i;

  g_last_live = NULL;
  g_cycle_to_dump = -1;
  g_prog_list = NULL;
  g_options = 0;
  if ((g_memory = (unsigned char*)malloc(sizeof(unsigned char)
					 * MEM_SIZE)) != NULL)
    return (1);
  i = 0;
  while (i < MEM_SIZE)
    {
      g_memory[i] = 0;
      ++i;
    }
  return (0);
}

int		cw_free_memory()
{
  if (g_prog_list != NULL)
    cw_clear_list();
  if (g_last_live != NULL)
    free(g_last_live);
  if (g_memory != NULL)
    free(g_memory);
  return (1);
}

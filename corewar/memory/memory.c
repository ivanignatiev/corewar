/*
** memory.h for corewar in ./dasm/memory/
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 11:46:25 2012 ivan ignatiev
** Last update Thu Dec 13 14:46:50 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

int		cw_init_memory()
{
  if ((g_memory = (unsigned char*)malloc(sizeof(unsigned char) * MEM_SIZE)) != NULL)
    return (1);
  return (0);
}

int		cw_free_memory()
{
  free(g_memory);
  return (1);
}

/*
** memory.h for corewar in /home/ignati_i//projects/corewar/corewar-2016ed-2015s-2017si-liu_q/dasm
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 11:46:25 2012 ivan ignatiev
** Last update Mon Dec 10 11:56:20 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"cwlib.h"
#include	"op.h"
#include	"dasm.h"

int		cw_init_memory()
{
  if ((g_memory = (char*)malloc(sizeof(char) * MEM_SIZE)) != NULL)
    return (1);
  return (0);
}

int		cw_free_memory()
{
  free(g_memory);
}

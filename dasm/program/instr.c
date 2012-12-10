/*
** intr.c for corewar in ./dasm/program
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 12:34:41 2012 ivan ignatiev
** Last update Mon Dec 10 13:33:26 2012 ivan ignatiev
*/

#include	<stdio.h>
#include	"cwlib.h"
#include	"op.h"
#include	"dasm.h"

int		cw_try_run_instr(t_program *prog)
{
  /* prog->memory_start[prog->pc] */
  
  prog->pc = prog->pc + 1;
  if (prog->pc == prog->header.prog_size)
    return (0);
  return (1);
}

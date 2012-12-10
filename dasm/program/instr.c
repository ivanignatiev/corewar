/*
** intr.c for corewar in ./dasm/program
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 12:34:41 2012 ivan ignatiev
** Last update Mon Dec 10 16:29:30 2012 qiuyan liu
*/

#include	<stdio.h>
#include	"cwlib.h"
#include	"op.h"
#include	"dasm.h"

int		cw_try_run_instr(t_program *prog)
{
  int		n;

  n = 0;
  while (op_tab[n].code)
    {
      if (prog->memory_start[prog->pc] == op_tab[n].code)
	{
	  printf("%s\n", op_tab[n].mnemonique);
	}
	n++;
    }
  prog->pc = prog->pc + 1;
  if (prog->pc == prog->header.prog_size)
    return (0);
  return (1);
}

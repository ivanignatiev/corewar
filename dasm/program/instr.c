/*
** intr.c for corewar in ./dasm/program
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 12:34:41 2012 ivan ignatiev
** Last update Mon Dec 10 17:21:12 2012 ivan ignatiev
*/

#include	<stdio.h>
#include	"cwlib.h"
#include	"op.h"
#include	"dasm.h"

int	cw_instr_live(t_program *prog, op_t *instr)
{
  printf("%s", instr->mnemonique);
  return (1);
}

int	cw_instr_ld(t_program *prog, op_t *instr)
{
  printf("%s", instr->mnemonique);
  return (1);
}

int	cw_instr_st(t_program *prog, op_t *instr)
{
  printf("%s", instr->mnemonique);
  return (1);
}

int	cw_instr_add(t_program *prog, op_t *instr)
{
  printf("%s", instr->mnemonique);
  return (1);
}

int	cw_instr_sub(t_program *prog, op_t *instr)
{
  printf("%s", instr->mnemonique);
  return (1);
}

int	cw_instr_and(t_program *prog, op_t *instr)
{
  printf("%s", instr->mnemonique);
  return (1);
}

int	cw_instr_or(t_program *prog, op_t *instr)
{
  printf("%s", instr->mnemonique);
  return (1);
}

int	cw_instr_xor(t_program *prog, op_t *instr)
{
  printf("%s", instr->mnemonique);
  return (1);
}

int	cw_instr_zjmp(t_program *prog, op_t *instr)
{
  printf("%s", instr->mnemonique);
  return (1);
}
int	cw_instr_ldi(t_program *prog, op_t *instr)
{
  printf("%s", instr->mnemonique);
  return (1);
}

int	cw_instr_sti(t_program *prog, op_t *instr)
{
  printf("%s", instr->mnemonique);
  return (1);
}

int	cw_instr_fork(t_program *prog, op_t *instr)
{
  printf("%s", instr->mnemonique);
  return (1);
}

int	cw_instr_lld(t_program *prog, op_t *instr)
{
  printf("%s", instr->mnemonique);
  return (1);
}

int	cw_instr_lldi(t_program *prog, op_t *instr)
{
  printf("%s", instr->mnemonique);
  return (1);
}

int	cw_instr_lfork(t_program *prog, op_t *instr)
{
  printf("%s", instr->mnemonique);
  return (1);
}

int	cw_instr_aff(t_program *prog, op_t *instr)
{
  printf("%s", instr->mnemonique);
  return (1);
}

int		cw_try_run_instr(t_program *prog)
{
  int		n;
  t_instr	instrs[] = {
    NULL,
    cw_instr_live,
    cw_instr_ld,
    cw_instr_st,
    cw_instr_add,
    cw_instr_sub,
    cw_instr_and,
    cw_instr_or,
    cw_instr_xor,
    cw_instr_zjmp,
    cw_instr_ldi,
    cw_instr_sti,
    cw_instr_fork,
    cw_instr_lld,
    cw_instr_lldi,
    cw_instr_lfork,
    cw_instr_aff
  };

  n = 0;
  printf("Prog #%d: ", prog->prog_num);
  while (op_tab[n].code)
    {
      if (prog->memory_start[prog->pc] == op_tab[n].code)
	{
	  if (instrs[op_tab[n].code] != NULL)
	    instrs[op_tab[n].code](prog, &op_tab[n]);
	}
	n++;
    }
  printf("\n");
  prog->pc = prog->pc + 1;
  if (prog->pc >= prog->header.prog_size)
    return (0);
  return (1);
}

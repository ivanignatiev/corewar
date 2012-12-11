/*
** intr.c for corewar in ./dasm/program
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 12:34:41 2012 ivan ignatiev
** Last update Tue Dec 11 17:13:39 2012 ivan ignatiev
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"cwlib.h"
#include	"op.h"
#include	"dasm.h"

void	cw_show_args(op_t *instr, t_prog_args *args)
{
  int	i;

  if (args[0].type == T_REG)
    printf("%s r%lli", instr->mnemonique, args[0].value);
  else if (args[0].type == T_DIR)
    printf("%s %%%lli", instr->mnemonique, args[0].value);
  else if (args[0].type == T_IND)
    printf("%s %%:%lli", instr->mnemonique, args[0].value);
  i = 1;
  while (i < instr->nbr_args)
    {
      if (args[i].type == T_REG)
	printf(", r%lli", args[i].value);
      else if (args[i].type == T_DIR)
	printf(", %%%lli", args[i].value);
      else if (args[i].type == T_IND)
	printf(", %%:%lli", args[i].value);
      i = i + 1;
    }
}

int	cw_instr_live(t_program *prog, op_t *instr)
{
  t_prog_args	*args;

  args = cw_args_order(instr, 128);
  if (args == NULL)
    return (0);
  args[0].size = 4;
  cw_get_args(prog, instr, args);
  cw_show_args(instr, args);
  free(args);
  return (1);
}

int	cw_instr_ld(t_program *prog, op_t *instr)
{
  t_prog_args	*args;

  args = cw_args_order(instr, prog->memory_start[++prog->pc]);
  if (args == NULL)
    return (0);
  cw_get_args(prog, instr, args);
  cw_show_args(instr, args);
  free(args);
  return (1);
}

int	cw_instr_st(t_program *prog, op_t *instr)
{
  t_prog_args	*args;

  args = cw_args_order(instr, prog->memory_start[++prog->pc]);
  if (args == NULL)
    return (0);
  cw_get_args(prog, instr, args);
  cw_show_args(instr, args);
  free(args);
  return (1);
}

int	cw_instr_add(t_program *prog, op_t *instr)
{
  t_prog_args	*args;

  args = cw_args_order(instr, prog->memory_start[++prog->pc]);
  if (args == NULL)
    return (0);
  cw_get_args(prog, instr, args);
  cw_show_args(instr, args);
  free(args);
  return (1);
}

int	cw_instr_sub(t_program *prog, op_t *instr)
{
  t_prog_args	*args;

  args = cw_args_order(instr, prog->memory_start[++prog->pc]);
  if (args == NULL)
    return (0);
  cw_get_args(prog, instr, args);
  cw_show_args(instr, args);
  free(args);
  return (1);
}

int	cw_instr_and(t_program *prog, op_t *instr)
{
  t_prog_args	*args;

  args = cw_args_order(instr, prog->memory_start[++prog->pc]);
  if (args == NULL)
    return (0);
  cw_get_args(prog, instr, args);
  cw_show_args(instr, args);
  free(args);
  return (1);
}

int	cw_instr_or(t_program *prog, op_t *instr)
{
  t_prog_args	*args;

  args = cw_args_order(instr, prog->memory_start[++prog->pc]);
  if (args == NULL)
    return (0);
  cw_get_args(prog, instr, args);
  cw_show_args(instr, args);
  free(args);
  return (1);
}

int	cw_instr_xor(t_program *prog, op_t *instr)
{
  t_prog_args	*args;

  args = cw_args_order(instr, prog->memory_start[++prog->pc]);
  if (args == NULL)
    return (0);
  cw_get_args(prog, instr, args);
  cw_show_args(instr, args);
  free(args);
  return (1);
}

int	cw_instr_zjmp(t_program *prog, op_t *instr)
{
  t_prog_args	*args;

  args = cw_args_order(instr, 128);
  if (args == NULL)
    return (0);
  if (args[0].type != T_REG)
    args[0].size = IND_SIZE;
  cw_get_args(prog, instr, args);
  cw_show_args(instr, args);
  free(args);
  return (1);
}
int	cw_instr_ldi(t_program *prog, op_t *instr)
{
  t_prog_args	*args;

  args = cw_args_order(instr, prog->memory_start[++prog->pc]);
  if (args == NULL)
    return (0);
  if (args[0].type != T_REG)
    args[0].size = IND_SIZE;
  if (args[1].type != T_REG)
    args[1].size = IND_SIZE;
  cw_get_args(prog, instr, args);
  cw_show_args(instr, args);
  free(args);
  return (1);
}

int	cw_instr_sti(t_program *prog, op_t *instr)
{
  t_prog_args	*args;

  args = cw_args_order(instr, prog->memory_start[++prog->pc]);
  if (args == NULL)
    return (0);
  if (args[1].type != T_REG)
    {
      args[1].size = IND_SIZE;
      args[1].type = T_IND;
    }
  if (args[2].type != T_REG)
    {
      args[2].size = IND_SIZE;
      args[2].type = T_IND;
    }
  cw_get_args(prog, instr, args);
  cw_show_args(instr, args);
  free(args);
  return (1);
}

int	cw_instr_fork(t_program *prog, op_t *instr)
{
  t_prog_args	*args;

  args = cw_args_order(instr, 128);
  if (args == NULL)
    return (0);
  args[0].size = IND_SIZE;
  cw_get_args(prog, instr, args);
  cw_show_args(instr, args);
  free(args);
  return (1);
}

int	cw_instr_lld(t_program *prog, op_t *instr)
{
  t_prog_args	*args;

  args = cw_args_order(instr, prog->memory_start[++prog->pc]);
  if (args == NULL)
    return (0);
  cw_get_args(prog, instr, args);
  cw_show_args(instr, args);
  free(args);
  return (1);
}

int	cw_instr_lldi(t_program *prog, op_t *instr)
{
  t_prog_args	*args;

  args = cw_args_order(instr, prog->memory_start[++prog->pc]);
  if (args == NULL)
    return (0);
  cw_get_args(prog, instr, args);
  cw_show_args(instr, args);
  free(args);
  return (1);
}

int	cw_instr_lfork(t_program *prog, op_t *instr)
{
  t_prog_args	*args;

  args = cw_args_order(instr, 128);
  if (args == NULL)
    return (0);
  args[0].size = IND_SIZE;
  cw_get_args(prog, instr, args);
  cw_show_args(instr, args);
  free(args);
  return (1);
}

int	cw_instr_aff(t_program *prog, op_t *instr)
{
  t_prog_args	*args;

  args = cw_args_order(instr, prog->memory_start[++prog->pc]);
  if (args == NULL)
    return (0);
  cw_get_args(prog, instr, args);
  cw_show_args(instr, args);
  free(args);
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
  printf("Prog #%2d [%4d]: ", prog->prog_num, prog->pc);
  while (op_tab[n].code && prog->memory_start[prog->pc] != op_tab[n].code)
    n++;
  if (instrs[op_tab[n].code] != NULL)
    instrs[op_tab[n].code](prog, &op_tab[n]);
  printf("\n");
  prog->pc = prog->pc + 1;
  if (prog->pc >= prog->header.prog_size)
    return (0);
  return (1);
}

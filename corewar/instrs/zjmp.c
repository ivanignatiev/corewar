/*
** zjmp.c for corewar in ./corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec 12 16:26:30 2012 ivan ignatiev
** Last update Fri Dec 14 21:57:12 2012 ivan ignatiev
*/

#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

int		cw_instr_zjmp(t_program *prog, op_t *instr, t_prog_args *args)
{
  if (args[0].type != T_REG)
    args[0].size = IND_SIZE;
  cw_get_args(prog, instr, args);
  cw_show_args(instr, args, prog);
  if (prog->carry == 1)
    prog->pc = cw_m(prog->previos_pc - 1 + (args[0].value % IDX_MOD));
  return (1);
}

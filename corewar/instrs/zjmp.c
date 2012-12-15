/*
** zjmp.c for corewar in ./corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec 12 16:26:30 2012 ivan ignatiev
** Last update Sat Dec 15 06:07:25 2012 ivan ignatiev
*/

#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

int		cw_instr_zjmp(t_program *prog, op_t *instr, t_prog_args *args)
{
  args[0].size = IND_SIZE;
  cw_get_args(prog, instr, args);
  if (prog->carry == 1)
    prog->pc = cw_m(prog->previos_pc - 1 + (args[0].value % IDX_MOD));
  return (1);
}

/*
** or.c for corewar in ./corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec 12 16:24:28 2012 ivan ignatiev
** Last update Fri Dec 14 17:00:08 2012 ivan ignatiev
*/

#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

int		cw_instr_or(t_program *prog, op_t *instr, t_prog_args *args)
{
  cw_get_args(prog, instr, args);
  cw_show_args(instr, args, prog);
  if (args[0].type == T_REG)
    args[0].value = prog->reg[(args[0].value - 1)];
  if (args[1].type == T_REG)
    args[1].value = prog->reg[(args[1].value - 1)];
  prog->carry = !prog->carry;
  prog->reg[(args[2].value - 1)] = args[0].value | args[1].value;
  return (1);
}

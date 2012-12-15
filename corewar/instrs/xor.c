/*
** xor.c for corewar in /home/ignati_i//projects/corewar/corewar-2016ed-2015s-2017si-liu_q/corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec 12 16:25:44 2012 ivan ignatiev
** Last update Sat Dec 15 05:58:54 2012 ivan ignatiev
*/

#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

int		cw_instr_xor(t_program *prog, op_t *instr, t_prog_args *args)
{
  t_long_type	arg1;
  t_long_type	arg2;

  cw_get_args(prog, instr, args);
  arg1 = args[0].value;
  arg2 = args[1].value;
  if (args[0].type == T_REG)
    arg1 = prog->reg[(args[0].value - 1)];
  if (args[1].type == T_REG)
    arg2 = prog->reg[(args[1].value - 1)];
  prog->reg[(args[2].value - 1)] = arg1 ^ arg2;
  prog->carry = !prog->reg[(args[2].value - 1)];
  return (1);
}

/*
** lldi.c for corewar in ./corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec 12 16:33:15 2012 ivan ignatiev
** Last update Sat Dec 15 05:16:20 2012 ivan ignatiev
*/

#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

int		cw_instr_lldi(t_program *prog, op_t *instr, t_prog_args *args)
{
  t_long_type	addr;

  if (args[0].type != T_REG)
    args[0].size = IND_SIZE;
  if (args[1].type != T_REG)
    args[1].size = IND_SIZE;
  cw_get_args(prog, instr, args);
  if (args[0].type == T_REG)
    args[0].value = prog->reg[(args[0].value - 1)];
  if (args[1].type == T_REG)
    args[1].value = prog->reg[(args[1].value - 1)];
  addr = cw_m(prog->previos_pc
	      + ((prog->previos_pc + (args[0].value))
		 + args[1].value));
  cw_frommemcpy(&prog->reg[(args[2].value - 1)],
		REG_SIZE, sizeof(prog->reg[(args[2].value - 1)]),
		addr);
  my_conv_to_platform(&prog->reg[(args[2].value - 1)],
		      sizeof(prog->reg[(args[2].value - 1)]));
  prog->carry = !prog->reg[(args[2].value - 1)];
  return (1);
}

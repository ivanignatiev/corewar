/*
** st.c for corewar in ./corewar/instrs/
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec 12 16:20:05 2012 ivan ignatiev
** Last update Sat Dec 15 06:19:34 2012 ivan ignatiev
*/

#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

int		cw_instr_st(t_program *prog, op_t *instr, t_prog_args *args)
{
  t_long_type	addr;

  cw_get_args(prog, instr, args);
  if (args[1].type == T_REG)
    {
      prog->reg[(args[1].value - 1)] = prog->reg[(args[0].value - 1)];
    }
  else
    {
      addr = cw_m(prog->previos_pc + (args[1].value % IDX_MOD));
      my_conv_to_platform(&prog->reg[(args[0].value - 1)],
			  sizeof(prog->reg[(args[0].value - 1)]));
      cw_tomemcpy(&prog->reg[(args[0].value - 1)],
		  sizeof(prog->reg[(args[0].value - 1)]), REG_SIZE,
		  addr);
      my_conv_to_platform(&prog->reg[(args[0].value - 1)],
			  sizeof(prog->reg[(args[0].value - 1)]));
    }
  return (1);
}

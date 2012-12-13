/*
** st.c for corewar in ./corewar/instrs/
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec 12 16:20:05 2012 ivan ignatiev
** Last update Thu Dec 13 17:02:26 2012 ivan ignatiev
*/

#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

int		cw_instr_st(t_program *prog, op_t *instr, t_prog_args *args)
{
  t_long_type	addr;

  cw_get_args(prog, instr, args);
  cw_show_args(instr, args, prog);
  if (args[1].type == T_REG)
    {
      prog->reg[(args[1].value - 1)] = prog->reg[(args[0].value - 1)];
    }
  else
    {
      addr = (prog->previos_pc + (args[0].value % IDX_MOD)) % MEM_SIZE;
      my_conv_to_platform(&prog->reg[(args[0].value - 1)], sizeof(prog->reg[(args[0].value - 1)]));
      my_memncpy(g_memory + addr, &prog->reg[(args[0].value - 1)],
		 sizeof(prog->reg[(args[0].value - 1)]), REG_SIZE);
      my_conv_to_platform(&prog->reg[(args[0].value - 1)], sizeof(prog->reg[(args[0].value - 1)]));
    }
  return (1);
}

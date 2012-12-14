/*
** ld.c for corewar in ./corewar/instrs/
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec 12 16:19:22 2012 ivan ignatiev
** Last update Fri Dec 14 17:27:23 2012 ivan ignatiev
*/

#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

int		cw_instr_ld(t_program *prog, op_t *instr, t_prog_args *args)
{
  t_long_type	addr;

  cw_get_args(prog, instr, args);
  cw_show_args(instr, args, prog);
  prog->carry = !prog->carry;
  addr = (prog->previos_pc + (args[0].value % IDX_MOD)) % MEM_SIZE;
  cw_frommemcpy(&prog->reg[(args[1].value - 1)],
		REG_SIZE, sizeof(prog->reg[(args[1].value - 1)]),
		addr);
  my_conv_to_platform(&prog->reg[(args[1].value - 1)],
		      sizeof(prog->reg[(args[1].value - 1)]));
  return (1);
}

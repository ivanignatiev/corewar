/*
** ld.c for corewar in ./corewar/instrs/
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec 12 16:19:22 2012 ivan ignatiev
** Last update Wed Dec 12 18:26:33 2012 ivan ignatiev
*/

#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

int		cw_instr_ld(t_program *prog, op_t *instr, t_prog_args *args)
{
  int		addr;

  cw_get_args(prog, instr, args);
  cw_show_args(instr, args, prog);
  addr = (prog->pc + (args[0].value % IDX_MOD)) % MEM_SIZE;
  my_memncpy(&prog->reg[args[1].value], prog->memory_start + addr,
	     REG_SIZE, sizeof(prog->reg[args[1].value]));
  my_conv_to_platform(&prog->reg[args[1].value],
		      sizeof(prog->reg[args[1].value]));
  return (1);
}

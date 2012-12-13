/*
** sti.c for corewar in ./corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec 12 16:29:49 2012 ivan ignatiev
** Last update Thu Dec 13 17:02:02 2012 ivan ignatiev
*/

#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

int		cw_instr_sti(t_program *prog, op_t *instr, t_prog_args *args)
{
  unsigned char	*addr;

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
  cw_show_args(instr, args, prog);
  if (args[1].type == T_REG)
    args[1].value = prog->reg[args[1].value];
  if (args[2].type == T_REG)
    args[2].value = prog->reg[args[1].value];
  addr = (g_memory + (args[1].value + args[2].value) % MEM_SIZE);
  my_conv_to_platform(&prog->reg[(args[0].value - 1)], sizeof(prog->reg[(args[0].value - 1)]));
  my_memncpy(addr, &prog->reg[(args[0].value - 1)],
	     sizeof(prog->reg[(args[0].value - 1)]), REG_SIZE);
  my_conv_to_platform(&prog->reg[(args[0].value - 1)], sizeof(prog->reg[(args[0].value - 1)]));
  return (1);
}

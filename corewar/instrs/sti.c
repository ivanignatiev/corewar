/*
** sti.c for corewar in ./corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec 12 16:29:49 2012 ivan ignatiev
** Last update Sat Dec 15 12:27:38 2012 ivan ignatiev
*/

#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

static void	cw_init_sti_args(t_prog_args *args)
{
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
}

int		cw_instr_sti(t_program *prog, op_t *instr, t_prog_args *args)
{
  if (prog->instr.wait)
    {
      cw_init_sti_args(args);
      if (cw_get_args(prog, instr, args))
	{
	  args[1].wval = args[1].value;
	  args[2].wval = args[2].value;
	  if (args[1].type == T_REG)
	    args[1].wval = prog->reg[args[1].value - 1];
	  if (args[2].type == T_REG)
	    args[2].wval = prog->reg[args[2].value - 1];
	  args[0].wval =  cw_m(prog->previos_pc
				   + (args[1].wval + args[2].wval) % IDX_MOD);
	  args[0].change = 1;
	  return (1);
	}
      return (0);
    }
  my_conv_to_platform(&prog->reg[(args[0].value - 1)],
		      sizeof(prog->reg[(args[0].value - 1)]));
  cw_tomemcpy(&prog->reg[(args[0].value - 1)],
	      sizeof(prog->reg[(args[0].value - 1)]), REG_SIZE, args[0].wval);
  my_conv_to_platform(&prog->reg[(args[0].value - 1)],
		      sizeof(prog->reg[(args[0].value - 1)]));
  return (1);
}

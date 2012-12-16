/*
** ld.c for corewar in ./corewar/instrs/
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec 12 16:19:22 2012 ivan ignatiev
** Last update Sat Dec 15 12:39:50 2012 ivan ignatiev
*/

#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

int		cw_instr_ld(t_program *prog, op_t *instr, t_prog_args *args)
{
  t_long_type	addr;

  if (prog->instr.wait)
    {
      if (cw_get_args(prog, instr, args))
	{
	  if (args[0].type == T_IND)
	    {
	      addr = cw_m(prog->previos_pc + (args[0].value % IDX_MOD));
	      cw_frommemcpy(&args[1].wval, REG_SIZE,
			    sizeof(args[1].wval), addr);
	      my_conv_to_platform(&args[1].wval,
				  sizeof(args[1].wval));
	    }
	  else
	    args[1].wval = args[0].value;
	  args[1].change = 1;
	  prog->carry = !args[1].wval;
	  return (1);
	}
      return (0);
    }
  prog->reg[(args[1].value - 1)] = args[1].wval;
  return (1);
}

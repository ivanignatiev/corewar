/*
** lldi.c for corewar in ./corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec 12 16:33:15 2012 ivan ignatiev
** Last update Sat Dec 15 12:21:50 2012 ivan ignatiev
*/

#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

static int	cw_lldi_args(t_program *prog, op_t *instr, t_prog_args *args)
{
  t_long_type	addr;

  if (args[0].type != T_REG)
    args[0].size = IND_SIZE;
  if (args[1].type != T_REG)
    args[1].size = IND_SIZE;
  if (cw_get_args(prog, instr, args))
    {
      args[0].wval = args[0].value;
      args[1].wval = args[1].value;
      if (args[0].type == T_REG)
	args[0].wval = prog->reg[(args[0].value - 1)];
      if (args[1].type == T_REG)
	args[1].wval = prog->reg[(args[1].value - 1)];
      addr = cw_m(prog->previos_pc + ((prog->previos_pc + (args[0].wval))
		     + args[1].wval));
      cw_frommemcpy(&args[2].wval,
		    REG_SIZE, sizeof(args[2].wval), addr);
      my_conv_to_platform(&args[2].wval,
			  sizeof(args[2].wval));
      args[2].change = 1;
      prog->carry = !args[2].wval;
      return (1);
    }
  return (0);
}

int		cw_instr_lldi(t_program *prog, op_t *instr, t_prog_args *args)
{
  if (prog->instr.wait)
    return (cw_lldi_args(prog, instr, args));
  prog->reg[(args[2].value - 1)] = args[2].wval;
  return (1);
}

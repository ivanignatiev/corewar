/*
** and.c for corewar in ./corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec 12 16:23:29 2012 ivan ignatiev
** Last update Sat Dec 15 12:14:37 2012 ivan ignatiev
*/

#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

int		cw_instr_and(t_program *prog, op_t *instr, t_prog_args *args)
{
  if (prog->instr.wait)
    {
      if (cw_get_args(prog, instr, args))
	{
	  args[0].wval = args[0].value;
	  args[1].wval = args[1].value;
	  if (args[0].type == T_REG)
	    args[0].wval = prog->reg[(args[0].value - 1)];
	  if (args[1].type == T_REG)
	    args[1].wval = prog->reg[(args[1].value - 1)];
	  args[2].change = 1;
	  args[2].wval = args[0].wval & args[1].wval;
	  prog->carry = !args[2].wval;
	  return (1);
	}
      return (0);
    }
  prog->reg[(args[2].value - 1)] = args[2].wval;
  return (1);
}

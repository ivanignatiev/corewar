/*
** add.c for corewar in ./corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec 12 16:21:17 2012 ivan ignatiev
** Last update Sat Dec 15 12:13:53 2012 ivan ignatiev
*/

#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

int		cw_instr_add(t_program *prog, op_t *instr, t_prog_args *args)
{
  if (prog->instr.wait)
    {
      if (cw_get_args(prog, instr, args))
	{
	  args[2].change = 1;
	  args[2].wval = prog->reg[(args[0].value - 1)]
	    + prog->reg[(args[1].value - 1)];
	  prog->carry = !args[2].wval;
	  return (1);
	}
      return (0);
    }
  prog->reg[(args[2].value - 1)] = args[2].wval;
  return (1);
}

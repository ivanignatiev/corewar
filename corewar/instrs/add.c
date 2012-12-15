/*
** add.c for corewar in ./corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec 12 16:21:17 2012 ivan ignatiev
** Last update Fri Dec 14 22:10:54 2012 ivan ignatiev
*/

#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

int		cw_instr_add(t_program *prog, op_t *instr, t_prog_args *args)
{
  cw_get_args(prog, instr, args);
  cw_show_args(instr, args, prog);
  prog->reg[(args[2].value - 1)] = prog->reg[(args[0].value - 1)]
    + prog->reg[(args[1].value - 1)];
  prog->carry = !prog->reg[(args[2].value - 1)];
  return (1);
}

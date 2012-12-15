/*
** sub.c for corewar in ./corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec 12 16:22:30 2012 ivan ignatiev
** Last update Sat Dec 15 05:16:46 2012 ivan ignatiev
*/

#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

int	cw_instr_sub(t_program *prog, op_t *instr, t_prog_args *args)
{
  cw_get_args(prog, instr, args);
  prog->reg[(args[2].value - 1)] = prog->reg[(args[0].value - 1)]
    - prog->reg[(args[1].value - 1)];
  prog->carry = !prog->reg[(args[2].value - 1)];
  return (1);
}

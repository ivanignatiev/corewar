/*
** sub.c for corewar in ./corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec 12 16:22:30 2012 ivan ignatiev
** Last update Thu Dec 13 15:50:49 2012 ivan ignatiev
*/

#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

int	cw_instr_sub(t_program *prog, op_t *instr, t_prog_args *args)
{
  cw_get_args(prog, instr, args);
  cw_show_args(instr, args, prog);
  prog->carry = 1;
  prog->reg[args[2].value] = args[0].value - args[1].value;
  return (1);
}

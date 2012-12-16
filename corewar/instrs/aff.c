/*
** aff.c for corewar in ./corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec 12 16:35:56 2012 ivan ignatiev
** Last update Sat Dec 15 09:19:22 2012 ivan ignatiev
*/

#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

int		cw_instr_aff(t_program *prog, op_t *instr, t_prog_args *args)
{
  if (prog->instr.wait)
    return (cw_get_args(prog, instr, args));
  my_putchar(prog->reg[(args[0].value - 1)] % 256);
  return (1);
}

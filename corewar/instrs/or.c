/*
** or.c for corewar in ./corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec 12 16:24:28 2012 ivan ignatiev
** Last update Wed Dec 12 16:25:05 2012 ivan ignatiev
*/

#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

int		cw_instr_or(t_program *prog, op_t *instr, t_prog_args *args)
{
  cw_get_args(prog, instr, args);
  cw_show_args(instr, args, prog);

  return (1);
}
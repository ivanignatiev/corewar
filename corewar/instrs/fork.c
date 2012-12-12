/*
** fork.c for corewar in ./corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec 12 16:31:17 2012 ivan ignatiev
** Last update Wed Dec 12 16:32:09 2012 ivan ignatiev
*/

#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

int		cw_instr_fork(t_program *prog, op_t *instr, t_prog_args *args)
{
  args[0].size = IND_SIZE;
  cw_get_args(prog, instr, args);
  cw_show_args(instr, args, prog);


  return (1);
}

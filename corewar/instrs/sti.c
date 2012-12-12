/*
** sti.c for corewar in /home/ignati_i//projects/corewar/corewar-2016ed-2015s-2017si-liu_q/corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec 12 16:29:49 2012 ivan ignatiev
** Last update Wed Dec 12 18:34:41 2012 ivan ignatiev
*/

#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

int		cw_instr_sti(t_program *prog, op_t *instr, t_prog_args *args)
{
  if (args[1].type != T_REG)
    {
      args[1].size = IND_SIZE;
      args[1].type = T_IND;
    }
  if (args[2].type != T_REG)
    {
      args[2].size = IND_SIZE;
      args[2].type = T_IND;
    }
  cw_get_args(prog, instr, args);
  cw_show_args(instr, args, prog);
  if (args[1].type == T_REG)
    args[1].value = prog->reg[args[1].value];
  if (args[2].type == T_REG)
    args[2].value = prog->reg[args[1].value];
  my_memncpy((g_memory + (args[1].value + args[2].value) % MEM_SIZE), &prog->reg[args[0].value], REG_SIZE, REG_SIZE);
  return (1);
}

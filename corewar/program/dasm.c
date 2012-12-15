/*
** dasm.c for corewar in ./corewar/program
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Dec 15 04:56:50 2012 ivan ignatiev
** Last update Sat Dec 15 05:54:19 2012 ivan ignatiev
*/

#include	"op.h"
#include	"cwlib.h"
#include	"corewar.h"

void		cw_show_args(op_t *instr, t_prog_args *args,
			     t_program *prog)
{
  int		i;

  if ((g_options & O_AFF_SHELL) == 0)
    return ;

  printf("Prog #%3i {%6li-%6li} [%4li]: ", prog->prog_num,
	 prog->cycle - instr->nbr_cycles + 1
	 ,prog->cycle + 1, prog->previos_pc);
  if (args[0].type == T_REG)
    printf("%s r%li", instr->mnemonique, args[0].value);
  else if (args[0].type == T_DIR)
    printf("%s %%%li", instr->mnemonique, args[0].value);
  else if (args[0].type == T_IND)
    printf("%s %%:%li", instr->mnemonique, args[0].value);
  i = 1;
  while (i < instr->nbr_args)
    {
      if (args[i].type == T_REG)
	printf(", r%li", args[i].value);
      else if (args[i].type == T_DIR)
	printf(", %%%li", args[i].value);
      else if (args[i].type == T_IND)
	printf(", %%:%li", args[i].value);
      i = i + 1;
    }
  i = 0;
  printf(" # {");
  if (args[0].type == T_REG)
    printf(" [r%li = %li] ", args[0].value, prog->reg[args[0].value - 1]);
  if (args[1].type == T_REG)
    printf(" [r%li = %li] ", args[1].value, prog->reg[args[1].value - 1]);
  if (args[2].type == T_REG)
    printf(" [r%li = %li] ", args[2].value, prog->reg[args[2].value - 1]);
  printf(" , carry = %i}", prog->carry);
  printf("\n");
}

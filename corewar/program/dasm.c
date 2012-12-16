/*
** dasm.c for corewar in ./corewar/program
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Dec 15 04:56:50 2012 ivan ignatiev
** Last update Sat Dec 15 13:09:39 2012 ivan ignatiev
*/

#include	"op.h"
#include	"cwlib.h"
#include	"corewar.h"

void		cw_show_args(t_program *prog, op_t *instr, t_prog_args *args)
{
  int		i;

  if ((g_options & O_AFF_SHELL) == 0)
    return ;

  printf("Prog #%3i {%6li-%6li} [%4li]: ", prog->prog_num,
	 prog->cycle,
	 prog->cycle + prog->instr.nbr_cycles,
	 prog->previos_pc);
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
  printf(" #{");
  i = 0;
  while (i < instr->nbr_args)
    {
      if (args[i].change)
	{
	  if (args[i].type == T_REG)
	    printf("cng[r%li=%li->%li] ", args[i].value, prog->reg[args[i].value - 1], args[i].wval);
	  else
	    printf("cng[a=%li] ", args[i].wval);
	}
      else if (args[i].type == T_REG)
	printf("str[r%li=%li] ",args[i].value, prog->reg[args[i].value - 1]);
      i = i + 1;
    }
  printf("carry=%d}", prog->carry);
  printf("\n");
}

/*
** dasm.c for corewar in ./corewar/program
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Dec 15 04:56:50 2012 ivan ignatiev
** Last update Sat Dec 15 15:51:53 2012 ivan ignatiev
*/

#include	"op.h"
#include	"cwlib.h"
#include	"corewar.h"

static void	cw_show_addr_params(t_program *prog,
				    op_t *instr,
				    t_prog_args *args)
{
  if (prog && instr && args)
    {
      my_fprintf(OSTD, "Prog #%4l {%6l-%6l} [%5l]: ",
		 prog->prog_num,
		 prog->cycle,
		 prog->cycle + prog->instr.nbr_cycles,
		 prog->previos_pc);
    }
}

static void	cw_show_instr_params(t_program *prog,
				     op_t *instr,
				     t_prog_args *args)
{
  int		i;

  if (!prog || !instr || !args)
    return ;
  if (args[0].type == T_REG)
    my_fprintf(OSTD, "%s r%l", instr->mnemonique, args[0].value);
  else if (args[0].type == T_DIR)
    my_fprintf(OSTD, "%s %%%l", instr->mnemonique, args[0].value);
  else if (args[0].type == T_IND)
    my_fprintf(OSTD, "%s %%:%l", instr->mnemonique, args[0].value);
  i = 1;
  while (i < instr->nbr_args)
    {
      if (args[i].type == T_REG)
	my_fprintf(OSTD, ", r%l", args[i].value);
      else if (args[i].type == T_DIR)
	my_fprintf(OSTD, ", %%%l", args[i].value);
      else if (args[i].type == T_IND)
	my_fprintf(OSTD, ", %%:%l", args[i].value);
      i = i + 1;
    }
}

static void	cw_show_details(t_program *prog,
				op_t *instr,
				t_prog_args *args)
{
  int		i;

  if (!prog || !instr || !args)
    return ;
  my_fprintf(OSTD, " #{");
  i = 0;
  while (i < instr->nbr_args)
    {
      if (args[i].change)
	{
	  if (args[i].type == T_REG)
	    my_fprintf(OSTD, "cng[r%l=%l->%l] ", args[i].value,
		       prog->reg[args[i].value - 1],
		       args[i].wval);
	  else
	    my_fprintf(OSTD, "cng[a=%l] ", args[i].wval);
	}
      else if (args[i].type == T_REG)
	my_fprintf(OSTD, "str[r%l=%l] ",args[i].value,
		   prog->reg[args[i].value - 1]);
      i = i + 1;
    }
  my_fprintf(OSTD, "carry=%l}", prog->carry);
}


void		cw_show_args(t_program *prog,
			     op_t *instr,
			     t_prog_args *args)
{
  if ((g_options & O_AFF_SHELL) == 0)
    return ;

  cw_show_addr_params(prog, instr, args);
  cw_show_instr_params(prog, instr, args);
  cw_show_details(prog, instr, args);
  my_fprintf(OSTD, "\n");
}

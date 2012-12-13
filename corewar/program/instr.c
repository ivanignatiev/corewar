/*
** intr.c for corewar in ./dasm/program
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 12:34:41 2012 ivan ignatiev
** Last update Thu Dec 13 18:08:08 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

void	cw_show_args(op_t *instr, t_prog_args *args, t_program *prog)
{
  int	i;

  printf("Prog #%2i {%6li} [%4li]: ", prog->prog_num, (g_cycles + 1), prog->pc);
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
  while (i < REG_NUMBER)
    {
      printf("[r%i = %li]", i + 1,  prog->reg[i]);
      ++i;
    }
  printf(" , carry = %i}", prog->carry);
  printf("\n");
}

int		cw_call_instraction(t_program *prog, op_t *instr, t_prog_instr *instrs)
{
  t_prog_args	*args;
  int		result;

  prog->previos_pc = prog->pc;
  if (instrs[instr->code].enc_byte)
    args = cw_args_order(instr, g_memory[(++prog->pc) % MEM_SIZE]);
  else
    args = cw_args_order(instr, (char)128);
  if (args != NULL)
    {
      result = instrs[instr->code].func(prog, instr, args);
      free(args);
      return (result);
    }
  return (0);
}

int		cw_try_run_instr(t_program *prog, t_prog_instr *instrs)
{
  int		n;

  n = 0;
  while ((op_tab[n].code != 0) && (g_memory[prog->pc] != op_tab[n].code))
    n++;
  if (n <= 16 && instrs[op_tab[n].code].func != NULL)
    {
      if (prog->cur_nbr_cycles < 0)
	prog->cur_nbr_cycles = (op_tab[n].nbr_cycles - 1);
      else if (prog->cur_nbr_cycles == 0)
	{
	  cw_call_instraction(prog, &op_tab[n], instrs);
	  prog->pc = (prog->pc + 1) % MEM_SIZE;
	}
      --prog->cur_nbr_cycles;
    }
  else
    ++prog->pc;
  return (1);
}

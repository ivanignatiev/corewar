/*
** intr.c for corewar in ./dasm/program
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 12:34:41 2012 ivan ignatiev
** Last update Sat Dec 15 05:54:54 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

static int	cw_call_instruction(t_program *prog, op_t *instr,
				    t_prog_instr *instrs)
{
  t_prog_args	*args;
  int		result;

  prog->previos_pc = prog->pc;
  if (instrs[(int)instr->code].enc_byte == 1)
    {
      prog->pc = cw_m(prog->pc + 1);
      args = cw_args_order(instr, g_memory[prog->pc]);
    }
  else
    args = cw_args_order(instr, (char)128);
  if (args != NULL)
    {
      result = instrs[(int)instr->code].func(prog, instr, args);
      cw_show_args(instr, args, prog);
      free(args);
      return (result);
    }
  return (0);
}

static void	cw_bad_instr(t_program *prog)
{
  if (g_options & O_AFF_SHELL)
    printf("Prog #%3li {%13li} [%4li]: Bad instruction\n",
	   prog->prog_num,
	   prog->cycle,
	   prog->previos_pc);
}

int		cw_try_run_instr(t_program *prog,
				 t_prog_instr *instrs,
				 t_long_type cycle)
{
  int		n;

  n = 0;
  prog->cycle = cycle;
  while ((op_tab[n].code != 0) && (g_memory[prog->pc] != op_tab[n].code))
    n++;
  if (n <= 16 && instrs[(int)op_tab[n].code].func != NULL)
    {
      if (prog->cur_nbr_cycles < 0)
	prog->cur_nbr_cycles = op_tab[n].nbr_cycles - 1;
      else if (prog->cur_nbr_cycles == 0)
	{
	  cw_call_instruction(prog, &op_tab[n], instrs);
	  prog->pc = cw_m(prog->pc + 1);
	}
    }
  else
    {
      cw_bad_instr(prog);
      prog->pc = cw_m(prog->pc + 1);
    }
  --prog->cur_nbr_cycles;
  return (1);
}

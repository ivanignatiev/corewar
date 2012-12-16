/*
** intr.c for corewar in ./dasm/program
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 12:34:41 2012 ivan ignatiev
** Last update Sat Dec 15 15:38:19 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

static void	cw_bad_instr(t_program *prog)
{
  if (g_options & O_AFF_SHELL)
    my_fprintf(OSTD, "Prog #%3l {%12l} [%4l]: Bad instruction\n",
	   prog->prog_num,
	   prog->cycle,
	   prog->previos_pc);
  prog->instr.nbr_cycles = -1;
}

static int	cw_prepare_args(t_program *prog, t_prog_instr *instrs)
{
  int		result;

  if (instrs[(int)prog->instr.op->code].enc_byte == 1)
    {
      prog->pc = cw_m(prog->pc + 1);
      prog->instr.args = cw_args_order(prog->instr.op, g_memory[prog->pc]);
    }
  else
    prog->instr.args = cw_args_order(prog->instr.op, (char)128);
  if (prog->instr.args != NULL)
    {
      result = instrs[(int)prog->instr.op->code].func(prog,
						      prog->instr.op,
						      prog->instr.args);
      prog->instr.wait = 0;
      if (!result)
	free(prog->instr.args);
      return (result);
    }
  return (0);
}
static int	cw_prepare_instr(t_program *prog, t_prog_instr *instrs)
{
  int		n;

  n = 0;
  while ((op_tab[n].code != 0) && (g_memory[prog->pc] != op_tab[n].code))
    n++;
  if (n <= 16 && instrs[(int)op_tab[n].code].func != NULL)
    {
      prog->instr.op = &op_tab[n];
      prog->instr.wait = 1;
      prog->instr.nbr_cycles = op_tab[n].nbr_cycles - 1;
      if (prog->instr.args != NULL)
	free(prog->instr.args);
      return (cw_prepare_args(prog, instrs));
    }
  return (0);
}

int		cw_try_run_instr(t_program *prog,
				 t_prog_instr *instrs,
				 t_long_type cycle)
{
  prog->cycle = cycle;
  if (prog->instr.nbr_cycles < 0)
    {
      prog->previos_pc = prog->pc;
      if (cw_prepare_instr(prog, instrs))
	cw_show_args(prog, prog->instr.op, prog->instr.args);
      else
	cw_bad_instr(prog);
      prog->pc = cw_m(prog->pc + 1);
    }
  else if (prog->instr.nbr_cycles == 0 && prog->instr.args != NULL)
    instrs[(int)prog->instr.op->code].func(prog,
					   prog->instr.op,
					   prog->instr.args);
  --prog->instr.nbr_cycles;
  return (1);
}

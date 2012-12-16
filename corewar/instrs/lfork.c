/*
** lfork.c for corewar in ./corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec 12 16:34:08 2012 ivan ignatiev
** Last update Sat Dec 15 13:38:38 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

static int		cw_add_fork_to_list(t_program *prog_fork)
{
  t_prog_list		*prog_elem;
  t_prog_list		*nav;

  if ((prog_elem = (t_prog_list*)malloc(sizeof(t_prog_list))) != NULL)
    {
      prog_elem->prog = prog_fork;
      prog_elem->next = NULL;
      if (g_prog_list == NULL)
	g_prog_list = prog_elem;
      else
	{
	  nav = g_prog_list;
	  while (nav->next)
	    nav = nav->next;
	  nav->next = prog_elem;
	}
      return (1);
    }
  return (0);
}

static t_program	*cw_copy_program(t_program *prog)
{
  t_program		*new_prog;

  if ((new_prog = (t_program*)malloc(sizeof(t_program))) != NULL)
    {
      my_memncpy(new_prog, prog, sizeof(t_program), sizeof(t_program));
      new_prog->fork = 1;
      new_prog->instr.nbr_cycles = -1;
      new_prog->instr.args = NULL;
      new_prog->prog_num = cw_get_prog_number();
    }
  return (new_prog);
}

int			cw_instr_lfork(t_program *prog, op_t *instr, t_prog_args *args)
{
  t_program		*new_prog;

  if (prog->instr.wait)
    {
      args[0].size = IND_SIZE;
      if (cw_get_args(prog, instr, args))
	{
	  args[0].wval = cw_m(prog->previos_pc + (args[0].value));
	  args[0].change = 1;
	  prog->carry = !args[0].wval;
	  return (1);
	}
      return (0);
    }
  if ((new_prog = cw_copy_program(prog)) != NULL)
    {
      if (cw_add_fork_to_list(new_prog))
	{
	  new_prog->pc = args[0].wval;
	  return (1);
	}
      free(new_prog);
    }
  return (0);
}

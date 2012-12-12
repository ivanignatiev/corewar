/*
** fork.c for corewar in ./corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec 12 16:31:17 2012 ivan ignatiev
** Last update Wed Dec 12 18:06:24 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

int		cw_add_fork_to_list(t_program *prog_fork)
{
  t_prog_list	*prog_elem;
  t_prog_list	*nav;

  if ((prog_elem = (t_prog_list*)malloc(sizeof(t_prog_list))) != NULL)
    {
      prog_elem->prog = prog_fork;
      prog_elem->next = NULL;
      prog_elem->active = 1;
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

t_program	*cw_copy_program(t_program *prog)
{
  t_program	*new_prog;

  if ((new_prog = (t_program*)malloc(sizeof(t_program))) != NULL)
    {
      my_memncpy(new_prog, prog, sizeof(t_program), sizeof(t_program));
      new_prog->fork = 1;
    }
  return (new_prog);
}

int		cw_instr_fork(t_program *prog, op_t *instr, t_prog_args *args)
{
  t_program	*new_prog;

  args[0].size = IND_SIZE;
  cw_get_args(prog, instr, args);
  cw_show_args(instr, args, prog);
  if ((new_prog = cw_copy_program(prog)) != NULL)
    {
      if (cw_copy_memprogram(new_prog))
	{
	  if (cw_add_fork_to_list(new_prog))
	    {
	      new_prog->pc = new_prog->pc + (args[0].value % IDX_MOD);
	      return (1);
	    }
	}
      free(new_prog);
      return (0);
    }
}

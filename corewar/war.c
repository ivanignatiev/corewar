/*
** war.c for corewar in ./corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Dec 15 02:41:04 2012 ivan ignatiev
** Last update Sat Dec 15 05:12:39 2012 ivan ignatiev
*/

#include		<stdlib.h>
#include		"cwlib.h"
#include		"op.h"
#include		"corewar.h"

static t_long_type	cw_cycle_to_die(t_cycle *cycle,
					t_long_type prog_count)
{
  t_prog_list		*nav;

  if (cycle->nbr == cycle->die)
    {
      nav = g_prog_list;
      while (nav != NULL)
	{
	  if (cycle->die != nav->prog->last_live_cycle)
	    {
	      if (g_options & O_DIE_MSG)
		printf("%3li (%s) die on %lli cycle\n",
		       nav->prog->prog_num,
		       nav->prog->header.prog_name,
		       cycle->nbr);
	      cw_remove_program(nav->prog);
	    }
	  nav = nav->next;
	}
      return (cw_get_prog_count());
    }
  return (prog_count);
}

static int		cw_nbr_live_calls(t_cycle *cycle)
{
  t_prog_list		*nav;

  if (cycle->live_calls == 0)
    {
      cycle->nbr = 1;
      cycle->die -= CYCLE_DELTA;
      cycle->live_calls = NBR_LIVE;
      nav = g_prog_list;
      while (nav != NULL)
	{
	  cw_reset_program(nav->prog);
	  nav = nav->next;
	}
      return (1);
    }
  return (0);
}

static int		cw_dump_cycle(t_cycle *cycle)
{
  if (g_cycle_to_dump == cycle->nbr)
    {
      cw_dump_memory(g_memory, MEM_SIZE);
      return (1);
    }
  return (0);
}

void			begin_corewar(t_cycle *cycle,
				      t_long_type prog_count)
{
  t_prog_list		*nav;
  t_prog_instr		*instrs;

  if ((instrs = cw_instrs_list()) == NULL)
    return ;
  while (prog_count > 0 && cycle->die >= 0)
    {
      nav = g_prog_list;
      while (nav != NULL)
	{
	  if (!nav->prog->fork)
	    cw_try_run_instr(nav->prog, instrs, cycle->nbr);
	  else
	    nav->prog->fork = 0;
	  if (nav->prog->last_live_cycle == cycle->nbr
	      && cw_nbr_live_calls(cycle))
	    nav = NULL;
	  else
	    nav = nav->next;
	}
      prog_count = cw_cycle_to_die(cycle, prog_count);
      if (cw_dump_cycle(cycle))
	return ;
      ++cycle->nbr;
    }
}

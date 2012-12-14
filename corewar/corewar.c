/*
** dasm.c for corewar in ./dasm
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec  5 14:03:15 2012 ivan ignatiev
** Last update Fri Dec 14 16:20:54 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

static void	begin_corewar()
{
  t_prog_list	*nav;
  int		prog_count;
  t_long_type	cycle_to_die;
  int		die_cycle;
  t_prog_instr	instrs[] = {
    {NULL, 0},
    {cw_instr_live, 0},
    {cw_instr_ld, 1},
    {cw_instr_st, 1},
    {cw_instr_add, 1},
    {cw_instr_sub, 1},
    {cw_instr_and, 1},
    {cw_instr_or, 1},
    {cw_instr_xor, 1},
    {cw_instr_zjmp, 0},
    {cw_instr_ldi, 1},
    {cw_instr_sti, 1},
    {cw_instr_fork, 0},
    {cw_instr_lld, 1},
    {cw_instr_lldi, 1},
    {cw_instr_lfork, 0},
    {cw_instr_aff, 1}
  };

  prog_count = cw_get_prog_count();
  g_cycles = 1;
  die_cycle = 0;
  cycle_to_die = CYCLE_TO_DIE;
  g_live_calls = 0;
  while (prog_count > 0 && cycle_to_die >= 0)
    {
      if (g_cycles == cycle_to_die)
	die_cycle = 1;
      nav = g_prog_list;
      while (nav != NULL)
	{
	  if (!nav->prog->fork)
	    {
	      cw_try_run_instr(nav->prog, instrs);
	      if (cycle_to_die != nav->prog->last_live_cycle && die_cycle)
		{
		  printf("Prog #%d(%s) die on %d\n", nav->prog->prog_num, nav->prog->header.prog_name, nav->prog->cur_nbr_cycles);
		  cw_remove_program(nav->prog);
		  prog_count = cw_get_prog_count();
		}
	      if (g_live_calls == NBR_LIVE)
		{
		  cw_reset_program(nav->prog);
		}
	    }
	  else
	    nav->prog->fork = 0;
	  nav = nav->next;
	}
      if (g_cycle_to_dump == g_cycles)
	cw_dump_memory(g_memory, MEM_SIZE);
      ++g_cycles;
      die_cycle = 0;
      if (g_live_calls == NBR_LIVE)
	{
	  g_cycles = 1;
	  cycle_to_die -= CYCLE_DELTA;
	  g_live_calls = 0;
	}
    }
}

int		main(int argc, char **argv)
{
  if (argc > 1 && argv)
    {
      if (cw_init_memory())
	{
	  g_last_live = NULL;
	  if (cw_get_program_list(argc, argv))
	    {
	      if (cw_try_place_programs())
		{
		  begin_corewar();
		  if (g_last_live)
		    {
		      printf("player %ld(%s) won\n", g_last_live->prog_num, g_last_live->header.prog_name);
		      free(g_last_live);
		    }
		  return (EXIT_SUCCESS);
		}
	    }
	  cw_free_memory();
	}
    }
  else
    my_puterr("Too few arguments.\n");
  return (EXIT_FAILURE);
}

/*
** dasm.c for corewar in ./dasm
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec  5 14:03:15 2012 ivan ignatiev
** Last update Sat Dec 15 04:37:52 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

static void	cw_winner()
{
  if (g_last_live)
    {
      printf("player %ld(%s) won\n", g_last_live->prog_num,
	     g_last_live->header.prog_name);
    }
}

static t_cycle	*cw_init_cycle()
{
  t_cycle	*cycle;

  if ((cycle = (t_cycle*)malloc(sizeof(t_cycle))) != NULL)
    {
      cycle->nbr = 1;
      cycle->live_calls = NBR_LIVE;
      cycle->die = CYCLE_TO_DIE;
    }
  return (cycle);
}

int		main(int argc, char **argv)
{
  t_long_type	prog_count;
  t_cycle	*cycle;

  if (argc > 1 && argv != NULL)
    {
      if (cw_init_memory())
	{
	  if ((cycle = cw_init_cycle()) != NULL)
	    {
	      if (cw_get_program_list(argc, argv))
		if ((prog_count = cw_try_place_programs()) != 0)
		  {
		    begin_corewar(cycle, prog_count);
		    cw_winner();
		    cw_free_memory();
		    return (EXIT_SUCCESS);
		  }
	      free(cycle);
	    }
	  cw_free_memory();
	}
    }
  else
    printf("corewar: Too few arguments\n");
  return (EXIT_FAILURE);
}

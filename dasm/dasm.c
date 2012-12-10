/*
** dasm.c for corewar in ./dasm
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec  5 14:03:15 2012 ivan ignatiev
** Last update Mon Dec 10 13:20:56 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"cwlib.h"
#include	"op.h"
#include	"dasm.h"

void		begin_corewar()
{
  t_prog_list	*nav;
  int		cycles;
  int		prog_count;

  prog_count = cw_get_prog_count();
  while (prog_count)
    {
      nav = g_prog_list;
      while (nav != NULL)
	{
	  if (nav->active && !cw_try_run_instr(nav->prog))
	    {
	      prog_count = prog_count - 1;
	      nav->active = 0;
	    }
	  nav = nav->next;
	}
    }
}

int		main(int argc, char **argv)
{
  if (argc > 1 && argv)
    {
      if (cw_init_memory())
	{
	  cw_get_program_list(argc, argv);
	  begin_corewar();
	  /* DEBUG# */
	  cw_dump_memory(g_memory, MEM_SIZE);
	  /* #DEBUG */
	  cw_free_memory();
	  return (EXIT_SUCCESS);
	}
    }
  else
    my_puterr("Too few arguments.\n");
  return (EXIT_FAILURE);
}

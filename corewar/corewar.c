/*
** dasm.c for corewar in ./dasm
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec  5 14:03:15 2012 ivan ignatiev
** Last update Wed Dec 12 17:30:05 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

void		begin_corewar()
{
  t_prog_list	*nav;
  int		prog_count;
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
  while (prog_count)
    {
      nav = g_prog_list;
      while (nav != NULL)
	{
	  if (nav->active && !cw_try_run_instr(nav->prog, instrs))
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

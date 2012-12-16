/*
** live.c for corewar in ./corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec 12 16:17:00 2012 ivan ignatiev
** Last update Sun Dec 16 16:02:24 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

static void	cw_set_last_live(t_program *prog)
{
  if (g_last_live)
    free(g_last_live);
  if ((g_last_live = (t_program*)malloc(sizeof(t_program))) != NULL)
    {
      my_memncpy(g_last_live, prog,
		 sizeof(t_program), sizeof(t_program));
    }
}

static void	cw_save_live(t_long_type prog_num)
{
  t_prog_list	*nav;

  nav = g_prog_list;
  while (nav != NULL)
    {
      if (nav->prog->reg[0] == prog_num)
	{
	  cw_set_last_live(nav->prog);
	  nav->prog->last_live_cycle = nav->prog->cycle;
	  my_fprintf(OSTD, "player %l(%s) is alive\n", prog_num,
		 nav->prog->header.prog_name);
	}
      nav = nav->next;
    }
}

int		cw_instr_live(t_program *prog, op_t *instr, t_prog_args *args)
{
  if (prog->instr.wait)
    {
      args[0].size = 4;
      return (cw_get_args(prog, instr, args));
    }
  prog->live = 1;
  cw_save_live(args[0].value);
  return (1);
}


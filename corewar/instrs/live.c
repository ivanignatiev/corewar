/*
** live.c for corewar in ./corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec 12 16:17:00 2012 ivan ignatiev
** Last update Thu Dec 13 14:41:05 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

int		cw_save_live(t_long_type prog_num)
{
  t_prog_list	*nav;

  nav = g_prog_list;
  while (nav != NULL)
    {
      if (nav->prog->prog_num == prog_num)
	{
	  g_last_live = nav->prog;
	  nav->prog->last_live_cycle = g_cycles;
	  printf("player %li(%s) is alive\n", prog_num, nav->prog->header.prog_name);
	}
      nav = nav->next;
    }
}

int		cw_instr_live(t_program *prog, op_t *instr, t_prog_args *args)
{
  args[0].size = 4;
  cw_get_args(prog, instr, args);
  cw_show_args(instr, args, prog);
  cw_save_live(args[0].value);
  return (1);
}


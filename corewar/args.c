/*
** args.c for corewar in ./corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Dec 15 00:34:42 2012 ivan ignatiev
** Last update Sat Dec 15 05:37:36 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"op.h"
#include	"cwlib.h"
#include	"corewar.h"

static void	cw_old_style_init()
{
  op_tab[0].nbr_cycles = 5;
  op_tab[1].nbr_cycles = 5;
  op_tab[2].nbr_cycles = 2;
  op_tab[3].nbr_cycles = 10;
  op_tab[4].nbr_cycles = 6;
  op_tab[5].nbr_cycles = 6;
  op_tab[6].nbr_cycles = 6;
  op_tab[7].nbr_cycles = 6;
  op_tab[8].nbr_cycles = 10;
  op_tab[9].nbr_cycles = 25;
  op_tab[10].nbr_cycles = 2;
  op_tab[11].nbr_cycles = 600;
  op_tab[12].nbr_cycles = 10;
  op_tab[13].nbr_cycles = 50;
  op_tab[14].nbr_cycles = 1000;
  op_tab[15].nbr_cycles = 2;
}

static int	cw_is_prog_exist(t_long_type prog_num)
{
  t_prog_list	*nav;

  nav = g_prog_list;
  while (nav != NULL)
    {
      if (nav->prog->prog_num == prog_num)
	return (1);
      nav = nav->next;
    }
  return (0);
}

static int	cw_try_add_cor(char *filename, t_long_type *prog_num,
			       t_long_type *start_addr)
{
  if (*prog_num < 0)
    *prog_num = cw_get_prog_number();
  else if (cw_is_prog_exist(*prog_num))
    {
      printf("prog number %li already used\n", *prog_num);
      return (0);
    }
  if (!cw_add_prog_to_list(filename, *start_addr, *prog_num))
    {
      printf("corewar: problem with program loading\n");
      return (0);
    }
  *prog_num = -1;
  return (1);
}

static int	cw_options(char *option)
{
  if (my_strcmp(option, "-aff_shell") == 0)
    {
      g_options = g_options | O_AFF_SHELL;
      return (1);
    }
  else if (my_strcmp(option, "-die_msg") == 0)
    {
      g_options = g_options | O_DIE_MSG;
      return (1);
    }
  else if (my_strcmp(option, "-old_style") == 0)
    {
      g_options = g_options | O_OLD_STYLE;
      cw_old_style_init();
      return (1);
    }
  return (0);
}

int		cw_get_program_list(int argc, char **argv)
{
  int		i;
  t_long_type	prog_num;
  t_long_type	start_addr;

  i = 1;
  prog_num = -1;
  start_addr = -1;
  while (i < argc)
    {
      if (my_strcmp(argv[i], "-dump") == 0 && (i + 1) < argc)
	g_cycle_to_dump = my_getnbr(argv[i + 1]);
      else if (my_strcmp(argv[i], "-n") == 0 && (i + 1) < argc)
	prog_num = my_getnbr(argv[i + 1]);
      else if (my_strcmp(argv[i], "-a") == 0 && (i + 1) < argc)
	start_addr = my_getnbr(argv[i + 1]);
      else
	{
	  if (!cw_options(argv[i]))
	    if (!cw_try_add_cor(argv[i], &prog_num, &start_addr))
	      return (0);
	  i = i - 1;
	}
      i = i + 2;
    }
  return (1);
}

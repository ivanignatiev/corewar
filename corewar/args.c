/*
** args.c for corewar in ./corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Dec 15 00:34:42 2012 ivan ignatiev
** Last update Sat Dec 15 00:51:44 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"op.h"
#include	"cwlib.h"
#include	"corewar.h"

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
	  if (!cw_try_add_cor(argv[i], &prog_num, &start_addr))
	    return (0);
	  i = i - 1;
	}
      i = i + 2;
    }
  return (1);
}

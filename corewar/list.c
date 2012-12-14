/*
** list.c for corewar in /home/ignati_i//projects/corewar/corewar-2016ed-2015s-2017si-liu_q/dasm
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 11:47:52 2012 ivan ignatiev
** Last update Fri Dec 14 16:24:23 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"op.h"
#include	"corewar.h"

/*
** Return count of programs in list
*/
int		cw_is_prog_exist(t_long_type prog_num)
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

/*
** Build programm list from COR-files passed from command args
*/
int		cw_get_program_list(int argc, char **argv)
{
  int		i;
  t_long_type	prog_num;
  t_long_type	start_addr;

  g_cycle_to_dump = -1;
  g_prog_list = NULL;
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
	  if (prog_num < 0)
	    prog_num = cw_get_prog_number();
	  else if (cw_is_prog_exist(prog_num))
	    {
	      printf("prog number %li already used\n", prog_num);
	      return (0);
	    }
	  cw_add_prog_to_list(argv[i], start_addr, prog_num);
	  prog_num = -1;
	  i = i - 1;
	}
      i = i + 2;
    }
  return (1);
}

/*
** Add programm to programm list
*/
int		cw_add_prog_to_list(char *filename,
				    int start_addr,
				    int prog_num)
{
  t_prog_list	*prog_elem;
  t_prog_list	*nav;

  if ((prog_elem = (t_prog_list*)malloc(sizeof(t_prog_list))) != NULL)
    {
      if ((prog_elem->prog = cw_load_program(filename, start_addr, prog_num)) != NULL)
	{
	  prog_elem->next = NULL;
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
      else
	free(prog_elem);
    }
  return (0);
}

/*
** Remove programm from program list
*/
void		cw_remove_program(t_program *prog)
{
  t_prog_list	*nav;
  t_prog_list	*tmp;

  nav = g_prog_list;
  if (g_prog_list->prog == prog)
    {
      tmp = g_prog_list;
      g_prog_list = tmp->next;
      free(tmp->prog);
      free(tmp);
    }
  else
    while (nav->next != NULL)
      {
	if (nav->next->prog == prog)
	  {
	    tmp = nav->next;
	    nav->next = tmp->next;
	    free(tmp->prog);
	    free(tmp);
	  }
	nav = nav->next;
      }
}

/*
** Return count of programs in list
*/
int		cw_get_prog_count()
{
  t_prog_list	*nav;
  int		i;

  i = 0;
  nav = g_prog_list;
  while (nav != NULL)
    {
      i = i + 1;
      nav = nav->next;
    }
  return (i);
}

/*
** Return count of programs in list
*/
t_long_type	cw_get_prog_number()
{
  t_prog_list	*nav;
  t_long_type	max;

  max = -1;
  nav = g_prog_list;
  if (nav)
    max = nav->prog->prog_num;
  while (nav != NULL)
    {
      if (nav->prog->prog_num > max)
	max = nav->prog->prog_num;
      nav = nav->next;
    }
  return (max + 1);
}


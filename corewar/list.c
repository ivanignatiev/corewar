/*
** list.c for corewar in /home/ignati_i//projects/corewar/corewar-2016ed-2015s-2017si-liu_q/dasm
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 11:47:52 2012 ivan ignatiev
** Last update Thu Dec 13 16:10:45 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"op.h"
#include	"corewar.h"

/*
** Build programm list from COR-files passed from command args
** TODO: parse agrg -dump [cycle_number] / -n [prog_num] / -a [start_addr]
*/
void		cw_get_program_list(int argc, char **argv)
{
  int		i;

  g_prog_list = NULL;
  i = 1;
  while (i < argc)
    {
      cw_add_prog_to_list(argv[i], -1, cw_get_prog_number());
      i = i + 1;
    }
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
	  return (prog_num + 1);
	}
      else
	free(prog_elem);
    }
  return (prog_num);
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

  max = 0;
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

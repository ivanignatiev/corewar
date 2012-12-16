/*
** list.c for corewar in ./corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 11:47:52 2012 ivan ignatiev
** Last update Sat Dec 15 13:04:36 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"op.h"
#include	"corewar.h"

int		cw_add_prog_to_list(char *filename,
				    int start_addr,
				    int prog_num)
{
  t_prog_list	*prog_elem;
  t_prog_list	*nav;

  if ((prog_elem = (t_prog_list*)malloc(sizeof(t_prog_list))) != NULL)
    {
      if ((prog_elem->prog = cw_load_program(filename,
					     start_addr, prog_num)) != NULL)
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


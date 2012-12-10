/*
** list.c for corewar in /home/ignati_i//projects/corewar/corewar-2016ed-2015s-2017si-liu_q/dasm
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 11:47:52 2012 ivan ignatiev
** Last update Mon Dec 10 11:59:51 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"op.h"
#include	"dasm.h"

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

void		cw_get_program_list(int argc, char **argv)
{
  int		i;
  int		prog_num;

  g_prog_list = NULL;
  i = 1;
  prog_num = 1;
  while (i < argc)
    {
      prog_num = cw_add_prog_to_list(argv[i], -1, prog_num);
      i = i + 1;
    }
}

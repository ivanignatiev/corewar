/*
** list_clear.c for corewar in ./corewar
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Dec 15 13:04:48 2012 ivan ignatiev
** Last update Sat Dec 15 13:23:55 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"op.h"
#include	"corewar.h"

static void	cw_free_program(t_prog_list *tmp)
{
  if (tmp->prog->instr.args != NULL)
    free(tmp->prog->instr.args);
  if (tmp->prog != NULL)
    free(tmp->prog);
  if (tmp != NULL)
    free(tmp);
}

void		cw_clear_list()
{
  t_prog_list	*nav;
  t_prog_list	*tmp;

  nav = g_prog_list;
  while (nav != NULL)
    {
      tmp = nav;
      nav = nav->next;
      cw_free_program(tmp);
    }
  g_prog_list = NULL;
}

void		cw_remove_program(t_program *prog)
{
  t_prog_list	*nav;
  t_prog_list	*tmp;

  if ((nav = g_prog_list) == NULL)
    return ;
  while (nav->next != NULL)
    {
      if (nav->next->prog->prog_num == prog->prog_num)
	{
	  tmp = nav->next;
	  nav->next = tmp->next;
	  cw_free_program(tmp);
	  return ;
	}
      else
	nav = nav->next;
    }
  if (g_prog_list->prog->prog_num == prog->prog_num)
    {
      tmp = g_prog_list;
      g_prog_list = tmp->next;
      cw_free_program(tmp);
    }
}

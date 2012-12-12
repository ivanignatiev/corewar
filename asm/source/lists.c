/*
** lists.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Mon Dec 10 16:24:42 2012 arthur sfez
** Last update Wed Dec 12 12:03:09 2012 arthur sfez
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"asm.h"

void		my_lab_to_list(labels_t **list, char *s, int count)
{
  labels_t	*elem;
  labels_t	*tmp;

  elem = malloc(sizeof(*elem));
  if (!elem)
    return ;
  elem->s = strndup(s, my_strlen(s) - 1);
  elem->adr = count;
  elem->next = NULL;
  if (*list == NULL)
    *list = elem;
  else
    {
      tmp = *list;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = elem;
    }
}

void		my_init_arg_tab(args_t **args)
{
  args = malloc(sizeof(*args) * (MAX_ARGS_NUMBER));
  if (args == NULL)
    exit(EXIT_FAILURE);
}

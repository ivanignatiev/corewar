/*
** lists.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Mon Dec 10 16:24:42 2012 arthur sfez
** Last update Thu Dec 13 15:47:40 2012 arthur sfez
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"asm.h"

void		my_lab_to_list(labels_t **list, char *s)
{
  labels_t	*elem;
  labels_t	*tmp;

  elem = malloc(sizeof(*elem));
  if (!elem)
    return ;
  if (s[my_strlen(s) - 2] == LABEL_CHAR)
    elem->s = strndup(s, my_strlen(s) - 1);
  else
    elem->s = strdup(s);
  elem->adr = g_data.count;
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

void		my_free_lists(labels_t **list1, labels_t **list2)
{
  labels_t	*tmp;

  while (*list1 != NULL)
    {
      tmp = *list1;
      *list1 = (*list1)->next;
      free(tmp->s);
      free(tmp);
    }
  while (*list2 != NULL)
    {
      tmp = *list2;      
      *list2 = (*list2)->next;
      free(tmp);
    }
}

void		my_init_arg_tab(args_t **args)
{
  int		i;

  i = 0;
  args = malloc(sizeof(*args) * (MAX_ARGS_NUMBER));
  if (args == NULL)
    exit(EXIT_FAILURE);
}

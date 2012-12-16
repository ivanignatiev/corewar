/*
** lists.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Mon Dec 10 16:24:42 2012 arthur sfez
** Last update Sun Dec 16 19:11:13 2012 ivan ignatiev
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"asm.h"
#include	"cwlib.h"

static labels_t	*my_init_list(int *size, int *val, args_t *arg)
{
  labels_t	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (NULL);
  *size = 0;
  *val = 0;
  if (arg != NULL)
    {
      *size = arg->size;
      *val = arg->val;
    }
  elem->adr = g_data.count;
  return (elem);
}

void		my_lab_to_list_ops(labels_t **list, char *s,
				   unsigned char n_ins, args_t *arg)
{
  int		size;
  int		val;
  labels_t	*elem;
  labels_t	*tmp;

  if ((elem = my_init_list(&size, &val, arg)) == NULL)
    return ;
  if (s[my_strlen(s) - 1] == LABEL_CHAR)
    elem->s = my_strndup(s, my_strlen(s) - 1);
  else
    elem->s = my_strdup(s);
  elem->adr_a = g_data.count + g_data.n[ARG_C] + 1 + my_enc_exists(n_ins);
  elem->line = g_data.nb_line;
  elem->size = size;
  elem->op = val;
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

void		my_lab_to_list(labels_t **list, char *s,
			       unsigned char n_ins, int size)
{
  labels_t	*elem;
  labels_t	*tmp;

  elem = malloc(sizeof(*elem));
  if (!elem)
    return ;
  if (s[my_strlen(s) - 1] == LABEL_CHAR)
    elem->s = my_strndup(s, my_strlen(s) - 1);
  else
    elem->s = my_strdup(s);
  elem->adr_a = g_data.count + g_data.n[ARG_C] + 1 + my_enc_exists(n_ins);
  elem->adr = g_data.count;
  elem->line = g_data.nb_line;
  elem->size = size;
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
      free(tmp->s);
      free(tmp);
    }
}

void		my_init_arg_tab(args_t **args)
{
  args = malloc(sizeof(*args) * (MAX_ARGS_NUMBER));
  if (args == NULL)
    exit(EXIT_FAILURE);
}

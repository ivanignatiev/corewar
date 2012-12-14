/*
** check_indirect.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Thu Dec 13 11:51:36 2012 arthur sfez
** Last update Fri Dec 14 18:01:42 2012 arthur sfez
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"asm.h"
#include	"cwlib.h"

int		my_check_indirect(char *s, labels_t **labels, int n_ins, int size)
{
  if (is_label_call(s))
    {
      my_lab_to_list(labels, s + 1, n_ins, size);
      return (0);
    }
  else
    return (my_getnbr(s));
}

args_t		*my_check_add_i(char *arg_val, int n_ins,
				int *encbyte, labels_t **labels)
{
  args_t	*arg;

  arg = malloc(sizeof(*arg));
  if (arg == NULL)
    {
      my_puterr("Malloc failed\n");
      return (NULL);
    }
  if (op_tab[n_ins - 1].type[g_data.n[ARG]] & T_IND)
    {
      *encbyte |= (1 << (6 - (g_data.n[ARG] * 2)));
      *encbyte |= (1 << (7 - (g_data.n[ARG] * 2)));
      arg->size = my_retrieve_size(n_ins, g_data.n[ARG], 2);
      arg->val = my_check_indirect(arg_val, labels, n_ins, arg->size);
      g_data.n[ARG_C] += arg->size;
    }
  else
    {
      my_err_msg(g_data.s, BAD_ARGUMENT, g_data.n[IND]);
      return (NULL);
    }
  return (arg);
}

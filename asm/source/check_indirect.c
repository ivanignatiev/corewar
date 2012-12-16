/*
** check_indirect.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Thu Dec 13 11:51:36 2012 arthur sfez
** Last update Sun Dec 16 17:32:29 2012 arthur sfez
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"asm.h"
#include	"cwlib.h"

int		my_check_indirect(char *s, labels_t **labels,
				  int n_ins, args_t *arg)
{
  if (is_label_call(s))
    {
      my_lab_to_list_ops(labels, s + 1, n_ins, arg);
      return (0);
    }
  else
    return (my_getnbr(s));
}

args_t		*my_check_add_i(char *arg_val, int n_ins,
				unsigned char *encbyte, labels_t **labels)
{
  int		ret;
  args_t	*arg;
  char		*new_av;

  arg = malloc(sizeof(*arg));
  if (arg == NULL)
    return (NULL);
  if ((op_tab[n_ins - 1].type[g_data.n[ARG]] & T_IND) == 0)
    {
      my_err_msg(g_data.s, BAD_ARGUMENT, g_data.n[IND]);
      return (NULL);
    }
  arg->val = 0;
  *encbyte |= (1 << (6 - (g_data.n[ARG] * 2)));
  *encbyte |= (1 << (7 - (g_data.n[ARG] * 2)));
  arg->size = my_retrieve_size(n_ins, g_data.n[ARG], 2);
  if ((ret = my_check_operators(arg_val)) == -1)
    return (NULL);
  if (ret > 0)
    new_av = my_init_val(arg_val, ret, arg);
  else
    new_av = arg_val;
  arg->val += my_check_indirect(new_av, labels, n_ins, arg);
  g_data.n[ARG_C] += arg->size;
  return (arg);
}

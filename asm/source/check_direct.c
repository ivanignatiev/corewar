/*
** check_direct.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Wed Dec 12 15:57:05 2012 arthur sfez
** Last update Sun Dec 16 16:21:06 2012 arthur sfez
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"op.h"
#include	"asm.h"
#include	"cwlib.h"

int		my_check_direct(char *s, labels_t **labels, int n_ins, args_t *arg)
{
  if (is_label_call(s + 1))
    {
      my_lab_to_list_ops(labels, s + 2, n_ins, arg);
      return (0);
    }
  else
    return (my_getnbr(s + 1));
}

args_t		*my_check_add_d(char *arg_val, int n_ins,
				int *encbyte, labels_t **labels)
{
  int		ret;
  char		*new_av;
  args_t	*arg;

  if ((arg = malloc(sizeof(*arg))) == NULL)
    return (NULL);

  if ((op_tab[n_ins - 1].type[g_data.n[ARG]] & T_DIR) == 0)
    {
      my_err_msg(g_data.s, BAD_ARGUMENT, g_data.n[IND]);
      return (NULL);
    }
  arg->val = 0;
  *encbyte |= (0 << (6 - (g_data.n[ARG] * 2)));
  *encbyte |= (1 << (7 - (g_data.n[ARG] * 2)));
  arg->size = my_retrieve_size(n_ins, g_data.n[ARG], 4);
  if ((ret = my_check_operators(arg_val)) == -1)
    return (NULL);
  if (ret > 0)
    new_av = my_init_val(arg_val, ret, arg);
  else
    new_av = arg_val;
  arg->val += my_check_direct(new_av, labels, n_ins, arg);
  g_data.n[ARG_C] += arg->size;
  return (arg);
}

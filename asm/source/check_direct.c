/*
** check_direct.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Wed Dec 12 15:57:05 2012 arthur sfez
** Last update Thu Dec 13 17:13:15 2012 arthur sfez
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"op.h"
#include	"asm.h"

int		my_check_direct(char *s, labels_t **labels)
{
  if (is_label_call(s + 1))
    {
      my_lab_to_list(labels, s + 2);
      return (0);
    }
  else
    return (my_getnbr(s + 1));
}

args_t		*my_check_add_d(char *arg_val, int n_ins, int *encbyte, labels_t **labels)
{
  args_t	*arg;
  int		d_val;

  arg = malloc(sizeof(*arg));
  if (arg == NULL)
    {
      my_puterr("Malloc failed\n");
      return (NULL);
    }
  if (op_tab[n_ins - 1].type[g_data.n[ARG]] & T_DIR)
    {
      *encbyte |= (0 << (6 - (g_data.n[ARG] * 2)));
      *encbyte |= (1 << (7 - (g_data.n[ARG] * 2)));
      arg->val = my_check_direct(arg_val, labels);
      arg->size = my_retrieve_size(n_ins, g_data.n[ARG], 4);
    }
  else
    {
      my_err_msg(g_data.s, BAD_ARGUMENT, g_data.n[IND]);
      return (NULL);
    }
  return (arg);
}

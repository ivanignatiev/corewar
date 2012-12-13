/*
** check_args.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Tue Dec 11 18:54:07 2012 arthur sfez
** Last update Thu Dec 13 16:58:10 2012 arthur sfez
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"asm.h"

int		my_check_register(char *s)
{
  int		res;
  char		*val;

  val = malloc(sizeof(*val) * (my_strlen(s)));
  if (val == NULL)
    {
      my_puterr("Malloc failed\n");
      return (-1);
    }
  val[my_strlen(s) - 1] = 0;
  my_strcpy(val, s + 1);
  if (!my_check_val(val))
    return (my_err_msg(g_data.s, REG_VALUE, g_data.n[IND]));
  res = my_getnbr(val);
  free(val);
  if (res < 1 || res > REG_NUMBER)
    return (my_err_msg(g_data.s, REG_VALUE, g_data.n[IND]));
  return (res);
}

args_t		*my_check_add_r(char *arg_val, int n_ins, int *encbyte)
{
  args_t	*arg;
  int		r_val;

  arg = malloc(sizeof(*arg));
  if (arg == NULL)
    {
      my_puterr("Malloc failed\n");
      return (NULL);
    }
  if ((r_val = my_check_register(arg_val)) == -1)
    return (NULL);
  if (op_tab[n_ins - 1].type[g_data.n[ARG]] & T_REG)
    {
      *encbyte |= (01 << (6 - (g_data.n[ARG] * 2)));
      arg->val = r_val;
      arg->size = my_retrieve_size(n_ins, g_data.n[ARG], 1);
    }
  else
    {
      my_err_msg(g_data.s, BAD_ARGUMENT, g_data.n[IND]);
      return (NULL);
    }
  return (arg);
}

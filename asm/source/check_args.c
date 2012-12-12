/*
** check_args.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Tue Dec 11 18:54:07 2012 arthur sfez
** Last update Wed Dec 12 16:16:32 2012 arthur sfez
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
    return (0);
  val[my_strlen(s) - 1] = 0;
  my_strcpy(val, s + 1);
  if (!my_check_val(val))
    return (0);
  res = my_getnbr(val);
  free(val);
  if (res < 1 || res > REG_NUMBER)
    return (0);
  return (res);
}

args_t		*my_check_add_r(char *arg_val, int n, int n_ins, int *encbyte)
{
  args_t	*arg;
  int		r_val;

  arg = malloc(sizeof(*arg));
  if (arg == NULL)
    exit(EXIT_FAILURE);
  r_val = my_check_register(arg_val);
  if (op_tab[n_ins - 1].type[n] & T_REG)
    {
      *encbyte |= (01 << (6 - (n * 2)));
      arg->val = r_val;
      arg->size = my_retrieve_size(n_ins, n, 1);
    }
  else
    exit(EXIT_FAILURE); /* GALERE... */
  return (arg);
}

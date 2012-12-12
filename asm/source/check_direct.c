/*
** check_direct.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Wed Dec 12 15:57:05 2012 arthur sfez
** Last update Wed Dec 12 16:30:51 2012 arthur sfez
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"op.h"
#include	"asm.h"

int		my_check_direct(char *s)
{
  int		res;

  if (*s == LABEL_CHAR)
    {
      
    }
}

args_t		*my_check_add_d(char *arg_val, int n, int n_ins, int *encbyte)
{
  args_t	*arg;
  int		d_val;

  arg = malloc(sizeof(*arg));
  if (arg == NULL)
    exit(EXIT_FAILURE);
  if (op_tab[n_ins - 1].type[n] & T_DIR)
    {
      *encbyte |= (10 << (6 - (n * 2)));
      my_check_direct(arg_val);
      arg->size = my_retrieve_size(n_ins, n, 4);
    }
}

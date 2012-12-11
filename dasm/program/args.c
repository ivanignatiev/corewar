/*
** argc.c for corewar in ./dasm/program
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 13:58:06 2012 ivan ignatiev
** Last update Tue Dec 11 15:35:15 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"cwlib.h"
#include	"op.h"
#include	"dasm.h"

int		cw_get_args_count(unsigned char order_byte)
{
  unsigned char	c;
  int		n;
  int		len;

  n = 0;
  len = 0;
  while (n <= 6)
    {
      c = order_byte << n;
      c >>= 6;
      if (c > 0)
        len++;
      else
	return (len);
	n += 2;
    }
  return (len);
}

void		cw_args_size(t_prog_args *args, int nbr)
{
  int		i;

  i = 0;
  while (i < nbr)
    {
      args[i].size = 0;
      if (args[i].type == T_REG)
	args[i].size = 1;
      else if (args[i].type == T_DIR)
	args[i].size = DIR_SIZE;
      else if (args[i].type == T_IND)
	args[i].size = IND_SIZE;
      i = i + 1;
    }
}

t_prog_args	*cw_args_order(op_t *instr,
			       unsigned char order_byte)
{
  unsigned char	c;
  int		n;
  t_prog_args	*args;

  n = 0;
  if (cw_get_args_count(order_byte) != instr->nbr_args)
    return (NULL);
  if ((args = (t_prog_args*)malloc(sizeof(t_prog_args) * instr->nbr_args)) == NULL)
    return (NULL);
  while (n < instr->nbr_args * 2)
    {
      c = order_byte << n;
      c >>= 6;
      if ((c == 1) && (instr->type[n / 2] & T_REG))
	args[n / 2].type = T_REG;
      else if ((c == 2) && (instr->type[n / 2] & T_DIR))
	args[n / 2].type = T_DIR;
      else if ((c == 3) && (instr->type[n / 2] & T_IND))
	args[n / 2].type = T_IND;
      else
	{
	  free(args);
	  return (NULL);
	}
      n += 2;
    }
  cw_args_size(args, instr->nbr_args);
  return (args);
}

int		cw_get_args(t_program *prog,
			    op_t *instr,
			    t_prog_args *args)
{
  int		i;
  int		size;

  i = 0;
  size = 0;
  while (i < instr->nbr_args)
    {
      if (*(prog->memory_start + prog->pc + 1) >> 7)
	args[i].value = -1;
      else
	args[i].value = 0;
      my_memncpy(&args[i].value, (prog->memory_start + prog->pc + 1), args[i].size);
      my_conv_to_platform(&args[i].value, args[i].size);
      prog->pc += args[i].size;
      i = i + 1;
    }
  return (1);
}

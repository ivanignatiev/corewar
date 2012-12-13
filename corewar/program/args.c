/*
** argc.c for corewar in ./dasm/program
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 13:58:06 2012 ivan ignatiev
** Last update Thu Dec 13 16:58:48 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

int		cw_get_args_count(unsigned char order_byte)
{
  unsigned char	c;
  int		n;
  int		len;

  n = 0;
  len = 0;
  while (n <= 6)
    {
      c = (unsigned char)(order_byte << n) >> 6;
      if (c > 0)
        len++;
      else
	return (len);
	n += 2;
    }
  return (len);
}

int		cw_args_size(t_prog_args *args, int nbr)
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
      if (args[i].size > sizeof(t_long_type))
	return (0);
      i = i + 1;
    }
  return (1);
}

args_type_t	cw_args_get_type(unsigned char ctrl_pair, op_t *instr, int arg_num)
{
  if ((ctrl_pair == 1) && (instr->type[arg_num] & T_REG))
    return (T_REG);
  else if ((ctrl_pair == 2) && (instr->type[arg_num] & T_DIR))
    return (T_DIR);
  else if ((ctrl_pair == 3) && (instr->type[arg_num] & T_IND))
    return (T_IND);
  return (0);
}

t_prog_args	*cw_args_order(op_t *instr,
			       unsigned char order_byte)
{
  unsigned char	c;
  int		n;
  t_prog_args	*args;

  if (cw_get_args_count(order_byte) != instr->nbr_args)
    return (NULL);
  if ((args = (t_prog_args*)malloc(sizeof(t_prog_args) * instr->nbr_args)) == NULL)
    return (NULL);
  n = 0;
  while (n < (instr->nbr_args * 2))
    {
      c = (unsigned char)(order_byte << n) >> 6;
      if (!(args[n / 2].type = cw_args_get_type(c, instr, n / 2)))
	{
	  free(args);
	  return (NULL);
	}
      n += 2;
    }
  if (!cw_args_size(args, instr->nbr_args))
    {
      free(args);
      return (NULL);
    }
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
      if (g_memory[(prog->pc + 1) % MEM_SIZE] >> 7)
	args[i].value = -1;
      else
	args[i].value = 0;
      my_memncpy(&args[i].value, (g_memory + (prog->pc + 1) % MEM_SIZE),
		 args[i].size, sizeof(args[i].value));
      my_conv_to_platform(&args[i].value, sizeof(args[i].value));
      if (args[i].type == T_REG && args[i].value > REG_NUMBER && args[i].value < 1)
	return (0);
      prog->pc = (prog->pc + args[i].size) % MEM_SIZE;
      i = i + 1;
    }
  return (1);
}

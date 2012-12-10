/*
** argc.c for corewar in ./dasm/program
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 13:58:06 2012 ivan ignatiev
** Last update Mon Dec 10 19:11:31 2012 qiuyan liu
*/

#include	"cwlib.h"
#include	"op.h"
#include	"dasm.h"

/*
 *
 *  Array size: instr->nbr_args
 *  IND_SIZE 11
 *  1 01
 *  DIR_SIZE 10
 * order_byte = 11110100b
 * return ( Array [0] => IND_SIZE, [1] => IND_SIZE [2] => REG_SIZE)
 */

int		get_array_len(unsigned char order_byte)
{
  char		c;
  int		n;
  int		len;

  n = 0;
  len = 0;
  while (n <= 6)
    {
      c = order_byte;
      c <<= n;
      c >>= 6;
      if (c > 0)
        len++;
      else
	return (len);
	n += 2;
    }
}

int		is_possible_type(args_type_t *type, int t_type)
{
  int		n;

  n = 0;
  while (n < MAX_ARGS_NUMBER)
    {
      if (type[n] == t_type)
	return (1);
      n++;
    }
  return (0);
}

unsigned char	*args_order(op_t *instr, unsigned char order_byte)
{
  char		c;
  int		n;
  int		len;
  char		*Array;

  n = 0;
  len = get_array_len(order_byte);
  if (len == 0)
    return (NULL);
  else
    Array = malloc(len * sizeof(unsigned char));
  while (n <= 6)
    {
      c = order_byte;
      c <<= n;
      c >>= 6;
      if ((c == 1) && is_possible_type(instr->type, T_REG) && instr->nbr_args >= n / 2 + 1)
	Array[n / 2] = T_REG;
      else if ((c == 2) && is_possible_type(instr->type, T_DIR) && instr->nbr_args >= n / 2 + 1)
	Array[n / 2] = T_DIR;
      else if ((c == 3) && is_possible_type(instr->type, T_IND) && instr->nbr_args >= n / 2 + 1)
	Array[n / 2] = T_IND;
      else 
	return (NULL);
      n += 2;
    }

}

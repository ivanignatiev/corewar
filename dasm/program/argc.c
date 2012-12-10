/*
** argc.c for corewar in ./dasm/program
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 13:58:06 2012 ivan ignatiev
** Last update Mon Dec 10 14:43:04 2012 ivan ignatiev
*/

#include	"cwlib.h"
#include	"op.h"
#include	"dasm.h"

/*
 *
 *  Array size: instr->nbr_args
 *  IND_SIZE 11
 *  REG_SIZE 01
 *  DIR_SIZE 10
 * order_byte = 11110100b
 * return ( Array [0] => IND_SIZE, [1] => IND_SIZE [2] => REG_SIZE)
 */
unsigned char	*args_order(op_t *instr, char *order_byte)
{
  
}

void		args_skip(op_t *instr, t_program *prog)
{
  unsigned char order;

  if (instr->nbr_args == 1)
    {
    }
  else
    {
      order = prog->memory_start[prog->pc + 1];
      prog->pc = prog->pc + 2;
    }
}

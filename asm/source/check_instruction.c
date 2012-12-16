/*
** is_instruction.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Sat Dec  8 17:32:21 2012 arthur sfez
** Last update Sun Dec 16 17:46:16 2012 arthur sfez
*/

#include	"op.h"
#include	"asm.h"
#include	"cwlib.h"

int		is_instruction(char *s)
{
  int		i;

  i = 0;
  while (op_tab[i].mnemonique != 0)
    {
      if (my_strcmp(op_tab[i].mnemonique, s) == 0)
	return (1);
      i++;
    }
  return (0);
}

unsigned char	my_get_ins_code(line_t one_line, int i)
{
  int		n;

  n = 0;
  while (op_tab[n].mnemonique != 0)
    {
      if (my_strcmp(op_tab[n].mnemonique, one_line.arr[i]) == 0)
	return (op_tab[n].code);
      n++;
    }
  my_err_msg(one_line.s, UNKNOWN_INS, i);
  return (0);
}

int		my_enc_exists(unsigned char c)
{
  if (c == 1 || c == 9 || c == 12 || c == 15)
    return (0);
  return (1);
}

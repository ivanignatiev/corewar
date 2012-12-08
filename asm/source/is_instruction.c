/*
** is_instruction.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Sat Dec  8 17:32:21 2012 arthur sfez
** Last update Sat Dec  8 18:20:26 2012 arthur sfez
*/

#include "op.h"

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

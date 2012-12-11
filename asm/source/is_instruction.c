/*
** is_instruction.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Sat Dec  8 17:32:21 2012 arthur sfez
** Last update Tue Dec 11 14:48:48 2012 arthur sfez
*/

#include	"op.h"
#include	"asm.h"

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

int		my_get_ins_code(char *ins, char *s, int i)
{
  int		n;

  n = 0;
  while (op_tab[n].mnemonique != 0)
    {
      if (my_strcmp(op_tab[n].mnemonique, ins) == 0)
	return (my_getnbr(op_tab[n].code));
      n++;
    }
  /* my_err_msg + return (-1); */
  return (-1);
}

int		is_instruction_hexa(char *arr, int i, char *s, int lb_def)
{
  int		n;

  n = 0;
  while (op_tab[n].mnemonique != 0)
    {
      if (my_strcmp(op_tab[n].mnemonique, s) == 0)
	{
	  if ((i == 1 && lb_def == 0) || i > 1)
	    my_err_msg(s, UNKNOWN_ARG, my_get_line_pos(s, i));
	  else
	    return (1);
	}
      n++;
    }
  return (0);
}

char		*my_ins_hexa(char *s)
{
  int		i;

  i = 0;
  while (op_tab[i].mnemonique != 0)
    {
      if (my_strcmp(op_tab[i].mnemonique, s) == 0)
	return (&(op_tab[i].code));
      i++;
    }
}

/*
** check_register.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Wed Dec 12 16:13:10 2012 arthur sfez
** Last update Fri Dec 14 18:50:29 2012 arthur sfez
*/

#include	"op.h"

int		my_check_val(char *s)
{
  while (*s)
    {
      if (*s < '0' || *s > '9')
	return (0);
      s++;
    }
  return (1);
}

int		my_retrieve_size(int n_ins, int n, int t)
{
  if (n_ins == 1)
    return (4);
  if (n_ins == 9 || n_ins == 12 || n_ins == 15)
    return (IND_SIZE);
  if (n_ins == 10 && (n == 0 || n == 1))
    return (IND_SIZE);
  if ((n_ins == 11) && (n == 1 || n == 2))
    {
      if (t == 2 || t == 4)
	return (IND_SIZE);
    }
  return (t);
}

/*
** my_put_nbr.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/lib
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Fri Dec  7 11:46:32 2012 arthur sfez
** Last update Sat Dec 15 15:05:18 2012 ivan ignatiev
*/

#include "cwlib.h"

void		my_put_nbr(int n)
{
  if (n > 9)
    my_put_nbr(n / 10);
  my_putchar((n % 10) + 48);
}

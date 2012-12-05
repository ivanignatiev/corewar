/*
** my_put_nbr.c for nbr in /home/sfez_a//piscine/Jour_03
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Wed Oct  3 23:10:11 2012 arthur sfez
** Last update Fri Nov 16 16:36:44 2012 arthur sfez
*/

#include "../../include/my.h"

void		my_put_nbr(int nb)
{
  int		sign;

  sign = 1;
  if (nb <= -10 || nb >= 10)
    my_put_nbr((nb / 10));
  else if (nb < 0)
    my_putchar('-');
  if (nb < 0)
    sign = -1;
  my_putchar(sign * (nb % 10) + 48);
}

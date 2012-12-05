/*
** my_putnbr_base_rec.c for my_putnbr_base in /home/sfez_a//piscine_local/Jour_06/ex_15
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Tue Oct  9 22:09:28 2012 arthur sfez
** Last update Mon Nov 19 17:56:17 2012 arthur sfez
*/

#include "../../include/my.h"

int	my_putnbr_base(int nbr, char *base)
{
  int	base_size;
  int	sign;

  sign = 1;
  base_size = my_strlen(base);

  if (nbr <= -base_size || nbr >= base_size)
    my_putnbr_base((nbr / base_size), base);
  else if (nbr < 0)
    my_putchar('-');
  if (nbr < 0)
    sign = -1;
  my_putchar(base[sign * (nbr % base_size)]);
  return (nbr);
}

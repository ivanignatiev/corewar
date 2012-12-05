/*
** my_getnbr_base.c for my_getnbr_base in /home/sfez_a//piscine_local/Jour_06/ex_16
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Thu Oct 11 09:12:17 2012 arthur sfez
** Last update Sat Nov 24 17:00:47 2012 arthur sfez
*/

#include "../../include/my.h"

int	my_rmv_sign(char *str, int *nbr_ptr)
{
  int	i;
  int	sign;

  i = 0;
  sign = 1;
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
	sign = sign * (-1);
      i = i + 1;
    }
  *nbr_ptr = i;
  return (sign);
}

int	my_getval_str(char val, char *base)
{
  int	i;

  i = 0;
  while (base[i] != '\0')
    {
      if (val == base[i])
	  return (i);
      i = i + 1;
    }
  return (0);
}

int	my_check_base(char *base)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (base[i] != '\0')
    {
      if (base[i] == base[j] && i != j)
	  return (0);
      j = j + 1;
      if (j == my_strlen(base))
	{
	  i = i + 1;
	  j = 0;
	}
    }
  return (1);
}

int	my_check_str(char *str, char *base, int *nbr_ptr)
{
  int	i;
  int	j;
  int	check;

  i = *nbr_ptr;
  j = 0;
  check = 0;
  while (str[i] != '\0')
    {
      while (base[j] != '\0')
	{
	  if (str[i] == base[j])
	    check = 1;
	  j = j + 1;
	}
      if (check == 0)
	return (0);
      j = 0;
      i = i + 1;
      check = 0;
    }
  return (1);
}

int	my_getnbr_base(char *str, char *base)
{
  int	i;
  int	pwr;
  int	val;
  int	res;
  int	nbr_start;
  int	*nbr_ptr;
  int	sign;

  nbr_start = 0;
  nbr_ptr = &nbr_start;
  sign = my_rmv_sign(str, nbr_ptr);
  if (my_check_str(str, base, nbr_ptr) == 0 || my_check_base(base) == 0)
    return (0);
  i = *nbr_ptr;
  pwr = my_strlen(str) - 1 - i;
  res = 0;
  while (str[i] != '\0')
    {
      val = my_getval_str(str[i], base);
      res = res + val * (my_power_rec(my_strlen(base),  pwr));
      i = i + 1;
      pwr = pwr - 1;
    }
  return (res * sign);
}

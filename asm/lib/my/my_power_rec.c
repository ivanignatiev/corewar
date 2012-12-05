/*
** my_power_rec.c for power_rec in /home/sfez_a//piscine_local/Jour_05
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Fri Oct  5 14:34:24 2012 arthur sfez
** Last update Mon Nov 12 13:45:56 2012 arthur sfez
*/

int		my_power_rec(int nb, int power)
{
  if (power == 0)
    return (1);
  if (power < 0)
    return (0);
  if (power > 1)
    return (nb * my_power_rec(nb, power - 1));
  return (nb);
  if (power == 1)
    return (nb);
}

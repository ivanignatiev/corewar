/*
** my_getnbr.c for my_getnbr in /home/sfez_a/
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Fri Oct  5 14:16:18 2012 arthur sfez
** Last update Mon Nov 12 14:41:38 2012 arthur sfez
*/

int		my_getnbr(char *str)
{
  int		sign;
  int		my_int;

  sign = 1;
  my_int = 0;
  while (*str == '-' || *str == '+')
    {
      if (*str == '-')
	sign = sign * -1;
      str = str + 1;
    }
  while (*str >= '0' && *str <= '9')
    {
      my_int = (my_int * 10) + (*str - '0');
      str = str + 1;
    }
  my_int = my_int * sign;
  return (my_int);
}

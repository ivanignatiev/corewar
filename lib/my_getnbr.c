/*
** my_getnbr.c for lib in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/lib
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Tue Dec 11 14:52:05 2012 arthur sfez
** Last update Tue Dec 11 14:53:19 2012 arthur sfez
*/

int	my_getnbr(char *str)
{
  int	sign;
  int	res;
  
  sign = 1;
  res = 0;
  while (*str == '-' || *str == '+')
    {
      if (*str == '-')
	sign = sign * -1;
      str = str + 1;
    }
  while (*str >= '0' && *str <= '9')
    {
      res = (res * 10) + (*str - '0');
      str = str + 1;
    }
  res = res * sign;
  return (res);
}

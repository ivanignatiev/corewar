/*
** is_big_endian.c for is_big_endian in /home/ignati_i//test_c/Jour_09/ex_05
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Thu Oct 11 11:56:53 2012 ivan ignatiev
** Last update Thu Oct 11 12:00:32 2012 ivan ignatiev
*/

int	is_big_endian(void)
{
  unsigned short test;

  test = 1;
  if (*((unsigned char *) &test) == 0)
    return (1);
  else
    return (0);
}

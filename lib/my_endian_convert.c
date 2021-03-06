/*
** my_endian_convert.c for cwlib in /home/ignati_i//projects/corewar/corewar-2016ed-2015s-2017si-liu_q/lib
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Fri Dec  7 16:53:25 2012 ivan ignatiev
** Last update Tue Dec 11 12:13:07 2012 ivan ignatiev
*/

#include	"cwlib.h"

void		*my_bytes_reverse(void *buff, int size)
{
  char		tmp;
  int		n;
  char		*p;

  p = buff;
  n = size / 2;
  while (n > 0)
    {
      tmp = (*(unsigned char*)(p + n - 1));
      (*(unsigned char*)(p + n - 1)) = (*(unsigned char*)(p + size - n));
      (*(unsigned char*)(p + size - n)) = tmp;
      n--;
    }
  return (buff);
}

void 		*my_conv_to_platform(void *buff, int sz)
{
  if (is_big_endian())
    return (buff);
  else
    return (my_bytes_reverse(buff, sz));
}

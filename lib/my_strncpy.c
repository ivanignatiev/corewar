/*
** my_strncpy.c for stringmy in ./src/stringmy/
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Oct  8 10:11:21 2012 ivan ignatiev
** Last update Tue Dec 11 12:13:40 2012 ivan ignatiev
*/

#include	"cwlib.h"

char		*my_strncpy(char *dest, char *src, int n)
{
  int		i;

  i = 0;
  while (i < n && src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  while (i <= n)
    {
      dest[i] = '\0';
      i++;
    }
  return (dest);
}

void		*my_memncpy(void *dest, void *src, int n)
{
  int		i;

  i = 0;
  while (i < n)
    {
      ((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
      i++;
    }
  return (dest);
}

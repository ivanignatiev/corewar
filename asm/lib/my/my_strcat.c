/*
** my_strcat.c for my_strcat in /home/sfez_a//piscine_local/Jour_07/ex_01
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Tue Oct  9 10:09:12 2012 arthur sfez
** Last update Mon Nov 12 14:16:29 2012 arthur sfez
*/

#include "../../include/my.h"

char		*my_strcat(char *dest, char *src)
{
  int		dest_size;
  int		i;

  i = 0;
  dest_size = my_strlen(dest);
  while (src[i] != '\0')
    {
      dest[dest_size + i] = src[i];
      i = i + 1;
    }
  dest[dest_size + i] = '\0';
  return (dest);
}

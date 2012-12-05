/*
** my_strdup.c for my_strdup in /home/sfez_a//piscine_local/Jour_08/ex_01
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Wed Oct 10 10:26:06 2012 arthur sfez
** Last update Mon Nov 12 14:41:21 2012 arthur sfez
*/

#include <stdlib.h>
#include "../../include/my.h"

char		*my_strdup(char *src)
{
  char		*str;
  int		size;
  int		i;

  i = 0;
  size = my_strlen(src);
  str = malloc(size);
  if (str == NULL)
    return (NULL);
  while (i < size)
    {
      str[i] = src[i];
      i = i + 1;
    }
  str[i] = '\0';
  return (str);
}

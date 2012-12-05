/*
** my_strncat.c for my_strncat in /home/sfez_a//piscine_local/Jour_07/ex_02
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Tue Oct  9 10:34:17 2012 arthur sfez
** Last update Mon Nov 12 14:17:11 2012 arthur sfez
*/

#include "../../include/my.h"

char    *my_strncat(char *dest, char *src, int nb)
{
  int   dest_size;
  int   i;

  i = 0;
  dest_size = my_strlen(dest);
  while (i < nb && src[i] != '\0')
    {
      dest[dest_size + i] = src[i];
      i = i + 1;
    }
  dest[dest_size + i] = '\0';
  return (dest);
}

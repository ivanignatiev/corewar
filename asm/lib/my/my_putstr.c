/*
** my_putstr.c for putstr in /home/sfez_a//piscine_local/Jour_04
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Thu Oct  4 13:44:20 2012 arthur sfez
** Last update Mon Nov 12 14:16:10 2012 arthur sfez
*/

#include "../../include/my.h"

void		my_putstr(char *str)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str = str + 1;
    }
}

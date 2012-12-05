/*
** my_putchar.c for my_putchar in /home/sfez_a//libmy
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Wed Oct 10 10:12:11 2012 arthur sfez
** Last update Mon Nov 12 14:08:01 2012 arthur sfez
*/

#include <unistd.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}

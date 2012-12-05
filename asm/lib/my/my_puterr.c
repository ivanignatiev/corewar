/*
** my_puterr.c for my_puterr in /home/sfez_a//Local/projets_local/corewar/asm/lib/my
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Wed Dec  5 10:59:58 2012 arthur sfez
** Last update Wed Dec  5 11:01:32 2012 arthur sfez
*/

#include <unistd.h>
#include "../../include/my.h"

void		my_puterr(char *s)
{
  write(2, s, my_strlen(s));
}

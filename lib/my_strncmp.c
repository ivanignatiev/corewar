/*
** my_strcmp.c for my_strcmp in /home/sfez_a//piscine_local/Jour_06/ex_05
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Mon Oct  8 14:45:24 2012 arthur sfez
** Last update Thu Dec  6 20:02:44 2012 arthur sfez
*/

#include "cwlib.h"

int	my_strncmp(char *s1, char *s2, int nb)
{
  int	i;
  int	s1_size;
  int	s2_size;

  i = 0;
  s1_size = my_strlen(s1);
  s2_size = my_strlen(s2);
  while (i <= s1_size || i <= s2_size)
    {
      if (i < nb)
	{
	  if (s1[i] == s2[i])
	    i = i + 1;
	  else
	    return (s1[i] - s2[i]);
	}
      else
	return (0);
    }
  return (0);
}

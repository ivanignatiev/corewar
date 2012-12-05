/*
** my_strcmp.c for my_strcmp in /home/sfez_a//piscine_local/Jour_06/ex_05
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Mon Oct  8 14:45:24 2012 arthur sfez
** Last update Mon Nov 12 13:54:51 2012 arthur sfez
*/

int		my_strcmp(char *s1, char *s2)
{
  while (*s1 != '\0' || *s2 != '\0')
    {
      if (*s1 != *s2)
	return (*s1 - *s2);
      s1++;
      s2++;
    }
  return (0);
}

/*
** my_strcmp.c for strcmp in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/lib
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Sat Dec  8 17:38:25 2012 arthur sfez
** Last update Sat Dec  8 18:01:59 2012 arthur sfez
*/

int		my_strcmp(char *s1, char *s2)
{
  while (*s1 != 0 || *s2 != 0)
    {
      if (*s1 != *s2)
	return (*s1 - *s2);
      s1++;
      s2++;
    }
  return (*s1 - *s2);
}

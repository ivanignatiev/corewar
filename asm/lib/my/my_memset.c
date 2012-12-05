/*
** my_memset.c for my_memset in /home/sfez_a//Local/projets_local/myselect/lib/my
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Wed Nov 21 14:00:15 2012 arthur sfez
** Last update Sat Nov 24 17:02:51 2012 arthur sfez
*/

char		*my_memset(char *s, int c, int n)
{
  int		i;

  i = 0;
  while (i < n)
    {
      s[i] = c;
      i++;
    }
  return (s);
}

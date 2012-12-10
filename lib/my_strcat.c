/*
** my_strcat.c for my_strcat in /home/lu_a//day07
** 
** Made by angela lu
** Login   <lu_a@epitech.net>
** 
** Started on  Tue Oct  9 16:37:41 2012 angela lu
** Last update Mon Dec 10 14:34:54 2012 angela lu
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while(dest[i])
    i = i + 1;
  while (src[n])
    {
      dest[i] = src[n];
      n = n + 1;
      i = i + 1;
    }
  dest[i] = 0;
  return (dest);
}

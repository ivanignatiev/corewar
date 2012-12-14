/*
** my_strcpy.c for strcpy in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/lib
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Tue Dec 11 19:37:03 2012 arthur sfez
** Last update Tue Dec 11 19:37:48 2012 arthur sfez
*/

char		*my_strcpy(char *dst, char *src)
{
  while (*src)
    {
      *dst = *src;
      dst++;
      src++;
    }
  *dst = 0;
  return (dst);
}

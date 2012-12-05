/*
** my_strcpy.c for my_strcpy in /home/sfez_a//piscine_local/Jour_06/ex_01
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Mon Oct  8 09:33:17 2012 arthur sfez
** Last update Mon Nov 12 13:52:24 2012 arthur sfez
*/

char	*my_strcpy(char *dest, char *src)
{
  while (*src != '\0')
    {
      *dest = *src;
      dest++;
      src++;
    }
  *dest = '\0';
  return (dest);
}

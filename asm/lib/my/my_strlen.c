/*
** my_strlen.c for strlen in /home/sfez_a//piscine_local/Jour_04
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Thu Oct  4 14:02:40 2012 arthur sfez
** Last update Thu Oct  4 15:28:07 2012 arthur sfez
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (*str != '\0')
    {
      i = i + 1;
      str = str + 1;
    }
  return (i);
}

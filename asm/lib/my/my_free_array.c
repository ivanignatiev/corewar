/*
** my_free_array.c for arraymy in ./src/arraymy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Nov 10 17:34:36 2012 ivan ignatiev
** Last update Wed Dec  5 17:10:51 2012 arthur sfez
*/

#include	<stdlib.h>
#include	"../../include/cwstring.h"

int		my_free_array(char **arr)
{
  int		i;

  if (arr == NULL)
    return (1);
  i = 0;
  while (arr[i] != NULL)
    {
      free(arr[i]);
      i = i + 1;
    }
  if (arr != NULL)
    free(arr);
  return (1);
}

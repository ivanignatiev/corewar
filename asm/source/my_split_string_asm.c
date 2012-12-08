/*
** my_split_string.c for arraymy in ./src/arraymy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Nov 10 17:21:23 2012 ivan ignatiev
** Last update Sat Dec  8 19:15:53 2012 arthur sfez
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"cwlib.h"
#include	"asm.h"

int		is_it_separator_asm(char c, char *separators)
{
  int		i;

  i = 0;
  while (c != separators[i] && separators[i] != '\0')
    i = i + 1;
  if (separators[i] != '\0')
    return (1);
  else
    return (0);
}

char		**add_word_asm(char *str, int count,
			 char **arr)
{
  char		*elem;

  elem = (char*)malloc(sizeof(char) * (count + 1));
  if (elem != NULL)
    {
      my_strncpy(elem, str, count);
      elem[count] = '\0';
      return (my_add_to_array(elem, arr));
    }
  return (arr);
}

void		my_update_separators_asm(char **arr, char *separators)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (arr == NULL)
    return ;
  if (my_strlen(separators) == 1)
    return ;
  while (arr[j] != NULL)
    j++;
  if (is_instruction(arr[j - 1]))
    i = 1;
  if (i == 1)
    separators[1] = '\0';
}

char		**my_split_string_asm(char *str, char *separators)
{
  int		i;
  int		count;
  int		start;
  char		**arr;

  i = 0;
  arr = NULL;
  count = 0;
  while (str[i] != '\0')
    {
      if (!is_it_separator_asm(str[i], separators))
	{
	  if ((i == 0 || is_it_separator_asm(str[i - 1], separators)))
	    {
	      my_update_separators_asm(arr, separators);
	      start = i;
	    }
	  count = count + 1;
	}
      else if (count > 0 && (arr = add_word_asm(str + start, count, arr)) != NULL)
	count = 0;
      i = i + 1;
    }
  if (count > 0)
    arr = add_word_asm(str + start, count, arr);
  return (arr);
}

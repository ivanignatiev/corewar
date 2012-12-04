/*
** get_next_line.c for get_next_line in ./
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sun Dec  2 18:23:21 2012 ivan ignatiev
** Last update Tue Dec  4 17:08:36 2012 ivan ignatiev
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"cwstring.h"

int		my_strlen(char *str)
{
  int		i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

int		my_strncpy(char *dest, char *src, int n)
{
  int		i;

  if (src == NULL)
    return (0);
  i = 0;
  while (src[i] != '\0' && i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  while (i < n)
    {
      dest[i] = '\0';
      i = i + 1;
    }
  return (i);
}

char		*xrealloc(char *rest, char *buf,
			  int n, char *f_rest)
{
  int		len;
  char		*tmp;
  int		i;

  len = my_strlen(rest);
  if ((tmp = (char*)malloc(sizeof(char) * (len + n + 1))) != NULL)
    {
      i = my_strncpy(tmp, rest, len);
      while ((i - len) < n)
	{
	  tmp[i] = buf[i - len];
	  i = i + 1;
	}
      tmp[i] = '\0';
      free(f_rest);
    }
  return (tmp);
}

char		*cut_line(char **rest, int last)
{
  int		i;
  char		*line;

  if (*rest == NULL)
    return (NULL);
  i = 0;
  while ((*rest)[i] != '\n' && (*rest)[i] != '\0')
    i = i + 1;
  if (((*rest)[i] == '\n') || (last && (*rest)[i] == '\0' && i > 0))
    {
      if ((line = (char*)malloc(sizeof(char) * (i + 1))) != NULL)
	{
	  my_strncpy(line, *rest, i);
	  line[i] = '\0';
	  if ((*rest)[i] != '\0')
	    *rest = xrealloc(((*rest) + i + 1), "", 0, *rest);
	  else
	    {
	      free(*rest);
	      *rest = NULL;
	    }
	  return (line);
	}
    }
  return (NULL);
}

char		*get_next_line(const int fd)
{
  static char	*rest;
  char		buf[BUFFER_SIZE + 1];
  int		sz;
  char		*line;

  while ((sz = read(fd, buf, BUFFER_SIZE)) > 0)
    {
      buf[BUFFER_SIZE] = 0;
      if ((rest = xrealloc(rest, buf, sz, rest)) != NULL)
	{
	  if ((line = cut_line(&rest, 0)) != NULL)
	    return (line);
	}
      else
	return (NULL);
    }
  return (cut_line(&rest, 1));
}

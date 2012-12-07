/*
** fill_header.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Thu Dec  6 18:52:45 2012 arthur sfez
** Last update Thu Dec  6 20:25:02 2012 arthur sfez
*/

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include "cwlib.h"
#include "op.h"
#include "asm.h"

int		my_header_name(char *name, char *line)
{
  int		i;

  while (*line != '"' && *line != '\0')
    line = line + 1;
  line = line + 1;
  i = 0;
  while (i < PROG_NAME_LENGTH && line[i] != '"'
	 && line[i] != '\0')
    {
      name[i] = line[i];
      i = i + 1;
    }
  if (line[i] != '"')
    return (0);
  while (i < PROG_NAME_LENGTH)
    {
      name[i] = '\0';
      i = i + 1;
    }
  return (1);
}

int		my_header_comment(char *comment, char *line)
{
  int		i;

  while (*line != '"'  && *line != '\0')
    line = line + 1;
  line = line + 1;
  i = 0;
  while (i < COMMENT_LENGTH && line[i] != '"'
	 && line[i] != '\0')
    {
      comment[i] = line[i];
      i = i + 1;
    }
  if (line[i] != '"')
    return (0);
  while (i < COMMENT_LENGTH)
    {
      comment[i] = '\0';
      i = i + 1;
    }
  return (1);
}

int		my_fill_header(header_t *header, char *s)
{
  if (my_strncmp(s, ".name", 5) == 0)
    {
      if (*(header->prog_name) != 0)
	return (0);
      return (my_header_name(header->prog_name, s + 5));
    }
  else if (my_strncmp(s, ".comment", 8) == 0)
    {
      if (*(header->comment) != 0)
	return (0);
      return (my_header_comment(header->comment, s + 8));
    }
  return (0);
}

header_t	*my_init_header(int fd)
{
  int		i;
  char		*tmp;
  char		*s;
  header_t	*header;

  if ((header = malloc(sizeof(header_t))))
    {
      i = 0;
      header->magic = COREWAR_EXEC_MAGIC;
      *(header->prog_name) = 0;
      *(header->comment) = 0;
      while ((s = get_next_line(fd)) && i != 2)
	{
	  tmp = s;
	  while (*s == ' ' || *s == '\t')
	    s++;
	  if (*s != '.' && *s != '\n')
	    return (NULL);
	  i = i + my_fill_header(header, s);
	  if (tmp)
	    free(tmp);
	}
      if (i != 2)
	return (NULL);
      lseek(fd, 0, SEEK_SET);
    }
  return (header);
}

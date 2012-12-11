/*
** fill_header.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Thu Dec  6 18:52:45 2012 arthur sfez
** Last update Tue Dec 11 12:09:50 2012 arthur sfez
*/

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include "cwlib.h"
#include "op.h"
#include "asm.h"

static int	my_header_name(char *name, char *line)
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

static int	my_header_comment(char *comment, char *line)
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

static int	my_fill_header(header_t *header, char *s)
{
  if (my_strncmp(s, NAME_CMD_STRING, 5) == 0)
    {
      if (!my_header_name(header->prog_name, s + 5))
	my_err_msg(s, UNTERMINATED_STR, 7);
      return (1);
    }
  else if (my_strncmp(s, COMMENT_CMD_STRING, 8) == 0)
    {
      if (*(header->prog_name) == 0)
	my_err_msg(s, SYNTAX_ERR, 1);
      if (!my_header_comment(header->comment, s + 8))
	my_err_msg(s, UNTERMINATED_STR, 9);
      return (1);
    }
  else if (my_strncmp(s, ".extend", 7) != 0)
    my_err_msg(s, UNKNOWN_CMD, 1);
  return (0);
}

void		my_check_header(header_t *header)
{
  int		i;

  i = 0;
  if (*(header->prog_name) == 0)
    while (i < PROG_NAME_LENGTH)
      {
	*(header->prog_name + i) = '\0';
	i++;
      }
  i = 0;
  if (*(header->comment) == 0)
    while (i < COMMENT_LENGTH)
      {
	*(header->comment + i) = '\0';
	i++;
      }
}

char		*my_init_header(int fd, header_t *header)
{
  int		line;
  char		*tmp;
  char		*s;

  header->magic = COREWAR_EXEC_MAGIC;
  my_conv_to_platform(&(header->magic), sizeof(header->magic));
  header->prog_size = 0;
  *(header->prog_name) = 0;
  *(header->comment) = 0;
  while ((s = get_next_line(fd)))
    {
      tmp = s;
      while (*s == ' ' || *s == '\t')
	s++;
      if (*s != '.' && *s != '\0')
	return (s);
      if (*s == '.')
	my_fill_header(header, s);
      free(tmp);
      nb_line++;
    }
  return (NULL);
}

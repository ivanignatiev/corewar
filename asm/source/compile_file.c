/*
** compile_file.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Thu Dec  6 18:50:45 2012 arthur sfez
** Last update Thu Dec 13 19:30:52 2012 arthur sfez
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"op.h"
#include	"asm.h"
#include	"cwlib.h"

static int	my_parse_data(int fdr, char *s)
{
  int		stop;
  char		*separators;
  line_t	one_line;
  labels_t	*labels[2];

  stop = 0;
  one_line.s = s;
  labels[CALL] = NULL;
  labels[DEF] = NULL;
  separators = my_malloc_separators();
  while (stop == 0 && one_line.s)
    {
      g_data.s = one_line.s;
      if ((one_line.arr = my_split_string_asm(one_line.s, separators)))
	{
	  separators[1] = ' ';
	  if (one_line.arr[0][0] != COMMENT_CHAR)
	    if (my_parse_line(one_line, labels) == -1)
	      stop = 1;
	}
      free(one_line.s);
      my_free_array(one_line.arr);
      one_line.s = get_next_line(fdr);
      g_data.nb_line++;
    }
  my_putstr(labels[DEF]->s);
  my_seeknwrite(labels[CALL], labels[DEF]);
  free(separators);
  my_free_lists(&labels[DEF], &labels[CALL]);
  if (stop == 1)
    return (-1);
  return (1);
}

static int	open_cor(char *str)
{
  int		fdw;
  char		*cor;

  cor = malloc(sizeof(char) * (my_strlen(str) + 3));
  if (cor == NULL)
    return (-1);
  cor = my_strncpy(cor, str, (my_strlen(str) - 1));
  cor = my_strcat(cor, "cor");
  fdw = open(cor, O_RDWR | O_CREAT | O_TRUNC, 
	     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  free(cor);
  return (fdw);
}

int		my_compile_file(int fdr, char *str)
{
  char		*s;
  header_t	*header;

  g_data.nb_line = 1;
  g_data.count = sizeof(header_t);
  if ((header = malloc(sizeof(header_t))))
    {
      if (!(s = my_init_header(fdr, header)))
	return (-1);
      my_check_header(header);
      if ((g_data.fdw = (open_cor(str))) != -1)
	{
	  write(g_data.fdw, header, sizeof(*header));
	  if (my_parse_data(fdr, s) == 1)
	    my_success_msg_file(header, str);
	}
      else
	return (my_err_msg_file(str));
      free(header);
      close(fdr);
      close(g_data.fdw);
    }
  return (1);
}

/*
** compile_file.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Thu Dec  6 18:50:45 2012 arthur sfez
   Last update Tue Dec 11 15:22:32 2012 arthur sfez
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"op.h"
#include	"asm.h"
#include	"cwlib.h"

static void	my_parse_data(int fdr, char *s, int fdw)
{
  int		i;
  char		*separators;
  char		**arr;
  labels_t	*labels[2];

  i = 0;
  labels[CALL] = NULL;
  labels[DEF] = NULL;
  separators = my_malloc_separators();
  while (s)
    {
      if ((arr = my_split_string_asm(s, separators)))
	{
	  separators[1] = ' ';
	  my_write_hexa(arr, s, labels, fdw);
	}
      if (i != 0)
	free(s);
      my_free_array(arr);
      s = get_next_line(fdr);
      i++;
      nb_line++;
    }
  free(separators);
}

static int	open_cor(char *str)
{
  int		fdw;
  char		*cor;

  cor = malloc(sizeof(char) * (my_strlen(str) + 3));
  cor = my_strncpy(cor, str, (my_strlen(str) - 1));
  cor = my_strcat(cor, "cor");
  fdw = open(cor, O_RDWR | O_CREAT | O_TRUNC, 
	     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  free(cor);
  return (fdw);
}

void		my_compile_file(int fdr, char *str)
{
  int		fdw;
  char		*s;
  header_t	*header;

  nb_line = 1;
  if ((header = malloc(sizeof(header_t))))
    {
      s = my_init_header(fdr, header);
      my_check_header(header);
      if ((fdw = (open_cor(str))) != -1)
	{
	  write(fdw, header, sizeof(*header));
	  my_parse_data(fdr, s, fdw);
	}
      free(header);
    }
}

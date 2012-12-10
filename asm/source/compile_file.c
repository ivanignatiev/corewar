/*
** compile_file.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Thu Dec  6 18:50:45 2012 arthur sfez
** Last update Sat Dec  8 19:42:29 2012 arthur sfez
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"op.h"
#include	"asm.h"
#include	"cwlib.h"

void		my_parse_data(int fdr, labels_t **list, char *s, int fdw)
{
  int		i;
  char		*separators;
  char		**arr;

  separators = my_malloc_separators();
  while (s)
    {
      i = 0;
      if ((arr = my_split_string_asm(s, separators)))
	{
	  separators[1] = ' ';
	  while (arr[i] != 0)
	    {
	      my_putstr(arr[i]);
	      my_putchar('\n');
	      i++;
	    }
	  my_write_ins(arr, list);
	}
      free(s);
      my_free_array(arr);
      s = get_next_line(fdr);
    }
  free(separators);
}

void		my_compile_file(int fdr)
{
  int		fdw;
  char		*s;
  header_t	*header;
  labels_t	*list;

  if ((header = malloc(sizeof(header_t))))
    {
      s = my_init_header(fdr, header);
      my_check_header(header);
      list = NULL;
      if ((fdw = open("my_cor.cor", O_RDWR | O_CREAT | O_TRUNC, 
		      S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
	return ;
      write(fdw, header, sizeof(*header));
      my_parse_data(fdr, &list, s, fdw);
    }
  if (header != NULL)
    free(header);
}

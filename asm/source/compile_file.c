/*
** compile_file.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Thu Dec  6 18:50:45 2012 arthur sfez
** Last update Fri Dec  7 18:46:41 2012 arthur sfez
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"op.h"
#include	"asm.h"
#include	"cwlib.h"

void		my_retrieve_data(int fd, labels_t **list, char *s)
{
  int		i;
  char		**arr;

  while (s)
    {
      i = 0;
      if ((arr = my_split_string(s, " ,\t")))
	my_translate(arr, list);
      free(s);
      my_free_array(arr);
      s = get_next_line(fd);
    }
  return (1);
}

void		my_compile_file(int fd)
{
  int		prog_size;
  char		*s;
  header_t	*header;
  labels_t	*list;


  if ((header = malloc(sizeof(header_t))))
    {
      s = my_init_header(fd, header);
      my_check_header(header);
      list = NULL;
      my_retrieve_data(fd, &list, s);
    }
}

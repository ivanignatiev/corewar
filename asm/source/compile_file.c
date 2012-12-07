/*
** compile_file.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Thu Dec  6 18:50:45 2012 arthur sfez
** Last update Fri Dec  7 14:08:39 2012 arthur sfez
*/

#include	<unistd.h>
#include	"op.h"
#include	"asm.h"
#include	"cwlib.h"

void		my_compile_file(int fd)
{
  int		prog_size;
  header_t	*header;
  labels_t	*list;

  if ((header = my_init_header(fd)))
    {
      my_check_header(header);
      list = NULL;
      //prog_size = my_retrieve_data(fd, &list);
    }
}

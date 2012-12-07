/*
** compile_file.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Thu Dec  6 18:50:45 2012 arthur sfez
** Last update Thu Dec  6 20:26:53 2012 arthur sfez
*/

#include	"op.h"
#include	"asm.h"
#include	"cwlib.h"

void		my_compile_file(int fd)
{
  header_t	*header;

  if (!(header = my_init_header(fd)))
    {
      return ; 
   }
     my_putstr(header->prog_name);
      my_putchar('\n');				
      my_putstr(header->comment);
 
}

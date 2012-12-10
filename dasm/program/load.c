/*
** program.c for corewar in ./dasm
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 11:44:12 2012 ivan ignatiev
** Last update Mon Dec 10 13:21:22 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	"cwlib.h"
#include	"op.h"
#include	"dasm.h"

int		cw_is_magic(header_t *hd)
{
  my_conv_to_platform(&(hd->magic), sizeof(hd->magic));
  return (hd->magic == COREWAR_EXEC_MAGIC);
}

t_program	*cw_load_program(char *filename,
				 int start_addr,
				 int prog_num)
{
  int		fd;
  t_program	*prog;

  if ((prog = (t_program*)malloc(sizeof(t_program))) != NULL)
    {
      if ((fd = open(filename, O_RDONLY)) > 0)
	{
	  if (read(fd, &(prog->header), sizeof(header_t)) > 0)
	    {
	      my_conv_to_platform(&(prog->header.prog_size), sizeof(prog->header.prog_size));
	      if ((prog->start_addr = cw_try_place_program(fd, start_addr,
							   prog->header.prog_size)) < 0
		  || !cw_is_magic(&(prog->header)))
		{
		  free(prog);
		  return (NULL);
		}
	      prog->prog_num = prog_num;
	      prog->memory_start = g_memory + prog->start_addr;
	      prog->pc = 0;
	      return (prog);
	    }
	}
    }
  return (NULL);
}

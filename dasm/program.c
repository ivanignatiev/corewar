/*
** program.c for corewar in /home/ignati_i//projects/corewar/corewar-2016ed-2015s-2017si-liu_q/dasm
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 11:44:12 2012 ivan ignatiev
** Last update Mon Dec 10 11:49:11 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	"cwlib.h"
#include	"op.h"
#include	"dasm.h"

t_program	*cw_load_program(char *filename,
				 int start_addr,
				 int prog_num)
{
  int		fd;
  int		real_size;
  t_program	*prog;

  if ((prog = (t_program*)malloc(sizeof(t_program))) != NULL)
    {
      if ((fd = open(filename, O_RDONLY)) > 0)
	{
	  if (read(fd, &(prog->header), sizeof(header_t)) > 0)
	    {
	      my_conv_to_platform(&(prog->header.prog_size), sizeof(int));
	      /*TODO: MAGIC VALIDE*/
	      if ((prog->start_addr = cw_try_place_program(fd, start_addr,
							   prog->header.prog_size)) < 0)
		{
		  free(prog);
		  return (NULL);
		}
	      prog->prog_num = prog_num;
	      prog->memory_start = g_memory + prog->start_addr;
	      return (prog);
	    }
	}
    }
  return (NULL);
}

void		cw_try_run_instr(t_program *prog)
{
  printf("#%d (start: %d) Prog: '%s' ('%s') , size %d\n",
	 prog->prog_num,
	 prog->start_addr,
	 prog->header.prog_name,
	 prog->header.comment,
	 prog->header.prog_size);
  cw_dump_memory(prog->memory_start, prog->header.prog_size);
  printf("\n#\n\n");
}

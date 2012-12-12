/*
** program.c for corewar in ./dasm/program
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 11:44:12 2012 ivan ignatiev
** Last update Wed Dec 12 17:38:17 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

static int	cw_is_magic(header_t *hd)
{
  my_conv_to_platform(&(hd->magic), sizeof(hd->magic));
  return (hd->magic == COREWAR_EXEC_MAGIC);
}

t_program	*cw_init_program(t_program *prog)
{
  int		i;

  i = 0;
  prog->cur_nbr_cycles = -1;
  prog->pc = 0;
  prog->nbr_cycles = 0;
  prog->carry = 0;
  prog->fork = 0;
  while (i < REG_NUMBER)
    {
      prog->reg[i] = 0;
      i = i + 1;
    }
  prog->reg[0] = prog->prog_num;
  return (prog);
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
		  my_puterr("corewar: Wrong COR file.\n");
		  free(prog);
		  return (NULL);
		}
	      prog->prog_num = prog_num;
	      prog->memory_start = g_memory + prog->start_addr;
	      return (cw_init_program(prog));
	    }
	}
    }
  return (NULL);
}

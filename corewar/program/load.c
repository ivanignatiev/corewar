/*
** program.c for corewar in ./dasm/program
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 11:44:12 2012 ivan ignatiev
** Last update Sat Dec 15 14:13:40 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

t_program	*cw_init_program(t_program *prog)
{
  int		i;

  i = 0;
  prog->instr.nbr_cycles = -1;
  prog->instr.wait = 0;
  prog->instr.args = NULL;
  prog->pc = 0;
  prog->live = 0;
  prog->carry = 0;
  prog->fork = 0;
  prog->last_live_cycle = -1;
  while (i < REG_NUMBER)
    {
      prog->reg[i] = 0;
      i = i + 1;
    }
  prog->reg[0] = prog->prog_num;
  return (prog);
}

void		cw_reset_program(t_program *prog)
{
  int		i;

  i = 0;
  if (prog->instr.args != NULL)
    free(prog->instr.args);
  prog->instr.args = NULL;
  prog->instr.nbr_cycles = -1;
  prog->instr.wait = 0;
  prog->live = 0;
  prog->pc = prog->start_addr;
  prog->carry = 0;
  prog->last_live_cycle = -1;
  while (i < REG_NUMBER)
    {
      prog->reg[i] = 0;
      i = i + 1;
    }
  prog->reg[0] = prog->prog_num;
}

t_program	*cw_load_program(char *filename,
				 int start_addr,
				 int prog_num)
{
  t_program	*prog;

  if ((prog = (t_program*)malloc(sizeof(t_program))) != NULL)
    if ((prog->fd = open(filename, O_RDONLY)) > 0)
      if (read(prog->fd, &(prog->header), sizeof(header_t)) > 0)
	{
	  my_conv_to_platform(&(prog->header.prog_size),
			      sizeof(prog->header.prog_size));
	  my_conv_to_platform(&(prog->header.magic),
			      sizeof(prog->header.magic));
	  if (prog->header.magic == COREWAR_EXEC_MAGIC)
	    {
	      prog->start_addr = start_addr;
	      prog->prog_num = prog_num;
	      return (cw_init_program(prog));
	    }
	}
  if (prog != NULL)
    {
      printf("%s is not a corewar executable\n", filename);
      if (prog->fd >= 0)
	close(prog->fd);
      free(prog);
    }
  return (NULL);
}

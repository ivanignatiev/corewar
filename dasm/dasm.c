/*
** dasm.c for corewar in ./dasm
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec  5 14:03:15 2012 ivan ignatiev
** Last update Fri Dec  7 16:45:09 2012 ivan ignatiev
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"cwlib.h"
#include	"op.h"

char		*g_memory;

typedef struct	s_program
{
  header_t	header;
  int		start_addr;
  int		prog_num;
  char		*memory_start;
} t_program;

t_program	*load_program(char *filename, int start_addr, int prog_num)
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
	      /* DEBUG# */
	      printf("Loaded programm '%s' (%s), size = %d\n", prog->header.prog_name, prog->header.comment, prog->header.prog_size);
	      /* #DEBUG */
	      real_size = read(fd, g_memory, prog->header.prog_size);
	      if (real_size != prog->header.prog_size)
		{
		  my_puterr("Wrong COR file.\n");
		  /* DEBUG# */
		  printf("Real size: %d, Header size: %d\n ", real_size, prog->header.prog_size);
		  /* #DEBUG */
		  free(prog);
		  return (NULL);
		}
	      prog->start_addr = start_addr;
	      prog->prog_num = prog_num;
	      prog->memory_start = g_memory + start_addr;
	      /* DEBUG# */
	      printf("Loaded programm '%s' (%s), size = %d\n", prog->header.prog_name, prog->header.comment, prog->header.prog_size);
	      /* #DEBUG */
	      return (prog);
	    }
	}
    }
  my_puterr("Not enought memory for program.\n");
  return (NULL);
}

int		init_memory()
{
  if ((g_memory = (char*)malloc(sizeof(char) * MEM_SIZE)) != NULL)
    {
      my_putstr("Memory initialisated.\n");
      return (1);
    }
  my_puterr("Memory initialisation failed.\n");
  return (0);
}

int		free_memory()
{
  free(g_memory);
  my_putstr("Memory freed.\n");
}

int		dump_memory()
{
  int		i;

  i = 0;
  while (i < 100)
    {
      printf("%X ", (unsigned int)g_memory[i]);
      if (i % 16 == 0)
	printf("\n");
      i = i + 1;
    }
}

int		main(int argc, char **argv)
{
  if (argc > 1 && argv)
    {
      if (init_memory())
	{
	  load_program(argv[1], 0, 0);
	  /* DEBUG# */
	  dump_memory();
	  /* #DEBUG */
	  free_memory();
	  return (EXIT_SUCCESS);
	}
    }
  else
    my_puterr("Too few arguments.\n");
  return (EXIT_FAILURE);
}

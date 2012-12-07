/*
** dasm.c for corewar in ./dasm
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Dec  5 14:03:15 2012 ivan ignatiev
** Last update Fri Dec  7 20:08:15 2012 ivan ignatiev
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"cwlib.h"
#include	"op.h"

unsigned char	*g_memory;

typedef struct	s_program
{
  header_t	header;
  int		start_addr;
  int		prog_num;
  char		*memory_start;
} t_program;

typedef struct	s_prog_list
{
  t_program	prog;
  struct	s_program_list	*next;
} t_prog_list;

t_program	*cw_load_program(char *filename, int start_addr, int prog_num)
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
	      real_size = read(fd, g_memory + start_addr, prog->header.prog_size);
	      if (real_size != prog->header.prog_size)
		{
		  my_puterr("Wrong COR file.\n");
		  free(prog);
		  return (NULL);
		}
	      prog->start_addr = start_addr;
	      prog->prog_num = prog_num;
	      prog->memory_start = g_memory + start_addr;
	      return (prog);
	    }
	}
    }
  my_puterr("Not enought memory for program.\n");
  return (NULL);
}

t_prog_list	*cw_add_prog_to_list(char *filename, int start_addr, int prog_num, t_prog_list *list)
{
  t_program	*prog;
  t_prog_list	*prog_elem;
  t_prog_list	*nav;

  if ((prog = cw_load_program(filename, start_addr, prog_num)) != NULL)
    {
      if ((prog_elem = (t_prog_list*)malloc(sizeof(t_prog_list))) != NULL)
	{
	  prog_elem->next = NULL;
	  if (list == NULL)
	    list = prog_elem;
	  else
	    {
	      nav = list;
	      while (nav->next)
		nav = nav->next;
	      nav->next = prog_elem;
	    }
	}
      else
	free(prog);
    }
  return (list);
}

int		cw_init_memory()
{
  if ((g_memory = (char*)malloc(sizeof(char) * MEM_SIZE)) != NULL)
    {
      my_putstr("Memory initialisated.\n");
      return (1);
    }
  my_puterr("Memory initialisation failed.\n");
  return (0);
}

int		cw_free_memory()
{
  free(g_memory);
  my_putstr("Memory freed.\n");
}

int		cw_dump_memory()
{
  int		i;
  char		myhex[] = "0123456789ABCDEF";

  i = 0;
  while (i < MEM_SIZE)
    {
      my_putchar(myhex[(g_memory[i] / 16) % 16]);
      my_putchar(myhex[g_memory[i]  % 16]);
      my_putchar(' ');
      if ((i + 1) % 16 == 0 && i > 0)
	my_putchar('\n');
      i = i + 1;
    }
  my_putchar('\n');
}

void		cw_try_run_instr(t_prog_list *prog)
{
}

void		begin_corewar(t_prog_list *progs)
{
  t_prog_list	*nav;
  int		cycles;

  /*  while ()
    {
      nav = progs;
      while (nav != NULL)
	{
	  cw_try_run_instr(nav->prog);
	  nav = nav->next;
	}
      cycles = cycles + 1;
      }*/
}

t_prog_list	*cw_get_program_list(int argc, char **argv)
{
  t_prog_list	*prog_list;
  int		i;

  prog_list = NULL;
  i = 1;
  while (i < argc)
    {
      prog_list = cw_add_prog_to_list(argv[i], 0, 0, prog_list);
      i = i + 1;
    }
  return (prog_list);
}

int		main(int argc, char **argv)
{
  t_prog_list	*prog_list;

  if (argc > 1 && argv)
    {
      if (cw_init_memory())
	{
	  prog_list = cw_get_program_list(argc, argv);
	  begin_corewar(prog_list);
	  /* DEBUG# */
	  cw_dump_memory();
	  /* #DEBUG */
	  cw_free_memory();
	  return (EXIT_SUCCESS);
	}
    }
  else
    my_puterr("Too few arguments.\n");
  return (EXIT_FAILURE);
}

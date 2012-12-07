/*
** main.c for corewar in /home/sfez_a//Local/projets_local/corewar/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Wed Dec  5 10:48:23 2012 arthur sfez
** Last update Thu Dec  6 19:59:03 2012 arthur sfez
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "cwlib.h"
#include	"op.h"
#include	"asm.h"


int		main(int ac, char **av)
{
  int		i;
  int		fd;

  i = 1;
  while (i < ac)
    {
      if ((fd = open(av[i], O_RDONLY)) == -1)
	{
	  my_puterr("Could not open ");
	  my_puterr(av[i]);
	  my_putchar('\n');
	}
      else
	my_compile_file(fd);
      i++;
    }
  return (EXIT_SUCCESS);
}

/*
** main.c for corewar in /home/sfez_a//Local/projets_local/corewar/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Wed Dec  5 10:48:23 2012 arthur sfez
** Last update Tue Dec 11 11:55:23 2012 arthur sfez
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	"cwlib.h"
#include	"op.h"
#include	"asm.h"

int		nb_line;

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
	  my_puterr("\n");
	}
      else if (!(av[i][my_strlen(av[i]) - 1] == 's'
		&& av[i][my_strlen(av[i]) - 2] == '.'))
	{
	  my_puterr(av[i]);
	  my_puterr(" isn't the right file. ");
	  my_puterr("\n");
	}
      else
	my_compile_file(fd, av[i]);
      i++;
    }
  return (EXIT_SUCCESS);
}

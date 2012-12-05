/*
** main.c for corewar in /home/sfez_a//Local/projets_local/corewar/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Wed Dec  5 10:48:23 2012 arthur sfez
** Last update Wed Dec  5 17:11:58 2012 arthur sfez
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/my.h"

int		main(int ac, char **av)
{
  int		fd;

  if (ac == 2)
    {
      if ((fd = open(av[1], O_RDONLY)) == -1)
	{
	  my_puterr("Open failed.");
	  return (EXIT_FAILURE);
	}
    }
  else
    my_putstr("Usage: ./AsmX file_name[.s]\n");
  return (EXIT_SUCCESS);
}

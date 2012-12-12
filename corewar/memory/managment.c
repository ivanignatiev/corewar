/*
** managment.c for corewar in ./dasm/memory
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 11:50:08 2012 ivan ignatiev
** Last update Wed Dec 12 16:15:50 2012 ivan ignatiev
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

int		cw_search_unmapped(int begin_search,
				   int prog_size)
{
  t_prog_list	*nav;
  int		last_addr;

  if ((nav = g_prog_list) == NULL
      && (MEM_SIZE - begin_search) >= prog_size)
    return (begin_search);
  last_addr = begin_search;
  while (nav != NULL)
    {
      if ((nav->prog->start_addr - last_addr) >= prog_size)
	return (last_addr);
      last_addr = nav->prog->start_addr + nav->prog->header.prog_size;
      nav = nav->next;
    }
  if ((MEM_SIZE - last_addr) >= prog_size)
    return (last_addr + 1);
  return (-1);
}

int		cw_try_place_program(int fd,
				     int start_addr,
				     int prog_size)
{
  int		real_size;
  int		found_addr;
  char		test_eof;

  if ((start_addr < 0 && (found_addr = cw_search_unmapped(0, prog_size)) >= 0)
      || (start_addr >= 0 && (found_addr = cw_search_unmapped(start_addr, prog_size)) == start_addr))
    {
      real_size = read(fd, g_memory + found_addr, prog_size);
      if (real_size == prog_size && read(fd, &test_eof, 1) == 0)
	return (found_addr);
    }
  return (-1);
}

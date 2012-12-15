/*
** managment.c for corewar in ./dasm/memory
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 11:50:08 2012 ivan ignatiev
** Last update Sat Dec 15 06:48:37 2012 ivan ignatiev
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"cwlib.h"
#include	"op.h"
#include	"corewar.h"

int		cw_put_program_to(int start_addr, t_program *prog)
{
  t_prog_list	*nav;
  char		test_eof;
  int		real_size;

  nav = g_prog_list;
  while (nav != NULL)
    {
      if (start_addr >= nav->prog->start_addr
	  && start_addr <= (nav->prog->header.prog_size
			 + nav->prog->start_addr)
	  && prog->prog_num != nav->prog->prog_num
	  && nav->prog->start_addr >= 0)
	return (0);
      nav = nav->next;
    }
  real_size = read(prog->fd, g_memory + start_addr, prog->header.prog_size);
  if (real_size != prog->header.prog_size
      && read(prog->fd, &test_eof, 1) != 0)
    return (0);
  prog->start_addr = start_addr;
  prog->pc = start_addr;
  return (1);
}

int		cw_try_place_programs()
{
  t_prog_list	*nav;
  int		i;
  int		prog_count;
  int		start_addr;

  prog_count = cw_get_prog_count();
  nav = g_prog_list;
  i = 0;
  while (nav != NULL)
    {
      if (nav->prog->header.prog_size > (MEM_SIZE / prog_count))
	return (0);
      if (nav->prog->start_addr < 0)
	start_addr = cw_m(i * (MEM_SIZE / prog_count));
      else
	start_addr = cw_m(nav->prog->start_addr);
      if (!cw_put_program_to(start_addr, nav->prog))
	return (0);
      close(nav->prog->fd);
      nav = nav->next;
      ++i;
    }
  return (i);
}

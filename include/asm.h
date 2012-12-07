/*
** asm.h for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Thu Dec  6 19:50:32 2012 arthur sfez
** Last update Fri Dec  7 14:08:03 2012 arthur sfez
*/

#ifndef ASM_H_
# define ASM_H_

# define UNKNOWN_CMD		0
# define SYNTAX_ERR		1
# define UNKNOWN_INS		2
# define UNKNOWN_ARG		3
# define UNTERMINATED_STR	4

#include "op.h"

struct	err_s
{
  char		*s;
  int		err;
};

typedef struct err_s err_t;

struct	labels_s
{
  char			*s;
  int			adr;
  struct labels_s	*next;
};

typedef struct labels_s labels_t;

void		my_compile_file(int fd);
header_t	*my_init_header(int fd);
void		my_check_header(header_t *header);
void		my_err_msg(char *s, int line, int err, int pos);

#endif /* ASM_H_ */

/*
** asm.h for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Thu Dec  6 19:50:32 2012 arthur sfez
** Last update Mon Dec 10 22:13:12 2012 angela lu
*/

#ifndef ASM_H_
# define ASM_H_

# define UNKNOWN_CMD		0
# define SYNTAX_ERR		1
# define UNKNOWN_INS		2
# define UNKNOWN_ARG		3
# define UNTERMINATED_STR	4
# define NUMBER_EXPECTED	5
# define TRAILING_GARBAGE	6

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

void		my_compile_file(int fd, char *str);
char		*my_init_header(int fd, header_t *header);
void		my_check_header(header_t *header);
void		my_err_msg(char *s, int line, int err, int pos);
int		is_instruction(char *s);
char		*my_malloc_separators();
char		*my_clean_string(char *s, char *separators);
int		check_lab_chars(char c);
int		is_label_def(char *str, int i);

#endif /* ASM_H_ */

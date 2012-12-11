/*
** asm.h for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Thu Dec  6 19:50:32 2012 arthur sfez
** Last update Tue Dec 11 16:32:46 2012 arthur sfez
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
# define TOOMANY_ARG		7
# define INVALID_CHAR		8
# define MISSING_LABEL_NAME	9

# define CALL			0
# define DEF			1

#include "op.h"

extern	int	nb_line;

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

struct	args_s
{
  int			val;
  int			size;
  struct args_s		*next;
};

typedef struct args_s	args_t;
typedef struct labels_s labels_t;

void		my_compile_file(int fd, char *str);
char		*my_init_header(int fd, header_t *header);
void		my_check_header(header_t *header);
void		my_err_msg(char *s, int err, int pos);
int		is_instruction(char *s);
char		*my_malloc_separators();
char		*my_clean_string(char *s, char *separators);
void		my_write_hexa(char **arr, char *s, labels_t **labels, int fdw);
char		*my_ins_hexa(char *s);
int		my_strstr_int(char *str, char *to_find);
int		my_get_line_pos(char *s, int i);
int		is_label_def(char *str, char *s, int i);

#endif /* ASM_H_ */

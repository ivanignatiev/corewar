/*
** asm.h for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Thu Dec  6 19:50:32 2012 arthur sfez
** Last update Thu Dec 13 19:21:44 2012 arthur sfez
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
# define NOTENOUGH_ARG		8
# define INVALID_CHAR		9
# define MISSING_LABEL_NAME	10
# define BAD_ARGUMENT		11
# define REG_VALUE		12

# define CALL			0
# define DEF			1

# define IND			0
# define ARG			1

#include "op.h"

struct	err_s
{
  char		*s;
  int		err;
};

struct	line_s
{
  char			*s;
  char			**arr;
};

struct	labels_s
{
  char			*s;
  int			adr_a;
  int			adr;
  int			size;
  struct labels_s	*next;
};

struct	args_s
{
  int			val;
  int			size;
};

struct	data_s
{
  int			nb_line;
  int			fdw;
  int			count;
  char			*s;
  int			n[2];
};

typedef struct err_s	err_t;
typedef struct line_s	line_t;
typedef struct args_s	args_t;
typedef struct labels_s labels_t;
typedef struct data_s	data_t;

extern	data_t	g_data;


/*
** Parsing header
*/

int		my_compile_file(int fd, char *str);
char		*my_init_header(int fd, header_t *header);
void		my_check_header(header_t *header);

/*
** Error messages
*/
int		my_err_msg(char *s, int err, int pos);
int		my_err_msg_header(char *s, int err, int pos);
int		my_get_line_pos(char *s, int i);

/*
** Parsing instructions
*/
int		is_instruction(char *s);
char		*my_malloc_separators();
char		*my_clean_string(char *s, char *separators);
int		my_parse_line(line_t one_line, labels_t **labels);
int		is_label_def(line_t one_line, int i, int *lb_def);
int		my_enc_exists(int n_ins);

/*
** Write binary
*/
void		my_init_arg_tab(args_t **args);
int		my_analyze_args(line_t one_line, int n_ins, labels_t **labels, args_t **args);
args_t		*my_check_add_r(char *arg_val, int n_ins, int *encbyte);
args_t		*my_check_add_d(char *arg_val, int n_ins, int *encbyte, labels_t **labels);
args_t		*my_check_add_i(char *arg_val, int n_ins, int *encbyte);
int		my_enc_exists(int c);

/*
** Lists
*/

void		my_lab_to_list(labels_t **list, char *s, int n_ins, int size);

#endif /* ASM_H_ */

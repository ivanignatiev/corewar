/*
** dasm.h for corewar in ./dasm/memory
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 11:53:03 2012 ivan ignatiev
** Last update Tue Dec 11 13:21:22 2012 ivan ignatiev
*/

#ifndef	DASM_H_
# define DASM_H_

typedef struct	s_program
{
  header_t	header;
  unsigned int	start_addr;
  unsigned int	prog_num;
  unsigned int	pc;
  long long	 reg[REG_NUMBER];
  unsigned char carry;
  unsigned char	*memory_start; /* g_memory  + start_addr + pc =  memory_start[pc] */
}		t_program;

typedef struct	s_prog_list
{
  char		active;
  t_program	*prog;
  struct	s_prog_list	*next;
}		t_prog_list;

typedef struct	s_prog_args
{
  long long	value;
  args_type_t	type;
  long long	size;
}		t_prog_args;

typedef		int(*t_instr)(t_program *prog, op_t *instr);

unsigned char	*g_memory;
t_prog_list	*g_prog_list;

int		cw_add_prog_to_list(char *filename,
				    int start_addr,
				    int prog_num);
int		cw_get_prog_count();
void		cw_get_program_list(int argc, char **argv);
t_program	*cw_load_program(char *filename,
				 int start_addr,
				 int prog_num);
int		cw_try_run_instr(t_program *prog);
int		cw_dump_memory(unsigned char *memory, int size);
int		cw_search_unmapped(int begin_search,
				   int prog_size);
int		cw_try_place_program(int fd,
				     int start_addr,
				     int prog_size);
int		cw_init_memory();
int		cw_free_memory();
t_prog_args	*cw_args_order(op_t *instr, unsigned char order_byte);
int		cw_get_args(t_program *prog,
			    op_t *instr,
			    t_prog_args *args);



#endif /* !DASM_H_ */


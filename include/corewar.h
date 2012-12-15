/*
** dasm.h for corewar in ./dasm/memory
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Mon Dec 10 11:53:03 2012 ivan ignatiev
** Last update Sat Dec 15 04:20:51 2012 ivan ignatiev
*/

#ifndef	COREWAR_H_
# define COREWAR_H_

typedef long int t_long_type;

typedef struct	s_program
{
  int		fd;
  header_t	header;
  int		fork;
  int		start_addr;
  t_long_type	prog_num;
  int		previos_pc;
  int		pc;
  t_long_type	reg[REG_NUMBER];
  unsigned char carry;
  t_long_type	cur_nbr_cycles;
  t_long_type	last_live_cycle;
  t_long_type	cycle;
}		t_program;

typedef struct	s_prog_list
{
  t_program	*prog;
  struct	s_prog_list	*next;
}		t_prog_list;

typedef struct	s_prog_args
{
  t_long_type	value;
  args_type_t	type;
  unsigned int	size;
}		t_prog_args;

typedef		int(*t_instr)(t_program *prog, op_t *instr, t_prog_args *args);

typedef	struct	s_prog_instr
{
  t_instr	func;
  int		enc_byte;
}		t_prog_instr;

typedef struct	s_cycle
{
  t_long_type	nbr;
  t_long_type	live_calls;
  t_long_type	die;
}		t_cycle;

unsigned char	*g_memory;
t_prog_list	*g_prog_list;
t_program	*g_last_live;
t_long_type	g_cycle_to_dump;

void		begin_corewar(t_cycle *cycle,
			      t_long_type prog_count);
int		cw_add_prog_to_list(char *filename,
				    int start_addr,
				    int prog_num);
int		cw_get_prog_count();
t_long_type	cw_get_prog_number();
int		cw_get_program_list(int argc,
				    char **argv);
t_program	*cw_load_program(char *filename,
				 int start_addr,
				 int prog_num);
t_prog_instr	*cw_instrs_list();
int		cw_try_run_instr(t_program *prog,
				 t_prog_instr *instrs,
				 t_long_type cycle);
int		cw_dump_memory(unsigned char *memory,
			       int size);
int		cw_init_memory();
int		cw_free_memory();
void		cw_clear_list();
t_long_type	cw_m(t_long_type addr);
int		cw_try_place_programs();
void		cw_reset_program(t_program *prog);
t_prog_args	*cw_args_order(op_t *instr,
			       unsigned char order_byte);
int		cw_get_args(t_program *prog,
			    op_t *instr,
			    t_prog_args *args);
void		cw_remove_program(t_program *prog);
void		cw_show_args(op_t *instr,
			     t_prog_args *args,
			     t_program *prog);
int		cw_instr_live(t_program *prog, op_t *instr, t_prog_args *args);
int		cw_instr_ld(t_program *prog, op_t *instr, t_prog_args *args);
int		cw_instr_st(t_program *prog, op_t *instr, t_prog_args *args);
int		cw_instr_add(t_program *prog, op_t *instr, t_prog_args *args);
int		cw_instr_sub(t_program *prog, op_t *instr, t_prog_args *args);
int		cw_instr_and(t_program *prog, op_t *instr, t_prog_args *args);
int		cw_instr_or(t_program *prog, op_t *instr, t_prog_args *args);
int		cw_instr_xor(t_program *prog, op_t *instr, t_prog_args *args);
int		cw_instr_zjmp(t_program *prog, op_t *instr, t_prog_args *args);
int		cw_instr_ldi(t_program *prog, op_t *instr, t_prog_args *args);
int		cw_instr_sti(t_program *prog, op_t *instr, t_prog_args *args);
int		cw_instr_fork(t_program *prog, op_t *instr, t_prog_args *args);
int		cw_instr_lld(t_program *prog, op_t *instr, t_prog_args *args);
int		cw_instr_lldi(t_program *prog, op_t *instr, t_prog_args *args);
int		cw_instr_lfork(t_program *prog, op_t *instr, t_prog_args *args);
int		cw_instr_aff(t_program *prog, op_t *instr, t_prog_args *args);
void		*cw_tomemcpy(void *src,
			     int n,
			     int dest_n,
			     t_long_type start_addr);
void		*cw_frommemcpy(void *dest,
			       int n,
			       int dest_n,
			       t_long_type start_addr);

#endif /* !COREWAR_H_ */

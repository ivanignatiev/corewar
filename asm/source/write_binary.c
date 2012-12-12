/*
** write_binary.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Sat Dec  8 16:14:16 2012 arthur sfez
** Last update Wed Dec 12 17:02:58 2012 arthur sfez
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"asm.h"
#include	"op.h"

void		my_write_args(int fdw, args_t **args, int *count)
{
  /*write(fdw, &args->val, args->size);
    args = args->next;*/
}

args_t		*my_update_encbyte(char *arg, int i, int n_ins, int *encbyte)
{
  if (*arg == 'r')
    return (my_check_add_r(arg, i, n_ins, encbyte));
  else if (*arg == DIRECT_CHAR)
    return (my_check_add_d(arg, i, n_ins, encbyte));
  /*
  else
    return (my_check_add_i(one_line, i, n_ins, encbyte));
  */
}

args_t		**my_analyze_args(line_t one_line, int i, int fdw, int n_ins)
{
  int		n;
  int		encbyte;
  args_t	**args;

  encbyte = 0;
  n = 0;
  my_init_arg_tab(args);
  write(fdw, &n_ins, 1);
  while (one_line.arr[i] != NULL)
    {
      if (n + 1 >= op_tab[n_ins - 1].nbr_args && one_line.arr[i + 1] != NULL)
	my_err_msg(one_line, TOOMANY_ARG, i - 1);
      args[n] = my_update_encbyte(one_line.arr[i], n, n_ins, &encbyte);
      n++;
      i++;
    }
  if (n != op_tab[n_ins - 1].nbr_args)
    my_err_msg(one_line, NOTENOUGH_ARG, i - n - 1);
  if (op_tab[n_ins - 1].nbr_args != 1 || op_tab[n_ins - 1].code == 16)
    write(fdw, &encbyte, 1);
  return (args);
}

static void	my_init_variables(int *lb_def, labels_t **labels, int *i, args_t **args)
{
  args = NULL;
  *lb_def = 0;
  *i = 0;
}

int		my_parse_line(line_t one_line, int fdw, labels_t **labels)
{
  int		i;
  int		lb_def;
  int		n_ins;
  args_t	**args;
  static int	count = sizeof(header_t);

  my_init_variables(&lb_def, labels, &i, args);
  while (one_line.arr[i] != NULL)
    {
      if ((lb_def == 0 && i == 0) && is_label_def(one_line, i, &lb_def))
	my_lab_to_list(&labels[DEF], one_line.arr[i], count);
      else if ((i == 0 && lb_def == 0) || (i == 1 && lb_def == 1))
	{
	  if (my_enc_exists((n_ins = my_get_ins_code(one_line, i))))
	    count++;
	  count++;
	  args = my_analyze_args(one_line, i + 1, fdw, n_ins);
	}
      else
	my_write_args(fdw, args, &count);
      i++;
    }
  return (count);
}

/*
** write_binary.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Sat Dec  8 16:14:16 2012 arthur sfez
** Last update Thu Dec 13 19:21:11 2012 arthur sfez
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"asm.h"
#include	"op.h"


args_t		*my_update_encbyte(char *arg, int n_ins, int *encbyte, labels_t **labels)
{
  if (*arg == 'r')
    return (my_check_add_r(arg, n_ins, encbyte));
  else if (*arg == DIRECT_CHAR)
    return (my_check_add_d(arg, n_ins, encbyte, labels));
  else
    return (my_check_add_i(arg, n_ins, encbyte));
}

int		my_analyze_args(line_t one_line, int n_ins, labels_t **labels, args_t **args)
{
  int		encbyte;

  encbyte = 0;
  g_data.n[ARG] = 0;
  write(g_data.fdw, &n_ins, 1);
  while (one_line.arr[g_data.n[IND]] != NULL)
    {
      if (g_data.n[ARG] + 1 >= op_tab[n_ins - 1].nbr_args && one_line.arr[g_data.n[IND] + 1] != NULL)
	{
	  my_err_msg(one_line.s, TOOMANY_ARG, g_data.n[IND] - 1);
	  return (-1);
	}
      if ((args[g_data.n[ARG]] = my_update_encbyte(one_line.arr[g_data.n[IND]], n_ins, &encbyte, labels)) == NULL)
	return (-1);
      g_data.n[ARG]++;
      g_data.n[IND]++;
    }
  if (g_data.n[ARG] != op_tab[n_ins - 1].nbr_args)
    {
      my_err_msg(one_line.s, NOTENOUGH_ARG, g_data.n[IND] - g_data.n[ARG] - 1);
      return (-1);
    }
  if (op_tab[n_ins - 1].nbr_args != 1 || op_tab[n_ins - 1].code == 16)
    {
      g_data.count++;
      write(g_data.fdw, &encbyte, 1);
    }
  return (1);
}

int		my_check_snd(line_t one_line, labels_t **labels, args_t **args)
{
  int		int_v;
  int		cpt;
  int		n_ins;

  cpt = 0;
  if ((n_ins = my_get_ins_code(one_line, g_data.n[IND])) == -1)
    return (-1);
  n_ins = my_get_ins_code(one_line, g_data.n[IND]);
  g_data.n[IND]++;
  if (my_analyze_args(one_line, n_ins, &labels[CALL], args) == -1)
    return (-1);
  g_data.count++;
  while (cpt < op_tab[n_ins - 1].nbr_args)
    {
      my_conv_to_platform(&args[cpt]->val, args[cpt]->size);
      g_data.count += args[cpt]->size;
      write(g_data.fdw, &args[cpt]->val, args[cpt]->size);
      cpt++;
    }
}

int		my_parse_line(line_t one_line, labels_t **labels)
{
  int		ret;
  int		lb_def;
  args_t	*args[MAX_ARGS_NUMBER];

  lb_def = 0;
  g_data.n[IND] = 0;
  while (one_line.arr[g_data.n[IND]] != NULL)
    {
      if (lb_def == 0 && g_data.n[IND] == 0)
	{
	  if ((ret = is_label_def(one_line, g_data.n[IND], &lb_def)) == 1)
	    my_lab_to_list(&labels[DEF], one_line.arr[g_data.n[IND]], 0, 0);
	  else if (ret == -1)
	    return (-1);
	}
      if ((g_data.n[IND] == 0 && lb_def == 0) || (g_data.n[IND] == 1 && lb_def == 1))
	{
	  if (my_check_snd(one_line, &labels[CALL], args) == -1)
	    return (-1);
	  g_data.n[IND]--;
	}
      g_data.n[IND]++;
    }
  return (1);
}

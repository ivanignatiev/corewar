/*
** write_binary.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Sat Dec  8 16:14:16 2012 arthur sfez
** Last update Tue Dec 11 14:44:52 2012 arthur sfez
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"asm.h"
#include	"op.h"

/*
void		my_write_ins_enc(char **arr, int fdw, int count, char *s)
{
  int		i;
  int		cpt;
  int		enc;

  i = 1;
  enc = 0;
  cpt = 0;
  write(fdw, my_ins_hexa(arr[0]), 1);
  count += 2;
  while (arr[i] != NULL)
    {
      if (i == 4)
	my_err_msg(s, 0, TOOMANY_ARG, my_strstr_int(s, arr[i]));
      if (is_valid_arg(arr[i], arr[0]))
	my_update_enc(&enc);
      else
	my_err_msg(s, 0, UNKNOWN_ARG, my_strstr_int(s, arr[i]));
      i++;
      cpt += 2;
    }
}
*/

void		my_write_hexa(char **arr, char *s, labels_t **labels, int fdw)
{
  int		i;
  int		n_ins;
  int		lb_def;
  args_t	*args; /* <- STOCKAGE DES ARGS */
  static int	count = sizeof(header_t);

  i = 0;
  lb_def = 0;
  while (arr[i] != NULL)
    {
      /*
      if ((lb_def == 0 && i == 0) && is_label_def(arr[i], s, i))
	{
	  lb_def = 1;
	  my_add_to_list(&labels[DEF], arr[i]);
	}
      else if ((i == 0 && lb_def == 0) || (i == 1 && lb_def == 1));
        {
	  if ((n_ins = my_get_ins_code(arr[i], s, i)) != -1)
	    args = my_write_ins_enc(arr + i + 1, s, i, n_ins);
	  else
	    RETURN ERROR;
	}
      else
        {
	  write(fdw, args->val, args->size);
	  args = args->next;
	}
      */
      i++;
    }
}

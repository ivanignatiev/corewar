/*
** seek_write.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Thu Dec 13 18:55:42 2012 arthur sfez
** Last update Sun Dec 16 18:39:12 2012 ivan ignatiev
*/

#include	<sys/types.h>
#include	<unistd.h>
#include	"asm.h"
#include	"cwlib.h"

void		my_err_msg_label(labels_t *calls)
{
  my_puterr("Error at line #");
  my_put_nbr(calls->line);
  my_puterr(" -> Label \"");
  my_puterr(calls->s);
  my_puterr("\" undefined\n");
}

labels_t	*my_check_lab_exists(labels_t *calls, labels_t *defs)
{
  while (defs != NULL)
    {
      if (my_strcmp(calls->s, defs->s) == 0)
	return (defs);
      defs = defs->next;
    }
  my_err_msg_label(calls);
  return (NULL);
}

int		my_seeknwrite(labels_t *calls, labels_t *defs)
{
  int		val;
  labels_t	*tmp;

  while (calls != NULL)
    {
      if ((tmp = my_check_lab_exists(calls, defs)) == NULL)
	return (-1);
      val = tmp->adr - calls->adr + calls->op;
      lseek(g_data.fdw, calls->adr_a, SEEK_SET);
      my_write_btb(g_data.fdw, &val, sizeof(val), calls->size);
      calls = calls->next;
    }
  lseek(g_data.fdw, 136, SEEK_SET);
  val = g_data.count - sizeof(header_t);
  my_conv_to_platform(&val, sizeof(int));
  write(g_data.fdw, &val, sizeof(int));
  return (1);
}

/*
** operators.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Sun Dec 16 11:23:19 2012 arthur sfez
** Last update Sun Dec 16 16:32:26 2012 arthur sfez
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"cwlib.h"
#include	"asm.h"

static char	**my_malloc_members(char *s, int pos)
{
  int		size;
  char		sign;
  char		*tmp;
  char		*tmp2;
  char		**res;

  tmp = my_strdup(s);
  tmp2 = tmp;
  size = 0;
  if ((res = malloc(sizeof(*res) * 2)) == NULL)
    return (NULL);
  sign = tmp[pos];
  tmp[pos] = 0;
  if ((*res = malloc(sizeof(**res) * (pos + 1))) == NULL)
    return (NULL);
  my_strcpy(*res, tmp);
  tmp = tmp + pos + 1;
  if (sign == '+')
    size++;
  if (!(*(res + 1) = malloc(sizeof(**res) * (my_strlen(tmp) + size + 1))))
    return (NULL);
  *res[1] = '-';
  my_strcpy(*(res + 1) + size, tmp);
  free(tmp2);
  return (res);
}

static int	is_alpha(char *s)
{
  int		i;

  i = 0;
  while (*s)
    {
      if ((*s == '+' || *s == '-') && i == 0)
	;
      else if (*s < '0' || *s > '9')
	return (0);
      s++;
      i++;
    }
  return (1);
}

char		*my_init_val(char *s, int pos, args_t *arg)
{
  char		**res;

  if ((res = my_malloc_members(s, pos)) == NULL)
    return (NULL);
  if (is_alpha(*res))
    {
      arg->val = my_getnbr(*res);
      arg->val *= -1;
      return (*(res + 1));
    }
  if (is_alpha(*(res + 1)))
    {
      arg->val = my_getnbr(*(res + 1));
      arg->val *= -1;
      return (*(res));
    }
  return (s);
}

int		my_check_operators(char *s)
{
  int		i;
  int		pos;

  i = 0;
  pos = 0;
  while (s[i])
    {
      if ((s[i] == '+' || s[i] == '-') && i != 0)
	{
	  if (pos != 0)
	    return (my_err_msg(g_data.s, TOOMUCH_OPS, g_data.n[IND]));
	  pos = i;
	}
      i++;
    }
  return (pos);
}

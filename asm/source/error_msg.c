/*
** error_msg.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Fri Dec  7 09:40:48 2012 arthur sfez
** Last update Wed Dec 12 13:50:17 2012 arthur sfez
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"asm.h"

err_t		g_err_tab[] =
  {
    {"Unknown directive", UNKNOWN_CMD},
    {"Syntax error", SYNTAX_ERR},
    {"Unknown mnemonic", UNKNOWN_INS},
    {"Bad argument", UNKNOWN_ARG},
    {"Unterminated string", UNTERMINATED_STR},
    {"Number expected", NUMBER_EXPECTED},
    {"Trailing garbage", TRAILING_GARBAGE},
    {"Too many arguments", TOOMANY_ARG},
    {"Not enough arguments", NOTENOUGH_ARG},
    {"Invalid characters on label", INVALID_CHAR},
    {"Missing label name", MISSING_LABEL_NAME},
  };

int		my_get_line_pos(char *s, int i)
{
  int		j;
  int		cpt;
  int		in_word;
  int		res;

  cpt = -1;
  j = 0;
  in_word = 0;
  res = 0;
  while (s[j])
    {
      if (is_it_separator_asm(s[j], "\t"))
	res += 4;
      if (!is_it_separator_asm(s[j], " ,\t") && in_word == 0)
	{
	  in_word = 1;
	  cpt++;
	  if (cpt == i)
	    return (j + res);
	}
      else if (in_word == 1 && is_it_separator_asm(s[j], " ,\t"))
	in_word = 0;
      j++;
    }
  return (1);
}

void		my_get_err_msg(char *s, int i, int lb_def)
{
  if (i == 0 && lb_def == 0);
    /*LABEL | INS */
  else if (i == 1 && lb_def == 1);
  /*INS*/
  else if ((i > 0 && lb_def == 0) || (i > 1 && lb_def == 1));
  /*ARGS*/
}

void		my_err_msg_header(char *s, int err, int pos)
{
  int		i;

  i = 0;
  my_putstr("Error at line #");
  my_put_nbr(nb_line);
  my_putstr(" : ");
  my_putstr(g_err_tab[err].s);
  my_putchar('\n');
  my_putstr(s);
  my_putchar('\n');
  while (i < pos)
    {
      my_putchar('-');
      i++;
    }
  my_putstr("^\n");
  exit(err);
}


void		my_err_msg(line_t one_line, int err, int pos)
{
  int		i;

  i = 0;
  pos = my_get_line_pos(one_line.s, pos);
  my_putstr("Error at line #");
  my_put_nbr(nb_line);
  my_putstr(" : ");
  my_putstr(g_err_tab[err].s);
  my_putchar('\n');
  my_putstr(one_line.s);
  my_putchar('\n');
  while (i < pos)
    {
      my_putchar('-');
      i++;
    }
  my_putstr("^\n");
  exit(err);
}

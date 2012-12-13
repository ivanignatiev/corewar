/*
** error_msg.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Fri Dec  7 09:40:48 2012 arthur sfez
** Last update Thu Dec 13 16:10:24 2012 arthur sfez
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
    {"Expecting another argument type", BAD_ARGUMENT},
    {"Invalid register value", REG_VALUE}
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

void		special_puterr(char *s)
{
  while (*s)
    {
      if (*s == '\t')
	write(2, "     ", 5);
      else
	write(2, s, 1);
      s++;
    }
}

int		my_err_msg_header(char *s, int err, int pos)
{
  int		i;

  i = 0;
  my_putstr("Error at line #");
  my_put_nbr(g_data.nb_line);
  my_putstr(" : ");
  my_putstr(g_err_tab[err].s);
  my_putchar('\n');
  special_puterr(s);
  my_putchar('\n');
  while (i < pos)
    {
      my_putchar('-');
      i++;
    }
  my_putstr("^\n");
  return (-1);
}

int		my_err_msg(char *s, int err, int pos)
{
  int		i;

  i = 0;
  pos = my_get_line_pos(s, pos);
  my_puterr("Error at line #");
  my_put_nbr(g_data.nb_line);
  my_puterr(" : ");
  my_puterr(g_err_tab[err].s);
  my_puterr("\n");
  special_puterr(s);
  my_puterr("\n");
  while (i < pos)
    {
      my_puterr("-");
      i++;
    }
  my_puterr("^\n");
  return (-1);
}

int		my_err_msg_file(char *s)
{
  my_puterr("Failed to open ");
  my_puterr(s);
  my_puterr("\n");
  return (-1);
}

void		my_success_msg_file(header_t *header, char *s)
{
  my_putstr("Assembling ");
  my_putstr(s);
  my_putstr(":\n\t");
  my_putstr(header->prog_name);
  my_putstr("\n\t");
  my_putstr(header->comment);
  my_putchar('\n');
}

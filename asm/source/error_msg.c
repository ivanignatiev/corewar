/*
** error_msg.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Fri Dec  7 09:40:48 2012 arthur sfez
** Last update Fri Dec 14 17:57:36 2012 arthur sfez
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"asm.h"
#include	"cwlib.h"

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

int		my_err_msg_header(char *s, int err, int pos)
{
  int		i;

  i = 0;
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

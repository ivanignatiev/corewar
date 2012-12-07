/*
** error_msg.c for corewar in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm/source
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Fri Dec  7 09:40:48 2012 arthur sfez
** Last update Fri Dec  7 15:53:25 2012 arthur sfez
*/

#include <unistd.h>
#include <stdlib.h>
#include "asm.h"

err_t		g_err_tab[] =
  {
    {"Unknown directive", UNKNOWN_CMD},
    {"Syntax error", SYNTAX_ERR},
    {"Unknown mnemonic", UNKNOWN_INS},
    {"Bad argument", UNKNOWN_ARG},
    {"Unterminated string", UNTERMINATED_STR},
    {"Number expected", NUMBER_EXPECTED},
    {"Trailing garbage", TRAILING_GARBAGE},
  };

void		my_err_msg(char *s, int line, int err, int pos)
{
  int		i;

  i = 0;
  my_putstr("Error at line #");
  my_put_nbr(line);
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

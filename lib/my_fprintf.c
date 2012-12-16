/*
** my_fprintf.c for corewar in ./lib
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Dec 15 14:33:28 2012 ivan ignatiev
** Last update Sun Dec 16 19:09:14 2012 ivan ignatiev
*/

#include	<stdlib.h>
#include	<stdarg.h>
#include	<unistd.h>
#include	"cwlib.h"

void		my_fput_n_nbr(int fd, long int nbr, int n)
{
  if (n > 1)
    my_fput_n_nbr(fd, nbr / 10, n - 1);
  else if (nbr > 9)
    my_fput_n_nbr(fd, nbr / 10, n);
  my_fputchar(fd, (nbr % 10) + 48);
}

void		my_fputnbr(int fd, const char *format, va_list *ap)
{
  int		zeros;
  long int	nbr;

  zeros = -1;
  if (format[0] >= '0' && format[0] <= '9')
    zeros = my_getnbr((char*)format);
  nbr = va_arg(*ap, long int);
  if (nbr < 0)
    {
      my_fputchar(fd, '-');
      nbr = -nbr;
    }
  my_fput_n_nbr(fd, nbr, zeros);
}

void		my_fputstr(int fd, va_list *ap)
{
  char		*str;

  str = (char*)va_arg(*ap, const char*);
  if (str == NULL)
    return ;
  while (*str != '\0')
    {
      my_fputchar(fd, *str);
      ++str;
    }
}

int		my_parse_percent(int fd, const char *format, va_list *ap)
{
  int		i;
  int		found_format;

  i = 0;
  found_format = 0;
  while (format[i] != '\0' && !found_format)
    {
      if (format[i] == '%')
	{
	  my_fputchar(fd, '%');
	  found_format = 1;
	}
      else if (format[i] == 'l')
	{
	  my_fputnbr(fd, format, ap);
	  found_format = 1;
	}
      else if (format[i] == 's')
	{
	  my_fputstr(fd, ap);
	  found_format = 1;
	}
      ++i;
    }
  return (i);
}

void		my_fprintf(int fd, const char *format, ...)
{
  int		i;
  va_list	ap;

  va_start(ap, format);
  i = 0;
  while (format[i] != '\0')
    {
      if (format[i] == '%')
	{
	  i += 1 + my_parse_percent(fd, format + i + 1, &ap);
	}
      else
	{
	  my_fputchar(fd, format[i]);
	  ++i;
	}
    }
  va_end(ap);
}

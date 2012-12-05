/*
** my.h for my_header in /home/sfez_a//include
** 
** Made by arthur sfez
** Login   <sfez_a@epitech.net>
** 
** Started on  Fri Oct 12 12:02:14 2012 arthur sfez
** Last update Wed Dec  5 17:12:16 2012 arthur sfez
*/

#ifndef MY_H_
# define MY_H_

# define EXIT_FAILURE	1
# define EXIT_SUCCESS	0

void		my_putchar(char);
void		my_put_nbr(int);
int		my_putnbr_base(int, char *);
void		my_putstr(char *);
void		my_puterr(char *);
int		my_strlen(char *);
int		my_getnbr(char *);
int		my_getnbr_base(char *, char *);
int		my_strcmp(char *, char *);
int		my_strncmp(char *, char *, int);
char		*my_strncpy(char *, char *, int);
char		*my_strcat(char *, char *);
char		*my_strncat(char *, char *, int);
char		*my_strdup(char *);
char		*my_memset(char *, int, int);
int		my_power_rec(int, int);

#endif /*MY_H_*/

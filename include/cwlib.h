/*
** cwstring.h for corewar in /home/ignati_i//projects/corewar/corewar-2016ed-2015s-2017si-liu_q/include
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Tue Dec  4 17:04:55 2012 ivan ignatiev
** Last update Thu Dec  6 18:48:26 2012 arthur sfez
*/

#ifndef CWLIB_H_
# define CWLIB_H_

# define BUFFER_SIZE 1024
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

void		my_putchar(char);
int		my_strlen(char *);
void		my_putstr(char *);
void		my_puterr(char *);
char		**my_split_string(char *str, char *separator,
			  int quotes_mode);
int		my_free_array(char **arr);
char		*get_next_line(const int fd);
char		*my_strncpy(char *dest, char *src, int n);
char		**my_add_to_array(char *str, char **arr);

#endif /* CWLIB_H_ */

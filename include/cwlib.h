/*
** cwlib.h for corewar in ./include
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Tue Dec  4 17:04:55 2012 ivan ignatiev
** Last update Tue Dec 11 16:51:00 2012 ivan ignatiev
*/

#ifndef CWLIB_H_
# define CWLIB_H_

# define BUFFER_SIZE		1024
# define EXIT_SUCCESS		0
# define EXIT_FAILURE		1
# define MALLOC_FAILURE		2

void		my_putchar(char);
int		my_strlen(char *);
void		my_putstr(char *);
void		my_puterr(char *);
int		my_strncmp(char *, char *, int);
char		**my_split_string(char *str, char *separator);
char		**my_split_string_asm(char *str, char *separator);
int		my_free_array(char **arr);
char		*get_next_line(const int fd);
char		*my_strncpy(char *dest, char *src, int n);
void		*my_memncpy(void *dest, void *src, int n);
char		**my_add_to_array(char *str, char **arr);
int		is_big_endian(void);
void		*my_bytes_reverse(void *buff, int size);
void		*my_conv_to_platform(void *buf, int sz);
char		*my_strcat(char *dest, char *src);

#endif /* CWLIB_H_ */

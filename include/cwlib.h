/*
** cwlib.h for corewar in ./include
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Tue Dec  4 17:04:55 2012 ivan ignatiev
** Last update Sun Dec 16 14:47:20 2012 ivan ignatiev
*/

#ifndef CWLIB_H_
# define CWLIB_H_

# define BUFFER_SIZE		1024
# define EXIT_SUCCESS		0
# define EXIT_FAILURE		1
# define MALLOC_FAILURE		2
# define OSTD			1
# define OERR			2

int		my_fputchar(int fd, char c);
void		my_putchar(char);
int		my_strlen(char *);
void		my_putstr(char *);
void		my_fprintf(int fd, const char *format, ...);
void		my_puterr(char *);
int		my_strncmp(char *, char *, int);
int		my_strcmp(char *, char *);
int		my_strcpy(char *, char *);
int		my_getnbr(char *s);
char		**my_split_string(char *str, char *separator);
char		**my_split_string_asm(char *str, char *separator);
int		my_free_array(char **arr);
char		*get_next_line(const int fd);
char		*my_strncpy(char *dest, char *src, int n);
void		*my_memncpy(void *dest, void *src, int n, int dest_n);
char		**my_add_to_array(char *str, char **arr);
int		is_big_endian(void);
void		*my_bytes_reverse(void *buff, int size);
void		*my_conv_to_platform(void *buf, int sz);
char		*my_strcat(char *dest, char *src);
char		*my_strdup(char *s);
char		*my_strndup(char *s, int n);
void		my_put_nbr(int n);
int		my_strcmp(char *s1, char *s2);

#endif /* CWLIB_H_ */

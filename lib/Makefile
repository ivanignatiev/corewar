##
## Makefile for libmy in /home/ignati_i//test_c/lib/my
## 
## Made by ivan ignatiev
## Login   <ignati_i@epitech.net>
## 
## Started on  Mon Oct 22 09:36:48 2012 ivan ignatiev
## Last update Fri Dec  7 17:20:00 2012 ivan ignatiev
##

CC	=	cc

AR	=	ar rc
RL	=	ranlib

RM	=	rm -f


CFLAGS	+=	-I../include
CFLAGS	+=	-Wextra	-Werror -Wall
CFLAGS	+=	-pedantic

NAME	=	libcw.a

SRCS	=	get_next_line.c \
		my_add_to_array.c \
		my_free_array.c \
		my_split_string.c \
		my_strncpy.c \
		strings.c \
		my_put_nbr.c \
		my_strncmp.c \
		is_big_endian.c \
		my_endian_convert.c


OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)
$(NAME):	$(OBJS)
		$(AR) $(NAME) $(OBJS)
		$(RL) $(NAME)
clean:
		$(RM) $(OBJS)
fclean:		clean
		$(RM) $(NAME)
re:		fclean all
.PHONY:		all clean fclean re
##
## Makefile for libmy in /home/ignati_i//test_c/lib/my
## 
## Made by ivan ignatiev
## Login   <ignati_i@epitech.net>
## 
## Started on  Mon Oct 22 09:36:48 2012 ivan ignatiev
## Last update Wed Dec  5 16:29:09 2012 arthur sfez
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
		my_strncpy.c


OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)
$(NAME):	$(OBJS)
		$(AR) ../bin/lib/$(NAME) $(OBJS)
		$(RL) ../bin/lib/$(NAME)
clean:
		$(RM) $(OBJS)
fclean:		clean
		$(RM) $(NAME)
re:		fclean all
.PHONY:		all clean fclean re
##
## Makefile for minishell1 in /home/ignati_i//test_c/minishell1
## 
## Made by ivan ignatiev
## Login   <ignati_i@epitech.net>
## 
## Started on  Sat Nov  3 01:52:16 2012 ivan ignatiev
## Last update Wed Dec  5 14:13:27 2012 ivan ignatiev
##

SRCS	=	dasm.c

CFLAGS	+=	-Wall -Werror
CFLAGS	+=	-pedantic -Wextra
CFLAGS	+=	-I../include

LDFLAGS +=	-lcw -L../bin/lib

NAME	=	mysh

OBJS	=	$(SRCS:.c=.o)

CC	=	cc

RM	=	rm -f


all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o ../bin/$(NAME) $(OBJS) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		re all fclean clean

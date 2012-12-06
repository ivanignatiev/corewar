##
## Makefile for minishell1 in /home/ignati_i//test_c/minishell1
## 
## Made by ivan ignatiev
## Login   <ignati_i@epitech.net>
## 
## Started on  Sat Nov  3 01:52:16 2012 ivan ignatiev
## Last update Thu Dec  6 18:03:47 2012 arthur sfez
##

SRCS	=	dasm.c

CFLAGS	+=	-Wall -Werror
CFLAGS	+=	-pedantic -Wextra
CFLAGS	+=	-I../include

LDFLAGS +=	-lcw -L../lib

NAME	=	dasm

OBJS	=	$(SRCS:.c=.o)

CC	=	cc

RM	=	rm -f


all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)
		cp $(NAME) ../bin/$(NAME)
clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		re all fclean clean

##
## Makefile for asm in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm
## 
## Made by arthur sfez
## Login   <sfez_a@epitech.net>
## 
## Started on  Wed Dec  5 16:32:59 2012 arthur sfez
## Last update Wed Dec  5 17:06:42 2012 arthur sfez
##

SRCS	=	source/main.c \

OBJS	=	$(SRCS:.c=.o)

NAME	=	asm

CFLAGS	+=	-Wall -Werror -Wextra
CFLAGS	+=	-pedantic -ansi

LIB	=	-lmy -Llib/

RM	=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LIB)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		re all fclean clean

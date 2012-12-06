##
## Makefile for asm in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm
## 
## Made by arthur sfez
## Login   <sfez_a@epitech.net>
## 
## Started on  Wed Dec  5 16:32:59 2012 arthur sfez
## Last update Thu Dec  6 10:52:44 2012 arthur sfez
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
		(cd lib/my/ && $(MAKE))
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LIB)

clean:
		(cd lib/my/ && $(MAKE) clean)
		$(RM) $(OBJS)

fclean:		clean
		(cd lib/my/ && $(MAKE) fclean)
		$(RM) $(NAME)

re:		fclean all

.PHONY:		re all fclean clean

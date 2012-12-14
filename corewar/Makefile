##
## Makefile for minishell1 in /home/ignati_i//test_c/minishell1
## 
## Made by ivan ignatiev
## Login   <ignati_i@epitech.net>
## 
## Started on  Sat Nov  3 01:52:16 2012 ivan ignatiev
## Last update Fri Dec 14 17:25:50 2012 ivan ignatiev
##

SRCS	=	corewar.c \
		list.c \
		program/load.c \
		program/instr.c \
		program/args.c \
		memory/dump.c \
		memory/managment.c \
		memory/memory.c \
		memory/memcpy.c \
		instrs/live.c \
		instrs/ld.c \
		instrs/st.c \
		instrs/add.c \
		instrs/sub.c \
		instrs/and.c \
		instrs/or.c \
		instrs/xor.c \
		instrs/zjmp.c \
		instrs/ldi.c \
		instrs/sti.c \
		instrs/fork.c \
		instrs/lld.c \
		instrs/lldi.c \
		instrs/lfork.c \
		instrs/aff.c \
		../lib/op.c

#CFLAGS	+=	-Werror
CFLAGS	+=	-Wall -pedantic -Wextra
CFLAGS	+=	-I../include

LDFLAGS +=	-lcw -L../lib

NAME	=	corewar

OBJS	=	$(SRCS:.c=.o)

CC	=	cc

RM	=	rm -f


all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)
		cp $(NAME) ../bin/
clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		re all fclean clean

##
## Makefile for corewar in ./corewar
## 
## Made by ivan ignatiev
## Login   <ignati_i@epitech.net>
## 
## Started on  Sat Nov  3 01:52:16 2012 ivan ignatiev
## Last update Sun Dec 16 16:34:17 2012 ivan ignatiev
##

SRCS	=	corewar.c \
		list.c \
		list_clear.c \
		args.c \
		war.c \
		program/load.c \
		program/instr.c \
		program/args.c \
		program/dasm.c \
		memory/dump.c \
		memory/managment.c \
		memory/memory.c \
		memory/memcpy.c \
		instrs/list.c \
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

CFLAGS	+=	-Werror
CFLAGS	+=	-Wall -pedantic -Wextra
CFLAGS	+=	-I../include

LIBNAME =	../lib/libcw.a
LIBDIR	=	../lib/
LDFLAGS =	-lcw -L$(LIBDIR)

NAME	=	corewar

OBJS	=	$(SRCS:.c=.o)

CC	=	cc
MAKE	=	make -C

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(LIBNAME) $(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)
		cp $(NAME) ../bin/
$(LIBNAME):
		$(MAKE) $(LIBDIR)
clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		re all fclean clean

##
## Makefile for asm in /home/sfez_a//Local/projets_svn/corewar-2016ed-2015s-2017si-liu_q/asm
## 
## Made by arthur sfez
## Login   <sfez_a@epitech.net>
## 
## Started on  Wed Dec  5 16:32:59 2012 arthur sfez
## Last update Wed Dec 12 16:29:39 2012 arthur sfez
##

SRCS	=	source/main.c \
		source/my_split_string_asm.c \
		source/is_instruction.c \
		source/compile_file.c \
		source/fill_header.c \
		source/error_msg.c \
		source/write_binary.c \
		source/check_label.c \
		source/strings.c \
		source/lists.c \
		source/check_args.c \
		source/check_register.c \
		source/check_direct.c \
		../lib/op.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	asm

#CFLAGS	+=	-Wall -Werror -Wextra
#CFLAGS	+=	-pedantic -ansi
CFLAGS	+=	-I../include/ -g3

LIB	=	-lcw -L../lib/

RM	=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LIB)
		cp $(NAME) ../bin/

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)
		$(RM) ../bin/$(NAME)

re:		fclean all

.PHONY:		re all fclean clean

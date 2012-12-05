##
## Makefile for Makefile in /home/sfez_a//Local/lib/my
## 
## Made by arthur sfez
## Login   <sfez_a@epitech.net>
## 
## Started on  Mon Oct 22 09:31:08 2012 arthur sfez
## Last update Wed Dec  5 11:01:11 2012 arthur sfez
##

SRC=		my_getnbr.c \
		my_getnbr_base.c \
		my_putchar.c \
		my_put_nbr.c \
		my_putnbr_base.c \
		my_power_rec.c \
		my_putstr.c \
		my_puterr.c \
		my_strcat.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strdup.c \
		my_strlen.c \
		my_strncat.c \
		my_strncmp.c \
		my_memset.c \
		get_next_line.c \
		my_add_to_array.c \
		my_free_array.c \
		my_split_string.c \

NAME=		libmy.a

OBJ=		$(SRC:.c=.o)

CP=		cp

RM=		rm -f

CFLAGS=		-Wall -Werror -ansi

CC	+=	-I../../include

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)
		$(CP) $(NAME) ..

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)
		$(RM) ../$(NAME)
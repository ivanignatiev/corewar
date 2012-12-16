##
## Makefile for corewar in ./corewar
## 
## Made by ivan ignatiev
## Login   <ignati_i@epitech.net>
## 
## Started on  Sat Nov  3 01:52:16 2012 ivan ignatiev
## Last update Sun Dec 16 21:34:18 2012 ivan ignatiev
##

ASM	=	./asm/
COREWAR	=	./corewar/
LIB	=	./lib/

MAKE	=	make -C

all:
		$(MAKE)	$(LIB)
		$(MAKE) $(ASM)
		$(MAKE) $(COREWAR)
clean:
		$(MAKE)	$(LIB) clean
		$(MAKE) $(ASM) clean
		$(MAKE) $(COREWAR) clean
fclean:
		$(MAKE)	$(LIB) fclean
		$(MAKE) $(ASM) fclean
		$(MAKE) $(COREWAR) fclean
re:		fclean all
.PHONY:		re all fclean clean

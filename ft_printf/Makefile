SRCS            = ft_printc.c ft_printcapitalx.c ft_printf.c ft_printi.c \
				ft_printp.c ft_prints.c ft_printu.c ft_printx.c

OBJS            = $(SRCS:.c=.o)
CC              = gcc
RM              = rm -f
CFLAGS          = -Wall -Wextra -Werror -I.
NAME            = libftprintf.a
all:            $(NAME)
$(NAME):        $(OBJS)
				ar rcs $(NAME) $(OBJS)
clean:
				$(RM) $(OBJS)
fclean:         clean
				$(RM) $(NAME)
re:             fclean $(NAME)
.PHONY:         all clean fclean re bonus

SRCS = 	so_long.c move.c checker1.c checker2.c checker3.c \
		gnl/get_next_line_utils.c gnl/get_next_line.c map.c
		
OBJS = $(SRCS:.c=.o)

SRCS_BNS = 	bonus/so_long_bonus.c bonus/move_bonus.c bonus/checker1_bonus.c \
		bonus/checker2_bonus.c bonus/checker3_bonus.c bonus/map_bonus.c \
		gnl/get_next_line_utils.c gnl/get_next_line.c
OBJS_BNS = $(SRCS_BNS:.c=.o)

LIBFT			= cd libft && make
LIB1			= libft/libft.a

PRINTF			= cd ft_printf && make
LIB2			= ft_printf/libftprintf.a

MLX				= cd mlx && make
LIB3			= mlx/libmlx.a

CC = gcc
FLAGS = -Wall -Wextra -Werror -I include
LFLAGS = -framework AppKit -framework OpenGL -L ./mlx -lmlx
RM = rm -f

NAME = so_long
NAME_BNS = so_long_bonus
	
all: libft ft_printf mlx $(NAME)
bonus: libft ft_printf mlx $(NAME_BNS)

libft:		
				@$(LIBFT)

ft_printf:		
				@$(PRINTF)

mlx:
				@$(MLX)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(LFLAGS) $(OBJS) $(LIB1) $(LIB2) $(LIB3) -o $(NAME)

$(NAME_BNS): $(OBJS_BNS)
	@$(CC) $(FLAGS) $(LFLAGS) $(OBJS_BNS) $(LIB1) $(LIB2) $(LIB3) -o $(NAME_BNS)
	
clean:
				$(RM) $(OBJS)
				$(RM) $(OBJS_BNS)
				@cd libft && make clean
				@cd ft_printf && make clean
				@cd mlx && make clean
fclean:         clean
				$(RM) $(NAME)
				$(RM) $(NAME_BNS)
				@cd ft_printf && make fclean
				@cd libft && make fclean  
re:             fclean all
.PHONY:         all libft ft_printf mlx bonus clean fclean re


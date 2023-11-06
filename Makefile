RED				=	\x1B[31m
GRN				=	\x1B[32m
YEL				=	\x1B[33m
BLU				=	\x1B[34m
MAG				=	\x1B[35m
CYN				=	\x1B[36m
WHT				=	\x1B[37m
RESET			=	\x1B[0m
CLE 			=	\e[1;1H\e[2J

NAME			=	Cub3D

LIBFT			=	libft.a
LIBFT_DIR		=	lib/lib_ft/

PARSE_LIB		=	parsing.a
PARSE_DIR		=	parsing/

MLX_LIB		=	libmlx.a
MLX_DIR		=	lib/minilibx_opengl_20191021/

# Compiler and flags
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -g
#-fsanitize=address
RM				=	rm -f

# Sources are all .c files
SRCS	=	main.c

OBJS	=	$(SRCS:.c=.o)

USER = $(shell whoami)

all: mlx libft parse $(NAME)
	@printf "$(CYN) \n\n			correction is made by $(USER)\n\n  $(RESET)\n"
	
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)$(LIBFT) $(MLX_DIR)$(MLX_LIB) -framework OpenGL -framework AppKit \
	$(PARSE_DIR)$(PARSE_LIB) -o $(NAME)
libft:
	@printf "$(GRN)making libft$(WHT)\n"
	@make -C $(LIBFT_DIR)

parse:
	@printf "$(GRN)making parsing$(WHT)\n"
	@make -C parsing

mlx:
	@make -C $(MLX_DIR)

mem: all
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes ./$(NAME)

#https://github.com/sm222/C_tools

# Removes objects
clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_DIR)     clean
	@make -C $(MLX_DIR)   clean
	@make -C parsing		  clean
	@echo $(shell clear)
	@printf "$(GRN)clean *.o$(RESET)\n"

# Removes objects and executables
fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR)     fclean
	@make -C parsing		  fclean
	@echo $(shell clear)
	@printf "$(GRN)clean all$(RESET)\n"

run: all
	@./$(NAME)

mc: all clean

re: fclean all

cp:
	cp supp.txt /tmp

norm:
	norminette *.c parsing include lib/lib_ft

.PHONY: all libft run mc
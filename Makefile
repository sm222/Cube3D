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

RENDER_LIB		=	render.a
RENDER_DIR		=	render/

MLX_LIB		=	libmlx.a
MLX_DIR		=	lib/minilibx_opengl_20191021/

# Compiler and flags
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -g
#-fsanitize=address
RM				=	rm -f

# Sources are all .c files
SRCS	=	main.c\
			debugft.c

OBJS	=	$(SRCS:.c=.o)

USER = $(shell whoami)

all: C_tool mlx libft parse render $(NAME)
	@printf "$(CYN) \n\n			correction is made by $(USER)\n\n  $(RESET)\n"
	
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)$(LIBFT) $(RENDER_DIR)$(RENDER_LIB) \
	$(PARSE_DIR)$(PARSE_LIB) $(MLX_DIR)$(MLX_LIB) \
	-framework OpenGL -framework AppKit C_tools/C_tool.a -o $(NAME)

libft:
	@printf "$(GRN)making libft$(WHT)\n"
	@make -C $(LIBFT_DIR)

C_tool:
	make -C C_tools

render:
	@printf "$(GRN)making render$(WHT)\n"
	make -C $(RENDER_DIR)

parse:
	@printf "$(GRN)making parsing$(WHT)\n"
	@make -C parsing

mlx:
	@make -C $(MLX_DIR)

mem:
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes ./$(NAME) map/map2.cub

#https://github.com/sm222/C_tools

# Removes objects
clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_DIR)	clean
	@make -C C_tools		clean
	@make -C $(MLX_DIR)		clean
	@make -C parsing		clean
	@make -C render			clean
	@echo $(shell clear)
	@printf "$(GRN)clean *.o$(RESET)\n"
	@rm -fr Cub3D.dSYM

# Removes objects and executables
fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR)		fclean
	@make -C parsing			fclean
	@make -C C_tools			fclean
	@make -C render				fclean
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

.PHONY: all libft run mc render

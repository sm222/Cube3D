NAME	=	parsing.a

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -g
RM		=	rm -f

LIBFT		=	libft.a
LIBFT_DIR	=	../lib/lib_ft/

SRCS	=	clean_parsing.c\
			parsing_map.c\
			parsing.c\
			parsing_err.c\
			parsing_extrac.c\
			parsing_look_char.c\
			parsing_texture.c\
			parsing_util.c\
			read_map.c\
			flood_fill.c\
			parsing_extrac_utils.c\
			flood_fill_utils.c\


OBJS	=	$(SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBFT_DIR)$(LIBFT)
	@cp $(LIBFT_DIR)$(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)

all: $(LDIR)$(LIBFT) $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
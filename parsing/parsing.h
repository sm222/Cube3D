
#ifndef PARSING_H
# define PARSING_H

# include <fcntl.h>
# include <stdbool.h>
# include "../include/structure.h"
# include "../lib/lib_ft/libft.h"


// use
t_map	parsing(char *arg, t_cub *cub);
t_err	extract_map(t_parsing *data);

t_err	read_map(t_parsing *data);
t_err	parsing_err(t_parsing *data, t_err err);
int		open_file(t_parsing *data, char *file);

short	clean_parsing(t_parsing *data);
t_err	parsing_look_c(t_parsing *data);
short	clean_wall_name(t_parsing *data);
t_err	extract_texture(t_parsing *data);
char	*extract_line_txt(t_str *str, t_err *err);

int		look_all_texture(t_texture *in);
void	set_value(char side[5][5], t_parsing *data);

size_t	skip_while(t_str *str, char c);
size_t	skip_to(t_str *str, char c);

t_err	extract_line_nbr(t_str *str, t_parsing *data, short c);
size_t	read_and_set_err_p(size_t in, short set_get);
t_err	set_err_and_return_code(size_t len, t_err code);

int		call_flood_fill(t_map in, t_parsing *data);
t_map	make_safe_copy(t_map const map, size_t const max_len);

short	look_at_end(t_str *str);
short	look_next(char *s, size_t i, short ver);
short	look_last_number(char const *s, size_t i);

t_err	skip_to_next_nbr(t_str *str, int nbr);
short	find_spawn(int *x, int *y, const t_map map);
char	rt_char(char c);

#endif // PARSING_H
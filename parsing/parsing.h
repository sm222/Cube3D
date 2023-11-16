
#ifndef PARSING_H
# define PARSING_H

# include <fcntl.h>
# include <stdbool.h>
# include "../include/structure.h"
# include "../lib/lib_ft/libft.h"

// use
t_map	parsing(char *arg);

t_err	read_map(t_parsing *data);
t_err	parsing_err(t_parsing *data, t_err err);
int		open_file(t_parsing *data, char *file);

t_err	parsing_look_c(t_parsing *data);
t_err	extract_texture(t_parsing *data);
char	*extract_line_txt(char *s, t_err *err);
short	clean_parsing(t_parsing *data);

int		look_all_texture(t_texture *in);
void	set_value(char in[5][5], t_parsing *data);

size_t	skip_space(const char *s);
size_t	skip_to(const char *s, char c);

t_err	extract_line_nbr(char *s, t_parsing *data, short c);

#endif // PARSING_H

#ifndef PARSING_H
# define PARSING_H

#include <fcntl.h>
#include <stdbool.h>
#include "../include/structure.h"
#include "../lib/lib_ft/libft.h"

enum side_tex {
	no,
	so,
	we,
	ea,
};

t_map	parsing(char *arg);
t_err	read_map(t_parsing *data);
t_err	parsing_err(t_parsing *data, t_err err);
t_err	parsing_look_c(t_parsing *data);
int		open_file(t_parsing *data, char *file);
t_err	extract_texture(t_parsing *data);

#endif // PARSING_H

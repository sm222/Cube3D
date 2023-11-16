
#include "parsing.h"

size_t	read_and_set_err_p(size_t in, short set_get)
{
	size_t	*i;

	i = ft_return_ptr(NULL, e_p_err_index);
	if (set_get == e_set)
		*i = in;
	if (set_get == e_add)
		(*i) += in;
	return (*i);
}

static t_err	look_all(t_parsing *data)
{
	t_err		rvalue;

	rvalue = 0;
	rvalue += parsing_err(data, read_map(data));
	if (rvalue < e_success)
		return (rvalue);
	rvalue += parsing_err(data, parsing_look_c(data));
	if (rvalue < e_success)
		return (rvalue);
	extract_texture(data);
	clean_parsing(data);
	return (e_success);
}

t_map	parsing(char *arg)
{
	t_parsing	data;
	t_err		rvalue;

	rvalue = 0;
	ft_bzero(&data, sizeof(t_parsing));
	ft_return_ptr(&data, e_parsing);
	ft_return_ptr(&data.err_p, e_p_err_index);
	if (!arg)
		return (NULL);
	data.map_name = arg;
	if (open_file(&data, arg) == -1)
		return (NULL);
	if (look_all(&data) < e_success)
		return (NULL);
	return (data.map);
}

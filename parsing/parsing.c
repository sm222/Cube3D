
#include "parsing.h"

/// @brief use to set a err len for the print of the red line
/// @param in 
/// @param set_get 
/// @return 
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

/// @brief make all the verification one by one
/// @param data
/// @return a t_err flag
static t_err	look_all(t_parsing *data)
{
	t_err	rvalue;

	rvalue = 0;
	rvalue += parsing_err(data, read_map(data));
	if (rvalue < e_success)
		return (rvalue);
	rvalue += parsing_err(data, parsing_look_c(data));
	if (rvalue < e_success)
		return (rvalue);
	rvalue = extract_texture(data);
	if (rvalue < e_success)
		return (rvalue);
	if (extract_map(data) < e_success)
	{
		clean_parsing(data);
		return (e_fail);
	}
	data->pre_map = (t_map)ft_double_sfree((void **)data->pre_map);
	return (e_success);
}

/// @brief use to make and parse a map
/// @param arg name of the file
/// @param cub the main struc
/// @return map if sucsess or NULL if error
t_map	parsing(char *arg, t_cub *cub)
{
	t_parsing	data;

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
	ft_memcpy(&cub->pars, &data, sizeof(t_parsing));
	return (data.map);
}

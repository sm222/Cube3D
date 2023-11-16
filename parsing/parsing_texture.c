
#include "parsing.h"

static short	print_err(t_err code, char *line, size_t i)
{
	if (code != e_empty_line && code < e_success)
	{
		ft_printf(2, "%oError\n", NULL);
		if (code == e_bad_char)
			ft_printf(2, "%o[%d] bad char: %s\n", NULL, i, line);
		if (code == e_bad_number)
			ft_printf(2, "%o[%d] bad number: %s\n", NULL, i, line);
		if (code == e_double_card)
			ft_printf(2, "%o[%d] double cord: %s\n", NULL, i, line);
		return (1);
	}
	return (0);
}

static t_err	look_data_fc(char *s, t_parsing *data)
{
	if (ft_strncmp(s, "C ", 2) == 0 && !data->texture.cf[0])
		return (extract_line_nbr(s, data, 0));
	else if (ft_strncmp(s, "C ", 2) == 0 && data->texture.cf[0])
	{
		ft_printf(2, "ici %s\n", s);
		return (e_double_card);
	}
	else if (ft_strncmp(s, "F ", 2) == 0 && !data->texture.cf[1])
		return (extract_line_nbr(s, data, 1));
	else if (ft_strncmp(s, "F ", 2) == 0 && data->texture.cf[1])
	{
		ft_printf(2, "ici %s\n", s);
		return (e_double_card);
	}
	return (e_bad_char);
}

static t_err	look_data_str(char *s, t_extract_t *var, t_parsing *data)
{
	size_t	j;

	j = 0;
	while (j < 4)
	{
		if (ft_strncmp(s, var->name[j], 3) == 0 && \
		!data->texture.side[j])
		{
			data->texture.side[j] = extract_line_txt(s, &var->err);
			return (e_success);
		}
		else if (ft_strncmp(s, var->name[j], 3) == 0 && \
			data->texture.side[j])
			return (e_double_card);
		j++;
	}
	return (look_data_fc(s, data));
}

static t_err	read_line_texture(char *line, t_extract_t *var, t_parsing *data)
{
	size_t	i;
	t_err	err;

	i = skip_space(line);
	if (line[i])
	{
		err = look_data_str(line + i, var, data);
		if (err == e_bad_number)
			return (err);
		if (look_all_texture(&data->texture) != 6 && err == e_bad_char)
			return (e_fail);
	}
	else
		return (e_empty_line);
	return (err);
}

/// @brief 
/// @param data 
/// @return 
t_err	extract_texture(t_parsing *data)
{
	t_extract_t	var;

	ft_bzero(&var, sizeof(t_extract_t));
	set_value(var.name, data);
	while (data->pre_map && data->pre_map[var.line])
	{
		var.err = read_line_texture(data->pre_map[var.line], &var, data);
		if (print_err(var.err, data->pre_map[var.line], var.line + 1))
			break ;
		var.line++;
	}
	printf("no%s\n", data->texture.side[e_no]);
	printf("so%s\n", data->texture.side[e_so]);
	printf("we%s\n", data->texture.side[e_we]);
	printf("ea%s\n", data->texture.side[e_ea]);
	printf("C %d,%d,%d\n", data->texture.celing[0], data->texture.celing[1], data->texture.celing[2]);
	printf("F %d,%d,%d\n", data->texture.flore[0], data->texture.flore[1], data->texture.flore[2]);
	return (0);
}

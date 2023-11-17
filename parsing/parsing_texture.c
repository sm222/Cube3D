
#include "parsing.h"

static short	print_err(t_err code, char *line, size_t i)
{
	size_t	j;

	j = read_and_set_err_p(0, e_get);
	if (code == e_end_of_tex)
		return (1);
	if (code != e_empty_line && code < e_success)
	{
		ft_printf(2, "%oError\n", NULL);
		if (code == e_bad_char)
			ft_printf(2, "%o[%d] bad char: \n%s\n", NULL, i, line);
		if (code == e_bad_number)
			ft_printf(2, "%o[%d] bad number: \n%s\n", NULL, i, line);
		if (code == e_double_card)
			ft_printf(2, "%o[%d] double cord: \n%s\n", NULL, i, line);
		if (code == e_inva_data_end)
			ft_printf(2, "%o[%d] "INVA_DATA_END"\n%s\n", NULL, i, line);
		if (code == e_inva_arg)
			ft_printf(2, "%o[%d] ivalid argument\n%s\n", NULL, i, line);
		ft_print_err_len(j);
		return (1);
	}
	return (0);
}

static t_err	look_data_fc(char *s, t_parsing *data)
{
	if (ft_strncmp(s, "C ", 2) == 0 && !data->texture.cf[0])
		return (extract_line_nbr(s, data, 0));
	else if (ft_strncmp(s, "C ", 2) == 0 && data->texture.cf[0])
		return (e_double_card);
	else if (ft_strncmp(s, "F ", 2) == 0 && !data->texture.cf[1])
		return (extract_line_nbr(s, data, 1));
	else if (ft_strncmp(s, "F ", 2) == 0 && data->texture.cf[1])
		return (e_double_card);
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
			return (var->err);
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
	
	err = e_success;
	read_and_set_err_p(0, e_set);
	i = skip_space(line);
	read_and_set_err_p(i, e_add);
	if (line[i])
	{
		err = look_data_str(line + i, var, data);
		if (err < e_success)
		{
			if (look_all_texture(&data->texture) == 6)
				return (e_end_of_tex);
			return (err);
		}
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
		if (print_err(var.err, data->pre_map[var.line], var.line + 1) < e_success)
			break ;
		var.line++;
	}
	data->i = var.line;
	//while (data->pre_map && data->pre_map[var.line])
	//{
	//	printf("%s\n", data->pre_map[var.line++]);
	//}
	return(e_success);
}

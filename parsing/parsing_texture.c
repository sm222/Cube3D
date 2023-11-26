
#include "parsing.h"

static short	print_err(t_err code, char *line, size_t i)
{
	size_t	j;

	j = read_and_set_err_p(0, e_get);
	if (code == e_end_of_tex)
		return (e_end_of_tex);
	if (code < e_success && code != e_empty_line)
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
		return (code);
	}
	return (1);
}

static t_err	look_data_fc(t_str *str, t_parsing *data)
{
	printf("ici--%s\n", str->s + str->i);
	if (ft_strncmp(str->s + str->i, "C", 1) == 0 && !data->texture.cf[0])
		return (extract_line_nbr(str, data, 0));
	else if (ft_strncmp(str->s + str->i, "C", 1) == 0 && data->texture.cf[0])
		return (e_double_card);
	else if (ft_strncmp(str->s + str->i, "F", 1) == 0 && !data->texture.cf[1])
		return (extract_line_nbr(str, data, 1));
	else if (ft_strncmp(str->s+ str->i, "F", 1) == 0 && data->texture.cf[1])
		return (e_double_card);
	return (e_bad_char);
}

static t_err	look_data_str(t_str *str, t_extract_t *var, t_parsing *data)
{
	size_t	j;

	j = 0;
	while (j < 4 && str->i - str->len > 3)
	{
		if (ft_strncmp(str->s + str->i, var->name[j], 2) == 0 && \
		!data->texture.side[j] && str->s[str->i + 2] == ' ')
		{
			data->texture.side[j] = extract_line_txt(str, &var->err);
			return (var->err);
		}
		else if (ft_strncmp(str->s + str->i, var->name[j], 2) == 0 && \
		data->texture.side[j] && str->s[str->i + 2] == ' ')
			return (e_double_card);
		j++;
	}
	return (look_data_fc(str, data));
}

static t_err	read_line_textu(t_str *str, t_extract_t *var, t_parsing *data)
{
	size_t	i;
	t_err	err;

	err = e_success;
	read_and_set_err_p(0, e_set);
	i = skip_while(str, ' ');
	read_and_set_err_p(i, e_add);
	if (str->i != str->len)
	{
		err = look_data_str(str , var, data);
		if (err < e_success)
			return (err);
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
	t_str		str;

	ft_bzero(&var, sizeof(t_extract_t));
	set_value(var.name, data);
	while (data->pre_map && data->pre_map[var.line])
	{
		ft_str_set(data->pre_map[var.line], &str, true);
		var.err = read_line_textu(&str, &var, data);
		if (var.err == e_bad_char && look_all_texture(&data->texture) == 6)
		{
			data->i = var.line;
			return (e_success);
		}
		if (print_err(var.err, data->pre_map[var.line], \
		var.line + 1) < e_success)
			break ;
		var.line++;
	}
	data->i = var.line;
	return (e_fail);
}

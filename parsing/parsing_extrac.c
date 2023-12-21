# include "parsing.h"

static t_err	look_end(t_str *str)
{
	while (str->i < str->len)
	{
		if (str->s[str->i] != ' ')
			return (set_err_and_return_code(str->i, e_inva_arg));
		str->i++;
	}
	return (e_success);
}

static t_err	get_nbr(t_str *str, t_color color[3])
{
	size_t	j;
	int		tmp;

	skip_while(str, ' ');
	j = 0;
	if (str->s[str->i] == ',')
		return (set_err_and_return_code(str->i, e_inva_arg));
	while (j < 3)
	{
		skip_while(str, ' ');
		tmp = ft_atoi(str->s + str->i);
		if (tmp > 255)
			return (set_err_and_return_code(str->i, e_bad_number));
		color[j] = tmp;
		skip_to_next_nbr(str, tmp);
		j++;
	}
	return (look_end(str));
}

static int	set_up(t_str *str)
{
	str->i++;
	str->j = str->i;
	while (str->j < str->len)
	{
		if (str->s[str->j] == ',')
			return (set_err_and_return_code(str->j, e_bad_char));
		else if (ft_isdigit(str->s[str->j]))
			return (e_success);
		else if (str->s[str->j] == ' ')
			str->j++;
		else
			return (set_err_and_return_code(str->j, e_inva_arg));
	}
	return (e_empty_line);
}

/// @brief ft_isdigit(s[i]) || s[i] == ',' || s[i] == ' ')
/// @param str 
/// @param data 
/// @param c 
/// @return 
t_err	extract_line_nbr(t_str *str, t_parsing *data, short c)
{
	short	vergul;

	if (set_up(str) < e_success)
		return (e_inva_arg);
	vergul = 0;
	while (str->j < str->len && ft_strchr("0123456789 ,", str->s[str->j]))
	{
		if (str->s[str->j] == ',')
		{
			if (look_next(str->s, str->j + 1, ++vergul))
				return (e_bad_char);
		}
		str->j++;
		read_and_set_err_p(1, e_add);
	}
	data->texture.cf[c] = true;
	if (str->j == str->len && vergul == 2 && look_last_number(str->s, str->j))
	{
		if (c == 0)
			return (get_nbr(str, data->texture.celing));
		if (c == 1)
			return (get_nbr(str, data->texture.flore));
	}
	return (set_err_and_return_code(str->j, e_inva_arg));
}

char	*extract_line_txt(t_str *str, t_err *err)
{
	char	*new;

	new = NULL;
	str->i += 2;
	while (str->s && str->i && str->s[str->i] == ' ')
		str->i++;
	while (str->s && str->i + str->j < str->len && \
	str->s[str->i + str->j] != ' ')
		str->j++;
	if (look_at_end(str))
	{
		*err = e_inva_data_end;
		return (NULL);
	}
	new = ft_strndup(str->s + str->i, str->j);
	*err = e_success;
	if (!new)
	{
		printf("moi4\n");
		*err = e_inva_arg;
	}
	return (new);
}

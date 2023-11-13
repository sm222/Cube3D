# include "parsing.h"

static short	look_at_end(char *end)
{
	size_t	i;

	i = 0;
	if (!end || !end[0])
		return (0);
	while (end[i] && end[i] == ' ')
		i++;
	if (!end[i])
		return (0);
	return (1);
}

void	extract_line_nbr(char *s, t_extract_t *var, t_parsing *data, short c)
{
	printf("%s\n", s);
	data->texture.cf[c] = true;
	(void)var;
}

char *extract_line_txt(char *s, t_err *err)
{
	char	*new;
	size_t	i;
	size_t	j;

	new = NULL;
	i = 2;
	j = 0;
	while (s && s[i] && s[i] == ' ')
		i++;
	while (s && s[i + j] && s[i + j] != ' ')
		j++;
	if (look_at_end(s + i + j))
	{
		ft_printf(2, "Error\n");
		ft_printf(2, "%oCub: invalid char after data\n", NULL);
		*err = e_bad_char;
		return (NULL);
	}
	new = ft_strndup(s + i, j);
	*err = e_success;
	return (new);
}

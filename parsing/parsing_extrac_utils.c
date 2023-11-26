
#include "parsing.h"

short	look_at_end(t_str *str)
{
	size_t	i;

	i = 0;
	if (str->i + str->j > str->len)
		return (0);
	while (str->i + str->j < str->len && str->s[str->i + str->j] == ' ')
		str->j++;
	if (!str->s[str->i + str->j])
		return (0);
	return (1);
}

short	look_next(char *s, size_t i)
{
	while (s && s[i])
	{
		if (s[i] == ',')
			return (1);
		else if (ft_isdigit(s[i]))
			return (0);
		else
			i++;
	}
	return (0);
}

short	look_last_number(char *s, size_t i)
{
	while (i > 0)
	{
		if (ft_isdigit(s[i]))
			return (1);
		if (s[i] == ',')
			return (0);
		i--;
	}
	return (0);
}

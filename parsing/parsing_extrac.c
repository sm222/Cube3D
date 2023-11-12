# include "parsing.h"

char *extract_line(const char *s, t_err *err)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	new = NULL;
	while (s && s[i] && s[i] != ' ')
		i++;
	j = i;
	while (s && s[j] && s[j] == ' ')
		j++;
	if (s[j])
	{
		ft_printf(2, "Error\n");
		ft_printf(2, "%oCub: invalid char after data\n", NULL);
		*err = e_bad_char;
		return (NULL);
	}
	printf("%s ici\n", s);
	new = ft_strndup(s, i);
	*err = e_success;
	return (new);
}

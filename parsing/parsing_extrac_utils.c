
#include "parsing.h"

/// @brief look for the size of a int
/// @param nb number
/// @return len in number len char[]
static int	size_int(int long nb)
{
	int	size;

	size = 1;
	if (nb < 0)
	{
		size++;
		nb *= -1;
	}
	while (nb > 9)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

/// @brief use to skip ... to next number
/// @param str t_str input
/// @param nbr number to find is len
/// @return success or fail
t_err	skip_to_next_nbr(t_str *str, int nbr)
{
	str->i += size_int(nbr);
	skip_while(str, ' ');
	if (str->i < str->len && str->s[str->i] == ',')
	{
		str->i++;
		return (e_success);
	}
	skip_while(str, ' ');
	return (e_fail);
}

/// @brief look at the end of a t_str
/// @param str string input
/// @return 1 if stuff at end of line else 0
short	look_at_end(t_str *str)
{
	if (str->i + str->j > str->len)
		return (0);
	while (str->i + str->j < str->len && str->s[str->i + str->j] == ' ')
		str->j++;
	if (!str->s[str->i + str->j])
		return (0);
	return (1);
}

/// @brief use to look next vergul in extract_line_nbr
/// @param s string
/// @param i start looking at
/// @param ver nuber of vergul
/// @return 1 if error else 0
short	look_next(char *s, size_t i, short ver)
{
	if (ver > 3 || i < ft_strlen(s))
	{
		read_and_set_err_p(i + 1, e_set);
		return (1);
	}
	while (s && s[i])
	{
		if (s[i] == ',')
		{
			read_and_set_err_p(i, e_set);
			return (1);
		}
		else if (ft_isdigit(s[i]))
			return (0);
		else if (s[i] == ' ')
			i++;
		else
		{
			read_and_set_err_p(i, e_set);
			return (1);
		}
	}
	return (0);
}

/// @brief 
/// @param s 
/// @param i 
/// @return 
short	look_last_number(char *s, size_t i)
{
	size_t	t;

	t = i;
	while (i > 0)
	{
		if (ft_isdigit(s[i]))
			return (1);
		if (s[i] == ',')
		{
			printf("moi 7\n");
			read_and_set_err_p(i, e_set);
			return (0);
		}
		i--;
	}
	printf("moi 6\n");
	read_and_set_err_p(t, e_set);
	return (0);
}

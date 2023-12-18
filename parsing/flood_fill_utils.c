#include "parsing.h"

static short	set_space(t_map map, size_t const len, size_t const max_len)
{
	map[0] = ft_calloc(max_len + 2, sizeof(char));
	if (!map[0])
		return (e_malloc_f);
	map[len - 2] = ft_calloc(max_len + 2, sizeof(char));
	if (!map[len - 2])
	{
		ft_free(map[0]);
		return (e_malloc_f);
	}
	ft_memset(map[0], ' ', max_len - 1);
	ft_memset(map[len - 2], ' ', max_len - 1);
	return (e_success);
}

t_map	make_safe_copy(t_map map, const size_t max_len)
{
	size_t	i;
	size_t	len;
	t_map	new_map;

	len = ft_strlen_double(map) + 3;
	new_map = ft_calloc(len + 1, sizeof(char *));
	if (set_space(new_map, len, max_len + 3) < e_success)
	{
		ft_printf(2, "%oError\nCub3D: malloc fail\n", NULL);
		ft_free(new_map);
		return (NULL);
	}
	i = 1;
	while (i < len - 2)
	{
		new_map[i] = ft_strdup(map[i - 1]);
		i++;
	}
	printf("top                     -\n");
	for (size_t k = 0; k < len; k++)
	{
		printf("%s|\n", new_map[k]);
		ft_free(new_map[k]);
	}
	ft_free(new_map);
	printf("bot                     -\n");
	return (NULL);
}
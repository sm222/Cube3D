
#ifndef STRUCTURE_H
# define STRUCTURE_H

//--------------------------//
//			define			//
//--------------------------//

# include <stdio.h>
# include <unistd.h>
# include "../lib/lib_ft/libft.h"

//--------------------------//
//			enum			//
//--------------------------//

enum e_cube {
	e_data,
	e_map,
}; 

//--------------------------//
//			type			//
//--------------------------//

typedef char** t_map; // char **

//--------------------------//
//			struct			//
//--------------------------//

typedef struct	s_parsing
{
	char	*s;
	size_t	i;
}	t_parsing;

typedef struct	s_cub
{
	t_parsing	pars;
	t_map		map;
	int			file_fd;
	void		*mlx;
	void		*window;
}	t_cub;





#endif // STRUCTURE_H
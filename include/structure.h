
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
	data,
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
	void		*window;
	void		*mlx;
}	t_parsing;

typedef struct	s_cube
{
	t_parsing	pars;
	t_map		map;
	int			file_fd;
}	t_cube;





#endif // STRUCTURE_H

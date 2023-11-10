
#ifndef STRUCTURE_H
# define STRUCTURE_H

//--------------------------//
//			define			//
//--------------------------//

/*		  //-------/*/
/*		  // color /*/
/*		  //-------/*/
# ifndef COLORS
#  define COLORS
#  define RED	"\x1B[31m"
#  define GRN	"\x1B[32m"
#  define YEL	"\x1B[33m"
#  define BLU	"\x1B[34m"
#  define MAG	"\x1B[35m"
#  define CYN	"\x1B[36m"
#  define WHT	"\x1B[37m"
#  define ORG	"\x1b[38;5;202m"
#  define PIK	"\x1b[38;5;176m"
#  define TOX	"\x1b[38;5;51m"
#  define RESET	"\x1B[0m"
#  define CLE	"\e[1;1H\e[2J"
#  define GIT	"\x1b[38;5;82m"
# endif


# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include "error.h"
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

typedef char**	t_map; // char **
typedef int		t_fd;  // int

//--------------------------//
//			struct			//
//--------------------------//

typedef struct	s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_texture;

typedef struct	s_extract_t
{
	char	name[5][3];
	bool	side[4];
	t_err	err;
	size_t	line;
}	t_extract_t;



typedef struct	s_parsing
{
	char		*map_name;
	char		*s;
	size_t		i;
	t_map		pre_map;
	t_map		map;
	t_fd		fd;
	int			err;
	t_texture	texture;
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

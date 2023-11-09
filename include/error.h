
#ifndef ERROR_H
# define ERROR_H

#include <err.h>
#include <errno.h>
#include <string.h>

typedef enum e_err {
	e_success	=	1,	//task run corectly
	e_fail		=	0,	//task did't work but not err from system
	e_malloc_f	=	-1,	//malloc fail, not my fault but better be safe
	e_empty_map	=	-2, //empty map, your map suck
	e_bad_char	=	-3, //empty map, your map suck
}	t_err;

#endif // ERR_H

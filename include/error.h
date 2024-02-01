
#ifndef ERROR_H
# define ERROR_H

#include <err.h>
#include <errno.h>
#include <string.h>

typedef enum e_err {
	e_success		=	1,	//task run corectly
	e_fail			=	0,	//task did't work but not err from system
	e_malloc_f		=	-1,	//malloc fail, not my fault but better be safe
	e_empty_map		=	-2, //empty map, your map suck
	e_bad_char		=	-3, //bad char, your map suck
	e_empty_line	=	-4, //not a real err, just ignore it
	e_double_card	=	-5, //find more ten one ... oof
	e_bad_number	=	-6, //number above 255 ... oof
	e_end_of_tex	=	-7, //all texture was find
	e_inva_data_end	=	-8, //find invalid char after data
	e_inva_arg		=	-9, //find invalid char after data
	e_double_tex	=	-10, //find more that one texture
	e_bad_args		=	-11 // ivalid argument pass to ft
}	t_err;

# define INVA_DATA_END "find invalid char after data:"

#endif // ERR_H

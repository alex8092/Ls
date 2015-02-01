#ifndef FILE_STRUCT_H
# define FILE_STRUCT_H

# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include "ft_sstream.h"

typedef struct s_file	t_file;

struct				s_file
{
	struct stat		st;
	char			*path;
	size_t			path_len;
	char			*name;
	size_t			nfilesprint;
	t_sstream		*nlinks;
	t_sstream		*user;
	t_sstream		*group;
	char			rights[11];
	t_bool			to_print;
};

#endif
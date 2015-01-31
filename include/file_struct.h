#ifndef FILE_STRUCT_H
# define FILE_STRUCT_H

# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_file	t_file;

struct				s_file
{
	struct stat		st;
	char			*path;
	size_t			path_len;
	char			*name;
};

#endif
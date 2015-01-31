#include "file.h"
#include "ft_common.h"
#include <stdlib.h>

t_file	*ft_file_new(const char *path)
{
	t_file	*f;

	f = (t_file *)ft_memalloc(sizeof(t_file));
	if (f)
	{
		f->path = ft_strdup(path);
		if (lstat(f->path, &f->st) == -1)
		{
			free(f->path);
			free(f);
			return (0);
		}
		f->path_len = ft_strlen(path);
		f->name = f->path;
	}
	return (f);
}
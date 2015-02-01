#include "file.h"
#include <stdlib.h>

void	ft_file_del(t_file *f)
{
	if (f)
	{
		if (f->name != f->path)
			free(f->name);
		if (f->nlinks)
			ft_sstream_del(f->nlinks);
		if (f->user)
			ft_sstream_del(f->user);
		if (f->group)
			ft_sstream_del(f->group);
		free(f->path);
		free(f);
	}
}
#include "file.h"
#include <stdlib.h>

void	ft_file_del(t_file *f)
{
	if (f)
	{
		if (f->name != f->path)
			free(f->name);
		free(f->path);
		free(f);
	}
}
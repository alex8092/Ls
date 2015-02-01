#include "ls.h"

t_bool	ft_file_willprint(t_file *f)
{
	static t_ls		*ls = 0;

	if (!ls)
		ls = ft_ls();
	if (f->name[0] == '.' && !ls->aopt)
		return (false);
	return (true);
}
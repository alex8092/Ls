#include "ls.h"

void	ft_infos_reset(void)
{
	static t_ls	*ls = 0;

	if (!ls)
		ls = ft_ls();
	ls->w_users = 0;
	ls->w_groups = 0;
	ls->w_nlinks = 0;
}
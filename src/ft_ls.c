#include "ls.h"
#include "ft_common.h"

t_ls	*ft_ls(void)
{
	static t_ls		ls;
	static t_bool	init = false;

	if (!init)
	{
		ft_bzero((void *)&ls, sizeof(t_ls));
		init = true;
	}
	return (&ls);
}
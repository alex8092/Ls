#include "ls.h"

void	ft_infos_get(t_file *f)
{
	ft_infos_get_nlinks(f);
	ft_infos_get_rights(f);
	ft_infos_get_user(f);
	ft_infos_get_group(f);
}
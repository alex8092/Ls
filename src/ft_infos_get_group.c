#include "ls.h"
#include <grp.h>

void	ft_infos_get_group(t_file *f)
{
	struct group	*gr;
	static t_ls		*ls = 0;

	if (!ls)
		ls = ft_ls();
	f->group = ft_sstream_new();	
	gr = getgrgid(f->st.st_gid);
	if (gr)
		f->group->add(f->group, gr->gr_name);
	else
		f->group->addi(f->user, f->st.st_gid);
	if (f->group->str->size > ls->w_groups)
		ls->w_groups = f->group->str->size;
}
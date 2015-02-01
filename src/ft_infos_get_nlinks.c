#include "ls.h"

void	ft_infos_get_nlinks(t_file *f)
{
	static t_ls	*ls = 0;

	if (!ls)
		ls = ft_ls();
	f->nlinks = ft_sstream_new();
	f->nlinks->addui(f->nlinks, f->st.st_nlink);
	if (f->nlinks->str->size > ls->w_nlinks)
		ls->w_nlinks = f->nlinks->str->size;
}
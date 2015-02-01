#include "ls.h"
#include <dirent.h>
#include "ft_sstream.h"
#include <grp.h>

static void	f_add_file(t_file *f, struct dirent *c, t_vector *v, t_sstream *ss)
{
	static t_ls		*ls = 0;
	t_file			*nf;

	ss->clear(ss);
	if (!ls)
		ls = ft_ls();
	if (f->path[f->path_len - 1] != '/')
		ss->add(ss, f->path)->addc(ss, '/')->add(ss, c->d_name);
	else
		ss->add(ss, f->path)->add(ss, c->d_name);
	nf = ft_file_new(ss->str->str);
	nf->name = ft_strdup(c->d_name);
	ft_vector_push(v, (void *)nf);
	if (ft_file_willprint(nf))
	{
		nf->to_print = true;
		++f->nfilesprint;
		if (ls->lopt)
			ft_infos_get(nf);
	}
}

t_vector	*ft_get_files(t_file *f)
{
	t_vector		*v;
	DIR				*d;
	struct dirent	*cur;
	t_sstream		*ss;

	ft_infos_reset();
	v = ft_vector_new();
	ss = ft_sstream_new();
	d = opendir(f->path);
	cur = 0;
	if (d)
	{
		cur = readdir(d);
		while (cur)
		{
			f_add_file(f, cur, v, ss);
			cur = readdir(d);
		}
		closedir(d);
	}
	ft_sstream_del(ss);
	return (v);
}
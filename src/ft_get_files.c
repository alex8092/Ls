#include "ls.h"
#include <dirent.h>
#include "ft_sstream.h"

static void	f_add_file(t_file *f, struct dirent *c, t_vector *v, t_sstream *ss)
{
	t_file	*nf;

	if (!ft_strcmp(c->d_name, "..") || !ft_strcmp(c->d_name, "."))
		return ;
	if (c->d_name[0] == '.' && !ft_ls()->aopt)
		return ;
	ss->clear(ss);
	if (f->path[f->path_len - 1] != '/')
		ss->add(ss, f->path)->addc(ss, '/')->add(ss, c->d_name);
	else
		ss->add(ss, f->path)->add(ss, c->d_name);
	nf = ft_file_new(ss->str->str);
	nf->name = ft_strdup(c->d_name);
	ft_vector_push(v, (void *)nf);
}

t_vector	*ft_get_files(t_file *f)
{
	t_vector		*v;
	DIR				*d;
	struct dirent	*cur;
	t_sstream		*ss;

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
	return (v);
}
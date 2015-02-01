#include "ls.h"
#include "ft_printer.h"
#include "ft_common.h"

static int	f_cmp(t_file *f1, t_file *f2)
{
	return (ft_strcmp(f1->name, f2->name));
}

static void	f_print_files(t_vector *files)
{
	size_t		i;

	i = 0;
	while (i < files->size)
	{
		if (((t_file *)files->ptr[i])->to_print)
			ft_print_file((t_file *)files->ptr[i]);
		++i;
	}
}

static void	f_print_folders(t_vector *files)
{
	size_t	i;
	t_file	*f;

	i = 0;
	while (i < files->size)
	{
		f = (t_file *)files->ptr[i];
		if (ft_strcmp(f->name, ".") && ft_strcmp(f->name, "..")
			&& S_ISDIR(f->st.st_mode))
			ft_print_folder((t_file *)files->ptr[i], true, true);
		++i;
	}
}

void	ft_print_folder(t_file *cur, t_bool print_name, t_bool print_space)
{
	t_vector	*files;

	files = ft_get_files(cur);
	if (cur->name[0] == '.' && !ft_ls()->aopt && !cur->nfilesprint)
		return ;
	ft_printer_init(1);
	if (print_space)
		ft_printer()->addc('\n');
	if (print_name)
		ft_printer()->add(cur->path)->add(":\n");
	ft_vector_sort(files, &f_cmp);
	f_print_files(files);
	if (ft_ls()->Ropt)
		f_print_folders(files);
	ft_vector_clearfree(files, &ft_file_del);
	ft_vector_del(files);
}
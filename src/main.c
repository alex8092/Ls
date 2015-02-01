#include "ls.h"
#include "ft_printer.h"
#include "ft_printf.h"
#include "ft_flagger.h"

static size_t	f_process_opts(t_flagger *f)
{
	t_ls	*inst;
	size_t	next;

	inst = ft_ls();
	inst->lopt = f->is_active(f, 'l', 0);
	inst->aopt = f->is_active(f, 'a', 0);
	inst->Ropt = f->is_active(f, 'R', 0);
	inst->ropt = f->is_active(f, 'r', 0);
	inst->topt = f->is_active(f, 't', 0);
	next = f->cur_index;
	ft_flagger_del(f);
	return (next);
}

static void		f_init_opts(t_flagger *f)
{
	f->add(f, 'l', 0, false);
	f->add(f, 'a', 0, false);
	f->add(f, 'R', 0, false);
	f->add(f, 'r', 0, false);
	f->add(f, 't', 0, false);
}

static void		f_process_no_arg(void)
{
	t_file	*f;

	f = ft_file_new(".");
	ft_print_folder(f, false, false);
	ft_file_del(f);
}

static void		f_process_args(void)
{
	t_vector	*files;
	size_t		nprint;

	ft_sort(ft_ls()->args, &ft_strcmp);
	files = ft_get_files_args();
	nprint = ft_print_files(files);
	ft_print_folders(files, nprint);
	ft_vector_clearfree(files, &ft_file_del);
	ft_vector_del(files);
}

int				main(int ac, char **av)
{
	t_flagger	*f;
	int			ret;

	ret = 0;
	ft_ls()->progname = av[0];
	f = ft_flagger_new();
	f_init_opts(f);
	if (f->parse(f, ac, av))
	{
		ft_ls()->args = av + f_process_opts(f);
		if (*ft_ls()->args)
			f_process_args();
		else
			f_process_no_arg();
		ft_printer_init(1)->flush();
	}
	else
	{
		ft_flagger_del(f);
		ft_printer_init(2)->add("usage: ")->add(av[0]);
		ft_printer()->add(" [-alRrt] files...\n")->flush();
		ret = 1;
	}
	return (ret);
}
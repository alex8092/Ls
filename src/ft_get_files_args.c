#include "ls.h"
#include "file.h"
#include "ft_printer.h"

static void	f_print_error(const char *file)
{
	ft_printer_init(2)->add(ft_ls()->progname)->add(": ")->add(file);
	ft_printer()->add(": No such file or directory\n")->flush();
	++ft_ls()->args_on_error;
}

t_vector	*ft_get_files_args(void)
{
	static t_ls	*inst = 0;
	size_t		i;
	t_file		*f;
	t_vector	*v;

	if (!inst)
		inst = ft_ls();
	v = ft_vector_new();
	i = 0;
	while (inst->args[i])
	{
		if (ft_file_exist(inst->args[i]))
		{
			f = ft_file_new(inst->args[i]);
			ft_vector_push(v, (void *)f);
		}
		else
			f_print_error(inst->args[i]);
		++i;
	}
	return (v);
}
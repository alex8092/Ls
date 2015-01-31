#include "ls.h"
#include "ft_printer.h"

void	ft_print_folder(t_file *cur, t_bool print_name, t_bool print_space)
{
	t_vector	*files;
	size_t		i;

	ft_printer_init(1);
	if (print_space)
		ft_printer()->addc('\n');
	if (print_name)
		ft_printer()->add(cur->path)->add(":\n");
	files = ft_get_files(cur);
	i = 0;
	while (i < files->size)
	{
		ft_print_file((t_file *)files->ptr[i]);
		++i;
	}
	ft_vector_clearfree(files, &ft_file_del);
	ft_vector_del(files);
}
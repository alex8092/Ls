#include "ls.h"
#include "ft_printer.h"

void	ft_print_file(t_file *f)
{
	ft_printer_init(1)->add(f->name)->addc('\n');
}
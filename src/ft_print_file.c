#include "ls.h"
#include "ft_printer.h"

void	ft_print_file(t_file *f)
{
	static t_ls		*ls = 0;
	t_sstream		*ss;

	if (!ls)
		ls = ft_ls();
	ft_printer_init(1);
	if (ls->lopt)
	{
		ss = ft_sstream_new();
		ss->addn(ss, f->rights, 11)->addc(ss, ' ');
		ss->v_min_field_width = ls->w_nlinks;
		ss->adds(ss, f->nlinks->str)->addc(ss, ' ');
		ss->v_min_field_width = ls->w_users;
		ss->v_left_align = true;
		ss->adds(ss, f->user->str)->addn(ss, "  ", 2);
		ss->v_min_field_width = ls->w_groups;
		ss->adds(ss, f->group->str)->addc(ss, ' ');
		ft_printer()->adds(ss->str);
		ft_sstream_del(ss);
	}
	ft_printer()->add(f->name)->addc('\n');
}
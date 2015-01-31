#include "ls.h"

void	ft_print_folders(t_vector *v, size_t nprint)
{
	t_bool	print_name;
	t_bool	print_space;
	t_file	*cur;
	size_t	i;

	i = 0;
	print_name = (v->size > 1 || ft_ls()->args_on_error) ? true : false;
	print_space = (nprint) ? true : false;
	while (i < v->size)
	{
		cur = (t_file *)v->ptr[i];
		if (S_ISDIR(cur->st.st_mode))
		{
			ft_print_folder(cur, print_name, print_space);
			print_space = true;
		}
		++i;
	}
}
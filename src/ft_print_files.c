#include "ls.h"

size_t	ft_print_files(t_vector *v)
{
	t_file	*cur;
	size_t	i;
	size_t	nprint;

	i = 0;
	nprint = 0;
	while (i < v->size)
	{
		cur = (t_file *)v->ptr[i];
		if (!S_ISDIR(cur->st.st_mode))
		{
			ft_print_file(cur);
			++nprint;
		}
		++i;
	}
	return (nprint);
}
#include "ls.h"
#include <pwd.h>

void	ft_infos_get_user(t_file *f)
{
	struct passwd	*pw;
	static t_ls		*ls = 0;

	if (!ls)
		ls = ft_ls();
	f->user = ft_sstream_new();
	pw = getpwuid(f->st.st_uid);
	if (pw)
		f->user->add(f->user, pw->pw_name);
	else
		f->user->addi(f->user, f->st.st_uid);
	if (f->user->str->size > ls->w_users)
		ls->w_users = f->user->str->size;
}
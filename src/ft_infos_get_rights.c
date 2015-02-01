#include "ls.h"

void	ft_infos_get_rights(t_file *f)
{
	f->rights[0] = (S_ISDIR(f->st.st_mode)) ? 'd' : '-';
	f->rights[1] = (f->st.st_mode & S_IRUSR) ? 'r' : '-';
	f->rights[2] = (f->st.st_mode & S_IWUSR) ? 'w' : '-';
	f->rights[3] = (f->st.st_mode & S_IXUSR) ? 'x' : '-';
	f->rights[4] = (f->st.st_mode & S_IRGRP) ? 'r' : '-';
	f->rights[5] = (f->st.st_mode & S_IWGRP) ? 'w' : '-';
	f->rights[6] = (f->st.st_mode & S_IXGRP) ? 'x' : '-';
	f->rights[7] = (f->st.st_mode & S_IROTH) ? 'r' : '-';
	f->rights[8] = (f->st.st_mode & S_IWOTH) ? 'w' : '-';
	f->rights[9] = (f->st.st_mode & S_IXOTH) ? 'x' : '-';
	f->rights[10] = ' ';
}
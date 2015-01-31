#include "file.h"

t_bool	ft_file_exist(const char *path)
{
	return (access(path, F_OK) != -1);
}
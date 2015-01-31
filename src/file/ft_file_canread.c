#include "file.h"

t_bool	ft_file_canread(const char *path)
{
	return (access(path, R_OK) != -1);
}
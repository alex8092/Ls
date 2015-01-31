#ifndef FILE_H
# define FILE_H

# include "file_struct.h"
# include "ft_common.h"

t_file	*ft_file_new(const char *path);
t_bool	ft_file_exist(const char *path);
t_bool	ft_file_canread(const char *path);
void	ft_file_del(t_file *f);

#endif
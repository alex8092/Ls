#ifndef LS_H
# define LS_H

# include "ft_vector.h"
# include "ft_common.h"
# include "file.h"

typedef struct s_ls	t_ls;

struct			s_ls
{
	t_bool		lopt;
	t_bool		ropt;
	t_bool		Ropt;
	t_bool		topt;
	t_bool		aopt;
	char		*progname;
	char		**args;
	size_t		current;
	size_t		args_on_error;
	size_t		w_nlinks;
	size_t		w_users;
	size_t		w_groups;
};

t_ls		*ft_ls(void);
t_vector	*ft_get_files_args(void);
t_vector	*ft_get_files(t_file *f);
t_bool		ft_file_willprint(t_file *f);
size_t		ft_print_files(t_vector *v);
void		ft_print_file(t_file *f);
void		ft_print_folders(t_vector *v, size_t nprint);
void		ft_print_folder(t_file *f, t_bool print_name, t_bool print_space);
void		ft_infos_reset(void);
void		ft_infos_get_nlinks(t_file *f);
void		ft_infos_get_rights(t_file *f);
void		ft_infos_get_user(t_file *f);
void		ft_infos_get_group(t_file *f);
void		ft_infos_get(t_file *f);

#endif
#ifndef EXEC_H
# define EXEC_H

typedef struct s_files
{
	char			*file;
	int				type;//ou un char * avec un text (revoir le lexing)
	struct s_files	*next;
}					t_files

typedef struct s_data
{
	int				*pipe;
	int				*fd;
	char			**command;
	char			**envp;
	char			**path;
	t_files			*begin;//la liste chainnee des files a ouvrir pour toutes les redirections
}	t_data

#endif
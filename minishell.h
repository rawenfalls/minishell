#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_envp
{
	// char			*var;
	char			*data;
	struct s_envp	*next;
}					t_envp;

typedef struct s_inf
{
	t_envp	*env;
	char	**envp;
	char	**slice;
	int		in;
	int		out;
}			t_inf;

//parser
t_envp	*create_elem(char *a);
void	add_env(t_envp **list, char *a);
void	dup_envp(char **envp);

#endif

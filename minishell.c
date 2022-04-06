#include "minishell.h"

void	print_error(char *str)
{
	printf("\33[5m\33[41mERROR\033[0m :%s\n",str);
	exit (1);
}

void	dup_envp(char **envp)
{
	t_inf	*en;
	t_envp	*tmp;
	int		i;

	i = -1;
	en = malloc(sizeof(t_inf));
	ft_memset(en, 0, sizeof(t_inf));
	while (envp[++i])
		add_env(&(en->env), ft_strdup(envp[i]));
	en->envp = malloc(sizeof(char *) * (i + 1));
	en->envp[i] = 0;
	i = 0;
	tmp = en->env;
	while (tmp->next)
	{
		en->envp[i] = ft_strdup(tmp->data);
		tmp = tmp->next;
		++i;
	}
	// tmp = en->env;
	// while (tmp->next)
	// {
	// 	printf("%s\n", tmp->data);
	// 	tmp = tmp->next;
	// }
}

void	check_quote(char *s)
{
	int	f;
	int	i;

	f = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\'')
			f += 1;
		
	}

}

char	*cmdpath(char *str)
{
	char	*cmd;
	char	*ret_str;
	int		i;
	int		e;

	cmd = "/usr/bin/";
	i = -1;
	ret_str = (char *)malloc(sizeof(char) * 100);
	if (!ret_str)
		print_error("malloc\n");
	while (cmd[++i])
		ret_str[i] = cmd[i];
	e = i;
	while (str[i - e])
	{
		ret_str[i] = str[i - e];
		i++;
	}
	ret_str[i] = '\0';
	return (ret_str);
}

void child1(char **a,char *cmd)
{
	execve(cmd, a, NULL);
	print_error("execve\n");
}

void fork_p(char **a)
{
	int pid[2];
	char *cmd;
	pid[0] = fork();
	if (pid[0] < 0)
		print_error("fork is FAILED\n");
	cmd = cmdpath(a[0]);
	if (pid[0] == 0)
		child1(a, cmd);
	free(cmd);
	waitpid(pid[0], NULL, 0);
}

void	cd_f(char **way)
{
	if (chdir(way[1]) < 0)
		print_error("wrong way");
}

char*	add_arrow(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	str[i] = '-';
	str[++i] = '>';
	str[++i] = ' ';
	str[++i] = '\0';
	return (str);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_inf	*res;
	char s[200];

	res = malloc(sizeof(t_inf));
	ft_memset(res, 0,sizeof(t_inf));
	if (argc != 1)
		exit(1);
	while (1)
	{
		getcwd(s,200);
		line = readline(add_arrow(s));
		add_history(line);
		dup_envp(envp);
	//	check_quote(line);
		res->slice = ft_split(line, ' ');

		if (res->slice[0][0] == 'c' && res->slice[0][1] == 'd')
			cd_f(res->slice);
		else
			fork_p(res->slice);

		//printf("%s\n", res->slice[0]);
		// int i = -1;
		// while (res->slice[++i])
		// 	printf("%s|end\n", res->slice[i]);
	}
	(void)argv;
	return (0);
}

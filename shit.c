#include "min.h"

void	print_error(char *str)
{
	int	i;

	i = 0;
	printf("\33[5m\33[41mERROR\033[0m :%s\n",str);
	exit (1);
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
		print_error("ERROR: malloc\n");
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
	print_error("ERROR: execve\n");
}

void fork_p(char **a)
{
	int pid[2];
	char *cmd;
	pid[0] = fork();
	if (pid[0] < 0)
		print_error("ERROR: fork is FAILED\n");
	cmd = cmdpath(a[0]);
	if (pid[0] == 0)
		child1(a, cmd);
	free(cmd);
	waitpid(pid[0], NULL, 0);
}

//getcwd - выдает текущую дерикторию
//chdir - переходит в заданую дерикторию
//дериктория в которой запущенна программа
//востанавливается после завершения
void	cd_f(char **way)
{
	char s[200];
	printf("now-> %s\n",getcwd(s,200));
	if (chdir(way[1]) < 0)
		print_error("wrong way");
	//printf("|%d|",chdir(way[1]));
	printf("after-> %s\n",getcwd(s,200));
}

// !access("a.txt", 0) вернет 1, если файл существует
// 0	Существование файла
// 1	Исполняемость файла
// 2	Доступность для записи
// 3	Доступность для чтения
// 4	Доступность для чтения/записи\
// if (!access("a.txt", 3))
// 	printf("have file\n");
// else
// 	printf("haven't file\n");
int	main(int argc, char const *argv[])
{
	char **a;
	int i;
	int j;
	// while(1)
	// {

	i = 0;


	a = (char**)malloc(sizeof(char*) * argc);
	while (argv[i + 1])
	{
		j = 0;
		a[i] = (char*)malloc(sizeof(char) * 100);
		while (argv[i + 1][j])
		{
			if (argv[i + 1][j] != ' ')
				a[i][j] = argv[i + 1][j];
			j++;
		}
		a[i][j]= '\0';
		i++;
	}
	a[i] = NULL;
	// char s[200];
	// printf("%s\n",getcwd(s,200));
	// chdir("..");
	// printf("%s\n",getcwd(s,200));

	if (a[0][0] == 'c' && a[0][1] == 'd')
		cd_f(a);
	else
		fork_p(a);
	i = -1;
	while(++i < argc)
		free(a[i]);
	free(a);

	//}
	// chdir("..");

	// char *cmd = "/usr/bin/env";
	// char *a1[] = {"env", NULL, NULL};
	// execve(cmd, a1,NULL);
	// print_error("ERROR: execve\n");
	//print_error("it was shit");
	return (0);
}
	//пока не удалять, необходимо для тестирования
	//gcc -g min.h shit.c && valgrind --leak-check=yes ./a.out echo -n a
	// char *cmd = "/bin/echo";
	// char *a1[] = {"echo", "-n", "eeeeee"};
	// execve(cmd, a1,NULL);
	// print_error("ERROR: execve\n");
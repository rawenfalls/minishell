#include "minishell.h"

t_envp	*create_elem(char *a)
{
	t_envp	*elem;

	elem = (t_envp *)malloc(sizeof(t_envp));
	elem->data = a;
	elem->next = NULL;
	return (elem);
}

void	add_env(t_envp **list, char *a)
{
	t_envp	*new_elem;
	t_envp	*tmp;

	if (*list)
	{
		new_elem = create_elem(a);
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_elem;
	}
	else
		*list = create_elem(a);
}

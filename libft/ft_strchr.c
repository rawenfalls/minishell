/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbombadi <sbombadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:39:15 by sbombadi          #+#    #+#             */
/*   Updated: 2021/10/13 15:39:18 by sbombadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int n)
{
	int	i;

	i = 0;
	while (*(s + i) != (char)n)
	{
		if (*(s + i) == 0)
			return (NULL);
		i++;
	}
	return ((char *)(s + i));
}
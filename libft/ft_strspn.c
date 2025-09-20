/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio < crosorio@student.42madrid.com>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-02 11:01:49 by crosorio          #+#    #+#             */
/*   Updated: 2025-07-02 11:01:49 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_aux(size_t count, int found, const char *a, const char *s)
{
	while (*s)
	{
		while (*a)
		{
			if (*s == *a)
			{
				found = 1;
				break ;
			}
			a++;
		}
		if (found)
		{
			count++;
			s++;
		}
		else
			break ;
	}
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t		count;
	int			found;
	const char	*a;

	found = 0;
	count = 0;
	a = accept;
	ft_aux(count, found, a, s);
	return (count);
}

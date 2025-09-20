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

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t		count;
	int			found;
	const char	*a = accept;

	count = 0;
	while (*s)
	{
		found = 0;
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
	return (count);
}

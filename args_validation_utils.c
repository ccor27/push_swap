/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:55:09 by crosorio          #+#    #+#             */
/*   Updated: 2025/08/01 18:21:12 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Function to validate if a string is empty or blank
 */
int	ft_is_string_empty_or_blank(char *s)
{
	if (!s)
		return (1);
	while (*s)
	{
		if (!((*s >= 9 && *s <= 13) || *s == 32))
			return (0);
		s++;
	}
	return (1);
}

/**
 * Functio to free stacks and matrix that we used to get numbers
 * from arguments
 */
void	ft_free_stacks_and_matrix(t_list **a, t_list **b, char **matrix)
{
	int	i;

	i = 0;
	if (matrix && matrix[i])
	{
		while (matrix[i])
		{
			free(matrix[i]);
			i++;
		}
		free(matrix);
	}
	if (a && *a)
		ft_lstclear(a);
	if (b && *b)
		ft_lstclear(b);
}


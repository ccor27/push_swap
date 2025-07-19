/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:55:09 by crosorio          #+#    #+#             */
/*   Updated: 2025/07/19 11:38:37 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
int	ft_find_max_index(t_list *stack)
{
	int		max_value;
	int		max_index;
	t_list	*current;

	if (!stack)
		return (-1);

	max_value = stack->content;
	max_index = stack->pos;
	current = stack;

	while (current)
	{
		if (current->content > max_value)
		{
			max_value = current->content;
			max_index = current->pos;
		}
		current = current->next;
	}
	return (max_index);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_finder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:17:29 by crosorio          #+#    #+#             */
/*   Updated: 2025/08/01 16:31:35 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_pos(t_list *stack)
{
	int value;
	int pos;

	if (!stack)
		return (-1);
	value = INT_MAX;
	pos = -1;
	while (stack)
	{
		if (stack->content < value)
		{
			value = stack->content;
			pos = stack->pos;
		}
		stack = stack->next;
	}
	return (pos);
}
int	ft_get_target_pos(t_list *node_to_compare, t_list *list_to_compare, char from, int target_pos)
{
	t_list	*head;
	int		best_match_val;

	if(from == 'a')
		best_match_val = INT_MIN;
	else
		best_match_val = INT_MAX;
	head = list_to_compare;
	while (head)
	{
		if (from == 'a' && (head->content < node_to_compare->content
			&& head->content > best_match_val))
		{
			best_match_val = head->content;
			target_pos = head->pos;
		}
		else if( from =='b' && (head->content > node_to_compare->content
				&& head->content < best_match_val))
		{
				best_match_val = head->content;
				target_pos = head->pos;
		}
		head = head->next;
	}
	return (target_pos);
}
void	ft_target_process(t_list **list, t_list *node, char from)
{
	t_list	*head;
	int		target_pos;

	head = *list;
	while (head)
	{
		target_pos = ft_get_target_pos(head,node,from,-1);
		if(target_pos == -1)
			target_pos = ft_find_pos(node);
		head->target_pos = target_pos;
		head = head->next;
	}
}

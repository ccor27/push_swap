/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:03:13 by crosorio          #+#    #+#             */
/*   Updated: 2025/07/12 14:12:32 by crosorio         ###   ########.fr       */
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
//TODO: refactor this in order to make it more efficient and sort
void	ft_find_targets(t_list **a, t_list **b)
{
	t_list	*node_a;
	t_list	*node_b;
	int		target_pos;
	int		best_match_val;
	int		best_val;

	node_a = a;
	while (node_a)
	{
		best_match_val = INT_MAX;
		target_pos = -1;
		node_b = b;
		// Buscar el nodo en B con valor mayor a node_a y menor que best_match_val
		while (node_b)
		{
			if (node_b->content > node_a->content
				&& node_b->content < best_match_val)
			{
				best_match_val = node_b->content;
				target_pos = node_b->pos;
			}
			node_b = node_b->next;
		}
		// Si no se encontró ningún valor mayor, usar el más pequeño en B
		if (target_pos == -1)
		{
			node_b = b;
			best_val = INT_MAX;
			while (node_b)
			{
				if (node_b->content < best_val)
				{
					best_val = node_b->content;
					target_pos = node_b->pos;
				}
				node_b = node_b->next;
			}
		}
		node_a->target_pos = target_pos;
		node_a = node_a->next;
	}
}
/**
 * Function to assig the position of the node
 */
void	ft_assing_positions(t_list **stack)
{
	int		i;
	t_list	*head;

	i = 0;
	head = *stack;
	while (head)
	{
		head->pos = i;
		head = head->next;
		i++;
	}
}
/**
 * Function to order a stack with just 3 elements in ascending
 * order
 */
void	ft_order_three_elements(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->content;
	second = (*stack)->next->content;
	third = (*stack)->next->next->content;
	if (first > second && second < third && first < third)
		ft_swap_two_element_at_top(stack, "sa");
	else if (first > second && second > third)
	{
		ft_swap_two_element_at_top(stack, "sa");
		ft_reverse_rotate_stack(stack, "rra");
	}
	else if (first > second && second < third && first > third)
		ft_rotate_stack(stack, "ra");
	else if (first < second && second > third && first < third)
	{
		ft_swap_two_element_at_top(stack, "sa");
		ft_rotate_stack(stack, "ra");
	}
	else if (first < second && second > third && first > third)
		ft_reverse_rotate_stack(stack, "rra");
}

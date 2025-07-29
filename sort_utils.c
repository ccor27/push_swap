/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:03:13 by crosorio          #+#    #+#             */
/*   Updated: 2025/07/19 12:12:44 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Function to find the cheap movement
 */
t_list	*ft_find_lowest_movements_cost(t_list *stack)
{
	t_list	*cheap;
	int		min_cost;
	int		cost_a;
	int		cost_b;
	int		total_cost;

	cheap = stack;
	min_cost = INT_MAX;
	while (stack)
	{
		cost_a = stack->cost_a;
		cost_b = stack->cost_b;
		if ((cost_a >= 0 && cost_b >= 0) || (cost_a < 0 && cost_b < 0))
			total_cost = ft_max(ft_abs(cost_a), ft_abs(cost_b));
		else
			total_cost = ft_abs(cost_a) + ft_abs(cost_b);
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			cheap = stack;
		}
		stack = stack->next;
	}
	return (cheap);
}
/**
 * Function to calculate the cost of movements of each node of A
 * and its target
 */
void	ft_find_cost(t_list **node, int stack_a_size, int stack_b_size)
{
	t_list	*head;

	head = *node;
	while (head)
	{
		if (head->pos <= stack_a_size / 2)
			head->cost_a = head->pos;
		else
			head->cost_a = (stack_a_size - head->pos) * -1;
		if (head->target_pos <= stack_b_size / 2)
			head->cost_b = head->target_pos;
		else
			head->cost_b = (stack_b_size - head->target_pos) * -1;
		head = head->next;
	}
}

/**
 * Function to find the min value of a stack
 */
int	ft_find_min_index(t_list *node)
{
	int		min;
	int		index;
	int		pos;
	t_list	*tmp;

	tmp = node;
	min = tmp->content;
	pos = 0;
	index = 0;
	while (tmp)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			index = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return (index);
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


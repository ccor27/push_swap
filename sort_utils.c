/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:03:13 by crosorio          #+#    #+#             */
/*   Updated: 2025/08/01 13:26:09 by crosorio         ###   ########.fr       */
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
 * Function to find the min value of a stack
 */
int	ft_find_min_index(t_list *node)
{
	int		min;
	int		index;
	t_list	*tmp;

	tmp = node;
	min = tmp->content;
	index = 0;
	while (tmp)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			index = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (index);
}
int	ft_find_max_index(t_list *node)
{
	int		min;
	int		index;
	t_list	*tmp;

	tmp = node;
	min = tmp->content;
	index = 0;
	while (tmp)
	{
		if (tmp->content > min)
		{
			min = tmp->content;
			index = tmp->pos;
		}
		tmp = tmp->next;
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

void	ft_find_cost_helper(char from, t_list *head, int first_stack_size,
		int second_stack_size)
{
	if (from == 'a')
	{
		if (head->pos <= first_stack_size / 2)
			head->cost_a = head->pos;
		else
			head->cost_a = (first_stack_size - head->pos) * -1;
		if (head->target_pos <= second_stack_size / 2)
			head->cost_b = head->target_pos;
		else
			head->cost_b = (second_stack_size - head->target_pos) * -1;
	}
	else
	{
		if (head->pos <= first_stack_size / 2)
			head->cost_b = head->pos;
		else
			head->cost_b = (first_stack_size - head->pos) * -1;
		if (head->target_pos <= second_stack_size / 2)
			head->cost_a = head->target_pos;
		else
			head->cost_a = (second_stack_size - head->target_pos) * -1;
	}
}

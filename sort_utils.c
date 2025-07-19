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

void	ft_find_targets(t_list **a, t_list **b)
{
	t_list	*node_a;
	t_list	*node_b;
	int		target_pos;
	int		best_match_val;
	int		best_val;

	node_a = *a;
	while (node_a)
	{
		best_match_val = INT_MIN;
		target_pos = -1;
		node_b = *b;
		// Buscar el nodo en B con valor menor a node_a y mayor que best_match_val
		while (node_b)
		{
			if (node_b->content < node_a->content
				&& node_b->content > best_match_val)
			{
				best_match_val = node_b->content;
				target_pos = node_b->pos;
			}
			node_b = node_b->next;
		}
		// Si no se encontró ningún valor menor, usar el mayor en B
		if (target_pos == -1)
		{
			node_b = *b;
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

// TODO: refactor this in order to make it more efficient and sort
// void	ft_find_targets(t_list **a, t_list **b)
// {
// 	t_list	*node_a;
// 	t_list	*node_b;
// 	int		target_pos;
// 	int		best_match_val;
// 	int		best_val;

// 	node_a = *a;
// 	while (node_a)
// 	{
// 		best_match_val = INT_MAX;
// 		target_pos = -1;
// 		node_b = *b;
// 		// Buscar el nodo en B con valor mayor a node_a y menor que best_match_val
// 		while (node_b)
// 		{
// 			if (node_b->content > node_a->content
// 				&& node_b->content < best_match_val)
// 			{
// 				best_match_val = node_b->content;
// 				target_pos = node_b->pos;
// 			}
// 			node_b = node_b->next;
// 		}
// 		// Si no se encontró ningún valor mayor, usar el más pequeño en B
// 		if (target_pos == -1)
// 		{
// 			node_b = *b;
// 			best_val = INT_MAX;
// 			while (node_b)
// 			{
// 				if (node_b->content < best_val)
// 				{
// 					best_val = node_b->content;
// 					target_pos = node_b->pos;
// 				}
// 				node_b = node_b->next;
// 			}
// 		}
// 		node_a->target_pos = target_pos;
// 		node_a = node_a->next;
// 	}
// }
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
		ft_swap_two_element_at_top(stack, "sa\n");
	else if (first > second && second > third)
	{
		ft_swap_two_element_at_top(stack, "sa\n");
		ft_reverse_rotate_stack(stack, "rra\n");
	}
	else if (first > second && second < third && first > third)
		ft_rotate_stack(stack, "ra\n");
	else if (first < second && second > third && first < third)
	{
		ft_swap_two_element_at_top(stack, "sa\n");
		ft_rotate_stack(stack, "ra\n");
	}
	else if (first < second && second > third && first > third)
		ft_reverse_rotate_stack(stack, "rra\n");
}

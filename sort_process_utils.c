/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_process_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:00:08 by crosorio          #+#    #+#             */
/*   Updated: 2025/08/01 16:42:04 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Function to find the biggest number
 */
int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

/**
 * Function to find the absolute value of a number
 */
int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

/**
 * Function to order two numbers into stack
 */
void	ft_order_two(t_list **stack)
{
	if (!stack || !*stack || !(*stack)->next)
		return ;
	if ((*stack)->content > (*stack)->next->content)
		ft_swap_two_element_at_top(stack, "sa\n");
}

/**
 * Function to get a element from the top of a stack
 */
t_list	*ft_pop(t_list **stack)
{
	t_list	*popped_node;

	if (!stack || !*stack)
		return (NULL);
	popped_node = *stack;
	*stack = (*stack)->next;
	popped_node->next = NULL;
	return (popped_node);
}

/**
 * Function to order a stack with just 3 elements in ascending
 * order
 */
void	ft_order_three_elements(t_list **stack)
{
	int	biggest_pos;

	ft_assing_positions(stack);
	biggest_pos = ft_find_max_index(*stack);
	if (biggest_pos == 0)
		ft_rotate_stack(stack, "ra\n");
	else if (biggest_pos == 1)
		ft_reverse_rotate_stack(stack, "rra\n");
	if ((*stack)->content > (*stack)->next->content)
		ft_swap_two_element_at_top(stack, "sa\n");
}

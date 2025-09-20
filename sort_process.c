/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:58:52 by crosorio          #+#    #+#             */
/*   Updated: 2025/09/19 20:55:24 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Principal function to sort the stack
 */
void	ft_sort(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) < 4)
	{
		if (ft_lstsize(*a) == 3)
			ft_order_three_elements(a);
		else
			ft_order_two(a);
	}
	else
	{
		while (ft_lstsize(*a) > 3 && ft_lstsize(*b) < 2)
			ft_put_into_stack(b, ft_pop(a), "pb\n");
		while (ft_lstsize(*a) > 3)
			ft_process_from_a_to_b(a, b);
		ft_order_three_elements(a);
		while (*b)
			ft_process_from_b_to_a(b, a);
		ft_assing_positions(a);
		ft_put_min_on_top(a);
	}
}

/**
 * Function to pass from A to B
 */
void	ft_process_from_a_to_b(t_list **a, t_list **b)
{
	ft_put_into_stack(b, ft_pop(a), "pb\n");
}

/**
 * Function to pass from stack B to stack A
 * in order numbers be sorter
 */
void	ft_process_from_b_to_a(t_list **b, t_list **a)
{
	ft_assing_positions(a);
	ft_assing_positions(b);
	ft_target_process(b, *a, 'b');
	ft_find_cost(b, ft_lstsize(*b), ft_lstsize(*a), 'b');
	ft_execute_movements(b, a, ft_find_lowest_movements_cost(*b), 'b');
	ft_put_into_stack(a, ft_pop(b), "pa\n");
}

/**
 * Function to put the minimum vale in the top of stack
 */
void	ft_put_min_on_top(t_list **a)
{
	int	min_index;
	int	size;
	int	i;

	min_index = ft_find_min_index(*a);
	size = ft_lstsize(*a);
	if (min_index <= size / 2)
		while (min_index-- > 0)
			ft_rotate_stack(a, "ra\n");
	else
	{
		i = size - min_index;
		while (i-- > 0)
			ft_reverse_rotate_stack(a, "rra\n");
	}
}

/**
 * Function to calculate the cost of movements of each node of A
 * and its target
 */
void	ft_find_cost(t_list **node, int first_stack_size, int second_stack_size,
		char from)
{
	t_list	*head;

	head = *node;
	while (head)
	{
		ft_find_cost_helper(from, head, first_stack_size, second_stack_size);
		head = head->next;
	}
}

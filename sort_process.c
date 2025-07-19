/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:00:08 by crosorio          #+#    #+#             */
/*   Updated: 2025/07/19 11:06:42 by crosorio         ###   ########.fr       */
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
void	ft_order_two(t_list **stack)
{
	if (!stack || !*stack || !(*stack)->next)
		return ;
	if ((*stack)->content > (*stack)->next->content)
		ft_swap_two_element_at_top(stack, "sa\n");
}

t_list	*ft_pop(t_list **stack)
{
	t_list	*popped_node;

	if (!stack || !*stack) // Check if stack pointer is NULL or stack is empty
		return (NULL);
	popped_node = *stack;    // Store the current head node
	*stack = (*stack)->next; // Update the stack head to the next node
	popped_node->next = NULL;
	// Detach the popped node from the stack (optional but good practice)
	return (popped_node); // Return the removed node
}

void	ft_sort(t_list **a, t_list **b)
{
	t_list	*cheap_movement;
	int		min_index;
	int		size;
	int		i;

	// validate stack a has more than 3 elements
	if (ft_lstsize(*a) < 4)
	{
		if (ft_lstsize(*a) == 3)
			ft_order_three_elements(a);
		else
			ft_order_two(a);
	}
	else
	{
		// pass the 2 first elements from A to B
		ft_put_into_stack(b, ft_pop(a), "pa\n");
		ft_put_into_stack(b, ft_pop(a), "pa\n");
		// make a loop until the size of A be more than 3
		while (ft_lstsize(*a) > 3)
		{
			// set the pos to each element of both A and B
			ft_assing_positions(a);
			ft_assing_positions(b);
			// select the target of A's elements
			ft_find_targets(a, b);
			// find the cost
			ft_find_cost(a, ft_lstsize(*a), ft_lstsize(*b));
			// select the lowest cost
			cheap_movement = ft_find_lowest_movements_cost(*a);
			// make the move
			ft_execute_movements(a, b, cheap_movement);
			ft_put_into_stack(b, ft_pop(a), "pb\n");
		}
		// order the 3 elements in A
		if (ft_lstsize(*a) == 3)
			ft_order_three_elements(a);
		else if (ft_lstsize(*a) == 2)
			ft_order_two(a);
		// pass all from B to A
		while (*b)
		{
			// create a ft_pop function to remove the node that we pass
			ft_put_into_stack(a, ft_pop(b), "pa\n");
		}
		// validate that the stack is ordered or we have to make more rotations
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
}

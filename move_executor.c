/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:39:51 by crosorio          #+#    #+#             */
/*   Updated: 2025/08/01 16:39:21 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Function to decide which movements do depending
 * of the cost's sign of both stacks
 */
void	ft_execute_movements(t_list **stack_from, t_list **stack_dest,
		t_list *node, char move)
{
	if (move == 'a')
	{
		if (node->cost_a >= 0 && node->cost_b >= 0)
			ft_do_rr(stack_from, stack_dest, node);
		else if (node->cost_a < 0 && node->cost_b < 0)
			ft_do_rrr(stack_from, stack_dest, node);
		else
			ft_do_different_moves(stack_from, stack_dest, node);
	}
	else
	{
		if (node->cost_a >= 0 && node->cost_b >= 0)
			ft_do_rr(stack_dest, stack_from, node);
		else if (node->cost_a < 0 && node->cost_b < 0)
			ft_do_rrr(stack_dest, stack_from, node);
		else
			ft_do_different_moves(stack_dest, stack_from, node);
	}
}

/**
 * Function to make different types of movements in both stacks
 */
void	ft_do_different_moves(t_list **a, t_list **b, t_list *node)
{
	if (node->cost_a > 0)
		while (node->cost_a-- > 0)
			ft_rotate_stack(a, "ra\n");
	else
		while (node->cost_a++ < 0)
			ft_reverse_rotate_stack(a, "rra\n");
	if (node->cost_b > 0)
		while (node->cost_b-- > 0)
			ft_rotate_stack(b, "rb\n");
	else
		while (node->cost_b++ < 0)
			ft_reverse_rotate_stack(b, "rrb\n");
}

/**
 * Function to make reverse rotation in both stacks, together
 * or separately
 */
void	ft_do_rrr(t_list **a, t_list **b, t_list *node)
{
	while (node->cost_a < 0 && node->cost_b < 0)
	{
		ft_reverse_rotate_two_stacks_at_same_time(a, b);
		node->cost_a++;
		node->cost_b++;
	}
	while (node->cost_a++ < 0)
		ft_reverse_rotate_stack(a, "rra\n");
	while (node->cost_b++ < 0)
		ft_reverse_rotate_stack(b, "rrb\n");
}

/**
 * Function to make simple rotation in both stacks, together
 * or separately
 */
void	ft_do_rr(t_list **a, t_list **b, t_list *node)
{
	while (node->cost_a > 0 && node->cost_b > 0)
	{
		ft_rotate_two_stacks_at_same_time(a, b);
		node->cost_a--;
		node->cost_b--;
	}
	while (node->cost_a-- > 0)
		ft_rotate_stack(a, "ra\n");
	while (node->cost_b-- > 0)
		ft_rotate_stack(b, "rb\n");
}

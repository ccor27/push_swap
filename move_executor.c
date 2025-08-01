/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:39:51 by crosorio          #+#    #+#             */
/*   Updated: 2025/07/19 10:10:54 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Function to decide which movements do depending
 * of the cost's sign of both stacks
 */
void	ft_execute_movements(t_list **a, t_list **b, t_list *node)
{
	ft_printf("el nodo es: %d y el cost_a: %d, el const_b: %d\n",node->content,node->cost_a,node->cost_b);
	ft_printf("la posicion del target es: %d\n", node->target_pos);
	if (node->cost_a >= 0 && node->cost_b >= 0)
		ft_do_rr(a, b, node);
	else if (node->cost_a < 0 && node->cost_b < 0)
		ft_do_rrr(a, b, node);
	else
		ft_do_different_moves(a, b, node);
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
		{
			ft_printf("desde ft_do_different_moves\n");
			ft_rotate_stack(b, "rb\n");
		}
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
		ft_reverse_rotate_two_stacks_at_same_time(a, b); // rrr
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
	{
		ft_printf("desde ft_do_rr\n");
		ft_rotate_stack(a, "ra\n");
	}
	while (node->cost_b-- > 0)
	{
			ft_printf("desde ft_do_rr\n");
			ft_rotate_stack(b, "rb\n");
	}
}


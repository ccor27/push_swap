/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio < crosorio@student.42madrid.com>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-17 13:39:51 by crosorio          #+#    #+#             */
/*   Updated: 2025-07-17 13:39:51 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_execute_movements(t_list **a, t_list **b, t_list *node)
{
	if (node->cost_a >= 0 && node->cost_b >= 0)
		ft_do_rr(a, b, node);
	else if (node->cost_a < 0 && node->cost_b < 0)
		ft_do_rrr(a, b, node);
	else
		ft_do_different_moves(a, b, node);
	// //case when cost_a and cost_b are positive
	// ft_do_rr(a, b,node);
	// //case when cost_a and cost_b are negative,
		//do the same like before but changing the sings
	// ft_do_rrr(a,b,node);
	// //case when cost_a and cost_b are different
	// ft_do_different_moves(a,b,node);
}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio < crosorio@student.42madrid.com>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-29 13:58:52 by crosorio          #+#    #+#             */
/*   Updated: 2025-07-29 13:58:52 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		//ft_printf("Movimientos de A -> B\n");
		while (ft_lstsize(*a) > 3)
			ft_process_from_a_to_b(a, b);
		//ft_printf("Movimientos de A -> B\n");
		ft_assing_positions(a);
		//ft_printf("Movimientos para ordenar los 3 de A\n");
		ft_order_three_elements(a);
		//ft_printf("Movimientos para ordenar los 3 de A\n");
		//ft_printf("Movimientos de B -> A\n");
		while (*b)
			ft_process_from_b_to_a(b, a);
		//ft_printf("Movimientos de B -> A\n");
		ft_assing_positions(a);
		//ft_printf("Movimientos para poner el min en A en el top\n");
		ft_put_min_on_top(a);
		//ft_printf("Movimientos para poner el min en A en el top\n");
	}
}

void	ft_process_from_a_to_b(t_list **a, t_list **b)
{
	ft_assing_positions(a);
	ft_assing_positions(b);
	ft_target_process(a,*b,'a');
	ft_find_cost(a, ft_lstsize(*a), ft_lstsize(*b),'a');
	ft_execute_movements(a, b, ft_find_lowest_movements_cost(*a));
	ft_put_into_stack(b, ft_pop(a),  "pb\n");
}
void	ft_process_from_b_to_a(t_list **b, t_list **a)
{
	ft_assing_positions(a);
	ft_assing_positions(b);
	ft_target_process(b,*a,'b');
	ft_find_cost(b, ft_lstsize(*b), ft_lstsize(*a),'b');
	ft_execute_movements(b, a, *b);
	ft_put_into_stack(a, ft_pop(b), "pa\n");
}
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
void	ft_find_cost(t_list **node, int first_stack_size, int second_stack_size, char from)
{
	t_list	*head;

	head = *node;
	while (head)
	{
		ft_find_cost_helper(from,head,first_stack_size,second_stack_size);
		head = head->next;
	}
}

			// if (head->pos <= first_stack_size / 2)
			// 	head->cost_a = head->pos;
			// else
			// 	head->cost_a = (first_stack_size - head->pos) * -1;
			// if (head->target_pos <= second_stack_size / 2)
			// 	head->cost_b = head->target_pos;
			// else
			// 	head->cost_b = (second_stack_size - head->target_pos) * -1;

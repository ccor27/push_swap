/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:41:39 by crosorio          #+#    #+#             */
/*   Updated: 2025/08/01 16:43:56 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Function to swap the two elements at the top
 * of a stack
 * sa , sb
 */
void	ft_swap_two_element_at_top(t_list **stack, char *movemnt)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	if (movemnt)
		ft_printf("%s", movemnt);
}

/**
 * Function to swap two stacks at the same time
 */
void	ft_swap_elements_same_time(t_list **stack_a, t_list **stack_b)
{
	ft_swap_two_element_at_top(stack_a, NULL);
	ft_swap_two_element_at_top(stack_b, NULL);
	ft_printf("ss\n");
}

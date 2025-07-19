/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:17:30 by crosorio          #+#    #+#             */
/*   Updated: 2025/07/19 11:17:32 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_rotate_stack(t_list **stack, char *movemnt)
{
	if(!stack || !*stack || !(*stack)->next)
		return;
	t_list *first;
	t_list *last_node;

	first = (*stack)->next;
	last_node = *stack;
	last_node->next = NULL;
	ft_lstadd_back(&first, last_node);
	*stack = first;
	if(movemnt)
		ft_printf("%s",movemnt);
}

void ft_rotate_two_stacks_at_same_time(t_list **stack_a, t_list **stack_b)
{
	ft_rotate_stack(stack_a,NULL);
	ft_rotate_stack(stack_b,NULL);
	ft_printf("rr\n");
}
void ft_reverse_rotate_stack(t_list **stack, char *movemnt)
{
	if(!stack || !*stack || !(*stack)->next)
		return;
	t_list *last_node;
	t_list *aux;
	aux = *stack;
	while(aux && aux->next->next)
		aux = aux->next;
	last_node = aux->next;
	aux->next =NULL;
	ft_lstadd_front(stack,last_node);
	if(movemnt)
		ft_printf("%s",movemnt);
}
void ft_reverse_rotate_two_stacks_at_same_time(t_list **stack_a, t_list **stack_b)
{
	ft_reverse_rotate_stack(stack_a,NULL);
	ft_reverse_rotate_stack(stack_b,NULL);
	ft_printf("rrr\n");
}

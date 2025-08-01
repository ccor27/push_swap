/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:00:08 by crosorio          #+#    #+#             */
/*   Updated: 2025/07/19 12:15:11 by crosorio         ###   ########.fr       */
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
	 int biggest_pos; // Usaremos la posición del más grande

    // Calcula las posiciones actuales de los nodos (si no están ya actualizadas)
    // Es CRÍTICO que las posiciones estén correctas para ft_find_max_val_pos
    ft_assing_positions(stack); // Asegúrate de que las posiciones estén al día

    biggest_pos = ft_find_max_index(*stack); // Encuentra la posición del nodo más grande

    if (biggest_pos == 0) // Si el más grande está en la primera posición (cima)
        ft_rotate_stack(stack, "ra\n"); // Mueve el más grande a la base
    else if (biggest_pos == 1) // Si el más grande está en la segunda posición
        ft_reverse_rotate_stack(stack, "rra\n"); // Mueve el más grande a la base
    // No necesitamos un 'else if (biggest_pos == 2)', porque si no es 0 ni 1,
    // significa que el más grande ya está en la posición 2 (la base), que es ideal.

    // Después de los movimientos anteriores, el más grande está en la base.
    // Ahora, solo necesitamos asegurarnos de que los dos primeros estén en orden.
    // (*stack)->content es el primer elemento, (*stack)->next->content es el segundo.
    if ((*stack)->content > (*stack)->next->content)
        ft_swap_two_element_at_top(stack, "sa\n"); // Intercambia los dos primeros si están desordenados

	// int	first;
	// int	second;
	// int	third;

	// first = (*stack)->content;
	// second = (*stack)->next->content;
	// third = (*stack)->next->next->content;
	// if (first > second && second < third && first < third)
	// 	ft_swap_two_element_at_top(stack, "sa\n");
	// else if (first > second && second > third)
	// {
	// 	ft_swap_two_element_at_top(stack, "sa\n");
	// 	ft_reverse_rotate_stack(stack, "rra\n");
	// }
	// else if (first > second && second < third && first > third)
	// 	ft_rotate_stack(stack, "ra\n");
	// else if (first < second && second > third && first < third)
	// {
	// 	ft_swap_two_element_at_top(stack, "sa\n");
	// 	ft_rotate_stack(stack, "ra\n");
	// }
	// else if (first < second && second > third && first > third)
	// 	ft_reverse_rotate_stack(stack, "rra\n");
}

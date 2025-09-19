/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:44:30 by crosorio          #+#    #+#             */
/*   Updated: 2025/08/01 16:50:10 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Function to print a stack
 */
void	ft_print_stack(t_list *stack)
{
	while (stack)
	{
		ft_printf("%d\n", stack->content);
		stack = stack->next;
	}
}
/**
 * Function to validate if a stack is ordered
 */
int ft_is_stack_ordered(t_list *stack)
{
	while(stack && stack->next)
	{
		if(stack->content > stack->next->content)
			return(0);
		stack = stack->next;
	}
	return(1);
}
/**
 * Main function
 */
int	main(int argc, char **argv)
{
	char	**numbers;
	char	*joined;
	t_list	*stack_a;
	t_list	*stack_b;

	numbers = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		ft_free_and_close(numbers, &stack_a);
	ft_join_arguments(argv,&joined);
	if(!joined || ft_strlen(joined) == 0 || ft_strspn(joined, " \t\n\r\f\v") == ft_strlen(joined))
		ft_free_and_close(numbers, &stack_a);
	numbers = ft_split(joined, ' ');
	if (!numbers)
		ft_free_and_close(numbers, &stack_a);
	if (!ft_fill_up_stack_a(&stack_a, numbers))
		ft_free_and_close(numbers, &stack_a);
	if(ft_is_stack_ordered(stack_a))
		exit(EXIT_SUCCESS);
	ft_sort(&stack_a,&stack_b);
	free(joined);
	// ft_printf("\n");
	// ft_print_stack(stack_a);
	ft_free_stacks_and_matrix(&stack_a,&stack_b, numbers);
	}

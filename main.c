/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:44:30 by crosorio          #+#    #+#             */
/*   Updated: 2025/07/04 13:15:14 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_list *stack)
{
	while (stack)
	{
		ft_printf("%d\n", stack->content);
		stack = stack->next;
	}
}

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
	//everything good, create stack b
	ft_print_stack(stack_a);
	// ft_printf("luego de hacer sa\n");
	// ft_sa(&stack_a,"sa\n");
	// ft_rotate_stack(&stack_a,"ra\n");
	// ft_printf("luego de hacer ra\n");
	// ft_rotate_stack(&stack_a,"ra\n");
	// ft_print_stack(stack_a);
	// ft_printf("luego de hacer rra\n");
	// ft_rotate_stack(&stack_a,"rra\n");
	// ft_print_stack(stack_a);
	// ft_printf("luego de hacer rra\n");
	// ft_reverse_rotate_stack(&stack_a,"rra\n");
	// ft_print_stack(stack_a);
	 ft_printf("luego de hacer pb (en el stack totalmente vacio)\n");
	t_list *node = ft_lstnew(10);
	ft_put_into_stack(&stack_b,node,"pa\n");
	ft_print_stack(stack_b);
}

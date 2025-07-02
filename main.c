/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:44:30 by crosorio          #+#    #+#             */
/*   Updated: 2025/06/19 14:19:32 by crosorio         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	char	**numbers;
	char	*joined;
	t_list	*stack_a;

	numbers = NULL;
	stack_a = NULL;
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
	//validate that the stack is not ordered
	//everything good, create stack b
	ft_print_stack(stack_a);
}

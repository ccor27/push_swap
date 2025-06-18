/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:44:30 by crosorio          #+#    #+#             */
/*   Updated: 2025/06/16 13:04:14 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_list *stack)
{
	while (stack)
	{
		ft_printf("%d\n",stack->content);
		stack = stack->next;
	}

}

int	main(int argc, char **argv)
{
	char	**numbers;
	t_list	*stack_a;

	if (argc < 2)
		ft_free_and_close(numbers, &stack_a);
	numbers = ft_split(argv[1], ' ');
	if (!numbers)
		ft_free_and_close(numbers, &stack_a);
	if (!ft_fill_up_stack_a(&stack_a, numbers))
		ft_free_and_close(numbers, &stack_a);
	ft_print_stack(stack_a);
}

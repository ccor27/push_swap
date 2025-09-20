/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:45:23 by crosorio          #+#    #+#             */
/*   Updated: 2025/08/01 16:43:15 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Function to validate if number(from arguments) is a valid one.
 * Only allowing numbers and just one sign
 */
int	ft_is_valid_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
 * Function to validate if a number exist in the stack
 */
int	ft_exist_number_in_stack(int number, t_list *stack)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->content == number)
			return (1);
		stack = stack->next;
	}
	return (0);
}

/**
 * Function to fill up the A stack with the arguments.
 * Validating if each number
 */
int	ft_fill_up_stack_a(t_list **stack, char **matrix)
{
	int		i;
	long	long_number;
	t_list	*new_node;

	i = 0;
	while (matrix[i])
	{
		if (!ft_is_valid_number(matrix[i]))
			return (0);
		long_number = ft_atol(matrix[i]);
		if (long_number < INT_MIN || long_number >= INT_MAX)
			return (0);
		if (ft_exist_number_in_stack(long_number, *stack))
			return (0);
		new_node = ft_lstnew(long_number);
		ft_lstadd_back(stack, new_node);
		i++;
	}
	return (1);
}

/**
 * Function to free both matrix and stack then, print and close
 * the program
 */
void	ft_free_and_close(char **matrix, t_list **stack)
{
	int	i;

	i = 0;
	if (matrix && matrix[i])
	{
		while (matrix[i])
		{
			free(matrix[i]);
			i++;
		}
		free(matrix);
	}
	if (stack && *stack)
		ft_lstclear(stack);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

/**
 * Function to take all the arguments
 * and join them into a single string
 */
void	ft_join_arguments(char **arguments, char **joined)
{
	char	*tmp;
	int		i;

	i = 1;
	*joined = NULL;
	while (arguments[i])
	{
		if (!joined)
			*joined = ft_strdup(arguments[i]);
		else
		{
			if (ft_is_string_empty_or_blank(arguments[i]))
			{
				free(*joined);
				joined = NULL;
				break ;
			}
			tmp = ft_strjoin(*joined, " ");
			free(*joined);
			*joined = ft_strjoin(tmp, arguments[i]);
			free(tmp);
		}
		i++;
	}
}

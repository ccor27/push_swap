/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:42:21 by crosorio          #+#    #+#             */
/*   Updated: 2025/07/12 14:10:25 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "printf/ft_printf.h"
# include <stdlib.h>

int		ft_is_valid_number(char *s);
int		ft_exist_number_in_stack(int number, t_list *stack);
int		ft_fill_up_stack_a(t_list **stack, char **matrix);
void	ft_free_and_close(char **matrix, t_list **stack);
void	ft_join_arguments(char **arguments, char **joined);
void	ft_swap_two_element_at_top(t_list **stack, char *movement);
void	ft_swap_elements_same_time(t_list **stack_a, t_list **stack_b);
void	ft_rotate_stack(t_list **stack, char *movemnt);
void	ft_rotate_two_stacks_at_same_time(t_list **stack_a, t_list **stack_b);
void	ft_reverse_rotate_stack(t_list **stack, char *movemnt);
void	ft_put_into_stack(t_list **stack, t_list *node, char *movemnt);
int		ft_is_string_empty_or_blank(char *s);
void	ft_order_three_elements(t_list **stack);
void	ft_assing_positions(t_list **stack);
void	ft_find_targets(t_list **a, t_list **b);
#endif

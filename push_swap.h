/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:42:21 by crosorio          #+#    #+#             */
/*   Updated: 2025/07/19 12:43:58 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "printf/ft_printf.h"
# include <stdlib.h>

// args_validation_utils.c
int		ft_is_string_empty_or_blank(char *s);
void	ft_free_stacks_and_matrix(t_list **a, t_list **b, char **matrix);
// args_validation.c
int		ft_is_valid_number(char *s);
int		ft_exist_number_in_stack(int number, t_list *stack);
int		ft_fill_up_stack_a(t_list **stack, char **matrix);
void	ft_free_and_close(char **matrix, t_list **stack);
void	ft_join_arguments(char **arguments, char **joined);
// main.c
void	ft_print_stack(t_list *stack);
int		ft_is_stack_ordered(t_list *stack);
// move_executor.c
void	ft_execute_movements(t_list **a, t_list **b, t_list *node);
void	ft_do_different_moves(t_list **a, t_list **b, t_list *node);
void	ft_do_rrr(t_list **a, t_list **b, t_list *node);
void	ft_do_rr(t_list **a, t_list **b, t_list *node);
// put_moves.c
void	ft_put_into_stack(t_list **stack, t_list *node, char *movemnt);
// rotate_moves.c
void	ft_rotate_stack(t_list **stack, char *movemnt);
void	ft_rotate_two_stacks_at_same_time(t_list **stack_a, t_list **stack_b);
void	ft_reverse_rotate_stack(t_list **stack, char *movemnt);
void	ft_reverse_rotate_two_stacks_at_same_time(t_list **stack_a,
			t_list **stack_b);
// sort_process_utils.c
int		ft_max(int a, int b);
int		ft_abs(int num);
void	ft_order_two(t_list **stack);
t_list	*ft_pop(t_list **stack);
void	ft_order_three_elements(t_list **stack);
// sort_process.c
void	ft_sort(t_list **a, t_list **b);
void	ft_process_from_a_to_b(t_list **a, t_list **b);
void	ft_process_from_b_to_a(t_list **b, t_list **a);
void	ft_put_min_on_top(t_list **a);
void	ft_find_cost(t_list **node, int first_stack_size, int second_stack_size, char from);
// sort_utils.c
t_list	*ft_find_lowest_movements_cost(t_list *stack);
int		ft_find_min_index(t_list *node);
int ft_find_max_index(t_list  *node);
void	ft_assing_positions(t_list **stack);
void	ft_find_cost_helper(char from, t_list *head, int first_stack_size, int second_stack_size);
// swap_moves.c
void	ft_swap_two_element_at_top(t_list **stack, char *movement);
void	ft_swap_elements_same_time(t_list **stack_a, t_list **stack_b);
// target_in_a_finder.c
void	ft_target_process(t_list **list, t_list *node, char from);
int		ft_get_target_pos(t_list *node_to_compare, t_list *list_to_compare,
			char from, int target_pos);
int		ft_find_pos(t_list *stack);
#endif

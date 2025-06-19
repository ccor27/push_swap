/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:42:21 by crosorio          #+#    #+#             */
/*   Updated: 2025/06/19 14:20:16 by crosorio         ###   ########.fr       */
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
#endif

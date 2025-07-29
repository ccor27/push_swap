/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:19:13 by crosorio          #+#    #+#             */
/*   Updated: 2025/07/04 13:18:46 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Function to put in the top from one stack to another
 */
void ft_put_into_stack(t_list **stack, t_list *node, char *movemnt)
{
		if (!node)
			return ;
		ft_lstadd_front(stack,node);
		if(movemnt)
			ft_printf("%s",movemnt);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio < crosorio@student.42madrid.com>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-15 20:00:08 by crosorio          #+#    #+#             */
/*   Updated: 2025-07-15 20:00:08 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_sort(t_list **a, t_list **b)
{
	//validate stack a has more than 3 elements
	if(ft_lstsize(*a) < 4)
	{
		if(ft_lstsize(*a) == 3)
			ft_order_three_elements(a);
		else
			//order 2
	}
	else
	{
		//pass the 2 first elements from A to B
		//make a loop until the size of A be more than 3
		while(ft_lstsize(*a) > 3)
		{
			//set the pos to each element of both A and B
			ft_assing_positions(a);
			ft_assing_positions(b);
			//select the target of A's elements
			ft_find_targets(a,b);
			//find the cost
			//select the lowest cost
			//make the move
		}
		//order the 3 elements in A
		//pass all from B to A
	}
}


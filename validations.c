/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:58:45 by crosorio          #+#    #+#             */
/*   Updated: 2025/06/16 14:01:02 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//int ft_exist
int ft_are_valid_arguments(char **arguments)
{
	//each item is number
	while(*arguments)
	{
		if(!ft_isdigit(*arguments))
			return(0);
		arguments++;
	}
	//not allow duplicated numbers
	//not multiple signes
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio < crosorio@student.42madrid.com>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-17 17:45:23 by crosorio          #+#    #+#             */
/*   Updated: 2025-06-17 17:45:23 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Function to validate if number(from arguments) is a valid one.
 * Only allowing numbers and just one sign
 */
int is_valid_number(char *s)
{
	int i;
	i = 0;
	if(s[i] == '-' || s[i] == '+')
		i++;
	if(!s[i])//sign without number
		return(0);
	while(s[i])
	{
		if(!ft_isdigit(s[i]))
			return(0);
		i++;
	}
	return(1);
}

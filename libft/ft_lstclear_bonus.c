/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:43:53 by crosorio          #+#    #+#             */
/*   Updated: 2025/04/15 11:47:16 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list *aux;

	if (!lst)
		return;
	while (*lst)
	{
		aux = (*lst)->next;
		free(*lst);
		*lst = aux;
	}
}

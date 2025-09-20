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

t_list	*ft_lstmap(t_list *lst, int (*f)(int))
{
	t_list	*new_list;
	t_list	*new_node;
	int		new_content;

	if (lst && f)
	{
		new_list = NULL;
		while (lst)
		{
			new_content = f(lst->content);
			new_node = ft_lstnew(new_content);
			if (!new_node)
			{
				ft_lstclear(&new_list);
				return (NULL);
			}
			ft_lstadd_back(&new_list, new_node);
			lst = lst->next;
		}
		return (new_list);
	}
	return (NULL);
}

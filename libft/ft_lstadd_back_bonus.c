/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:50:14 by seungjpa          #+#    #+#             */
/*   Updated: 2023/03/18 22:11:49 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (temp == 0)
	{
		*lst = new;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return ;
}

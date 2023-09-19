/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:10:41 by seungjpa          #+#    #+#             */
/*   Updated: 2023/03/18 21:27:47 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_element;

	new_element = malloc(sizeof(t_list));
	if (new_element == 0)
		return (0);
	new_element->content = content;
	new_element->next = 0;
	return (new_element);
}

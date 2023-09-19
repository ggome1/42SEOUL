/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:22:27 by seungjpa          #+#    #+#             */
/*   Updated: 2023/03/21 17:54:39 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index])
		index++;
	c = c % 256;
	if (c == 0)
		return ((char *)&s[index]);
	while (index--)
	{
		if (s[index] == c)
			return ((char *)&s[index]);
	}
	return (0);
}

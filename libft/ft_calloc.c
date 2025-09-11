/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 09:40:46 by svaladar          #+#    #+#             */
/*   Updated: 2025/08/06 12:31:24 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*temp;
	size_t			i;

	if (count == 0 || size == 0)
	{
		temp = malloc(0);
		if (!temp)
			return (NULL);
		return (temp);
	}
	if (size != 0 && size > ((size_t)-1) / count)
		return (NULL);
	temp = malloc(count * size);
	if (!temp)
		return (NULL);
	i = 0;
	while (i < count * size)
		temp[i++] = 0;
	return (temp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:03:02 by svaladar          #+#    #+#             */
/*   Updated: 2026/11/10 18:58:58 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c, t_format fmt)
{
	int		count;
	char	ch;

	ch = (char)c;
	count = 0;
	if (!(fmt.flags & F_MINUS))
		count += ft_pad(' ', fmt.width - 1);
	write(1, &ch, 1);
	count++;
	if (fmt.flags & F_MINUS)
		count += ft_pad(' ', fmt.width - 1);
	return (count);
}

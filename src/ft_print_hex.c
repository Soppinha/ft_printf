/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:02:57 by svaladar          #+#    #+#             */
/*   Updated: 2025/10/01 16:02:58 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, int uppercase, t_format fmt)
{
	char	buf[UTOA_BUF];
	char	*base;
	char	*prefix;

	base = BASE_HEX_LOW;
	prefix = "0x";
	if (uppercase)
	{
		base = BASE_HEX_UP;
		prefix = "0X";
	}
	if (!(fmt.flags & F_HASH) || n == 0)
		prefix = "";
	return (ft_print_number(ft_utoa_base(n, base, buf), prefix, fmt));
}

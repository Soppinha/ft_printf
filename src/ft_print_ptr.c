/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:03:15 by svaladar          #+#    #+#             */
/*   Updated: 2025/10/01 16:03:16 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long ptr, t_format fmt)
{
	char	buf[UTOA_BUF];

	if (ptr == 0)
	{
		fmt.precision = -1;
		return (ft_print_str("(nil)", fmt));
	}
	return (ft_print_number(ft_utoa_base(ptr, BASE_HEX_LOW, buf), "0x", fmt));
}
